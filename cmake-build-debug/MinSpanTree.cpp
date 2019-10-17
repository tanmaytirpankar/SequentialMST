//
// Created by tanmaypoke on 25/6/19.
//

#include "MinSpanTree.h"
#include <iostream>
#include <array>
using namespace std;

MinSpanTree::MinSpanTree() {

}
MinSpanTree::MinSpanTree(graph graph1) {
    this->G = graph1;
    this->mstcounter = 0;
}
void MinSpanTree::selectMSTEdges() {
    vector<edge> cheapestedges;
//    cout << "In Cheapest Edges list before sorting:\n";
//    G.displayGraph();
    sort(G.edges.begin(),G.edges.end(),G.comparator3);
//    cout << "In Cheapest Edges list after sorting:\n";
//    G.displayGraph();
    int tempSource = -1;
    for (int i = 0,j = 0;i < G.numvertices;i++) {
        if(tempSource != G.edges[j].getSource())
        {
            tempSource = G.edges[j].getSource();
            if(G.edges[j].getSource()>G.edges[j].getDestination()){
                cheapestedges.push_back(edge(G.edges[j].getDestination(),G.edges[j].getSource(),G.edges[j].getWeight()));
            } else{
                cheapestedges.push_back(edge(G.edges[j].getSource(),G.edges[j].getDestination(),G.edges[j].getWeight()));
            }
        }
        while(tempSource == G.edges[j].getSource() and j != G.edges.size()) j++;
    }
    cout << "Cheapest Edges List:\n";
    displayEdges(cheapestedges);
    addEdgesToMST(cheapestedges);
}
void MinSpanTree::displayEdges(vector<edge> edgeList) {
    cout << "Source Destination Weight\n";
    for (int i = 0; i < edgeList.size(); ++i) {
        cout << edgeList[i].getSource() << "\t";
        cout << edgeList[i].getDestination() << "\t";
        cout << edgeList[i].getWeight() << "\n";
    }
}
void MinSpanTree::addEdgesToMST(vector<edge> cheapestedges) {
    sort(cheapestedges.begin(),cheapestedges.end(),G.comparator2);
    int newEdgeCount = 0;
//    displayEdges(cheapestedges);
    for(int i = 0;i < cheapestedges.size() - 1;i++){
        if(cheapestedges[i].getSource() == cheapestedges[i+1].getSource() && cheapestedges[i].getDestination() == cheapestedges[i+1].getDestination()){
            newEdgeCount++;
            mstEdges.push_back(edge(cheapestedges[i].getSource(),cheapestedges[i].getDestination(),cheapestedges[i].getWeight()));
        }
    }
    displayEdges(mstEdges);
    G.numvertices-=newEdgeCount;
}
void MinSpanTree::renameVertices() {
//    displayEdges(G.edges);
    for (int i = 0; i < G.edges.size(); ++i) {
        for (int j = mstcounter; j < mstEdges.size(); ++j) {
            if(G.edges[i].getSource() == mstEdges[j].getDestination())
            {
                array<int, 6> temp = {mstEdges[j].getSource(),G.edges[i].getDestination(),G.edges[i].getWeight(),G.edges[i].getSource(),G.edges[i].getDestination(),G.edges[i].getWeight()};
                edgemapping.push_back(temp);
                G.edges[i].setSource(mstEdges[j].getSource());
            }
            if(G.edges[i].getDestination() == mstEdges[j].getDestination())
            {
                array<int, 6> temp = {G.edges[i].getSource(),mstEdges[j].getSource(),G.edges[i].getWeight(),G.edges[i].getSource(),G.edges[i].getDestination(),G.edges[i].getWeight()};
                edgemapping.push_back(temp);
                G.edges[i].setDestination(mstEdges[j].getSource());
            }
        }
    }
//    displayEdges(G.edges);
    cout << "\nnewEdge->oldEdge\n";
    for(int i = 0; i < edgemapping.size(); i++){
        cout << "(" << edgemapping[i][0] << "," << edgemapping[i][1] << "," << edgemapping[i][2] << ")->(" << edgemapping[i][3] << "," << edgemapping[i][4]<< "," << edgemapping[i][5] << ")\n";
    }
}
void MinSpanTree::updateOriginalEdgeList() {
    sort(G.edges.begin(),G.edges.end(),G.comparator2);
//    displayEdges(G.edges);
    vector<edge> newEdgeList;
    G.edges.push_back(edge(0,0,0));
    for (int i = 0; i < G.edges.size()-1; ++i) {
        if(G.edges[i].getSource() == G.edges[i+1].getSource() && G.edges[i].getDestination() == G.edges[i+1].getDestination())
        {
            if(G.edges[i].getWeight() < G.edges[i+1].getWeight())
            {
                newEdgeList.push_back(edge(G.edges[i].getSource(),G.edges[i].getDestination(),G.edges[i].getWeight()));
            }
            else if(G.edges[i].getWeight() > G.edges[i+1].getWeight()){
                newEdgeList.push_back(edge(G.edges[i+1].getSource(),G.edges[i+1].getDestination(),G.edges[i+1].getWeight()));
            }
            i++;
        }
        else{
            newEdgeList.push_back(edge(G.edges[i].getSource(),G.edges[i].getDestination(),G.edges[i].getWeight()));
        }
    }
    graph newGraph(G.numvertices,newEdgeList.size(),newEdgeList);
    G = newGraph;
    cout << "New graph:\n";
    newGraph.displayGraph();
}
void MinSpanTree::recoverOrigEdges() {
    for (int i = mstcounter; i <  mstEdges.size();++i) {
        for (int j = 0; j < edgemapping.size(); ++j) {
            if(edgemapping[j][0] == mstEdges[i].getSource() && edgemapping[j][1] == mstEdges[i].getDestination() && edgemapping[j][2] == mstEdges[i].getWeight()){
                mstEdges[i].setDestination(edgemapping[i][1]);
            }
        }
    }
    mstcounter = mstEdges.size();
}
vector<edge> MinSpanTree::findMST() {
    while (G.edges.size() != 0) {
        selectMSTEdges();
        renameVertices();
        updateOriginalEdgeList();
        recoverOrigEdges();
    }
//    selectMSTEdges();
//    renameVertices();
//    updateOriginalEdgeList();
//    selectMSTEdges();
//    renameVertices();
//    updateOriginalEdgeList();
    return mstEdges;
}