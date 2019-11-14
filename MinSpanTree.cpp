//
// Created by tanmaypoke on 25/6/19.
//

#include "MinSpanTree.h"
#include <iostream>
#include <array>
#include <algorithm>
#include <chrono>
using namespace std;

MinSpanTree::MinSpanTree() {

}
MinSpanTree::MinSpanTree(graph graph1) {
    this->G = graph1;
    this->mstcounter = 0;
}
void MinSpanTree::selectMSTEdges() {
    vector<edge> cheapestedges;
//    cout << "In Cheapest Edges list before sorting:"<<endl;
//    G.displayGraph();
//    cout << "Sorting before" << endl;
    long sum=0, sumw=0;
    edge g1;
//    g1 = G.edges[5];
//    cout << "g1:"<<g1.getSource()<<","<<g1.getDestination()<<","<<g1.getWeight();
//    std::cout << "sums = " << sum << ", " << sumw << std::endl;
    std::sort(G.edges.begin(), G.edges.end(), graph::comparator3);
//    cout << "In Cheapest Edges list after sorting:"<<endl;
//    G.displayGraph();
    int tempSource = -1;
    for (int i = 0,j = 0;i < G.numvertices;i++) {
        if(tempSource != G.edges[j].getSource())
        {
            tempSource = G.edges[j].getSource();
            if(G.edges[j].getSource()>G.edges[j].getDestination()){
                cheapestedges.push_back(edge(G.edges[j].getDestination(),G.edges[j].getSource(),G.edges[j].getWeight(),G.edges[j].getDestOriginal(),G.edges[j].getSrcOriginal()));
            } else{
                cheapestedges.push_back(edge(G.edges[j].getSource(),G.edges[j].getDestination(),G.edges[j].getWeight(),G.edges[j].getSrcOriginal(),G.edges[j].getDestOriginal()));
            }
        }
        while(tempSource == G.edges[j].getSource() and j != G.edges.size())
        {
            j++;
            if(j+1 == G.edges.size()) break;
        }
    }
//    if(G.edges.size()<G.edges.size()+1)
//    {
//        cout << "Cheapest Edges List:" << endl;
//        displayEdges(cheapestedges);
//    }
//    cout << "Cheapest Edges List:" << endl;
//    displayEdges(cheapestedges);
    addEdgesToMST(cheapestedges);
}
void MinSpanTree::displayEdges(vector<edge> edgeList) {
    cout << "Src Dest Wt OSrc ODest" << endl;
    for (int i = 0; i < edgeList.size(); ++i) {
        cout << edgeList[i].getSource() << "\t";
        cout << edgeList[i].getDestination() << "\t";
        cout << edgeList[i].getWeight() << "\t";
        cout << edgeList[i].getSrcOriginal() << "\t";
        cout << edgeList[i].getDestOriginal() << endl;
    }
}
void MinSpanTree::addEdgesToMST(vector<edge> cheapestedges) {
    sort(cheapestedges.begin(),cheapestedges.end(),G.comparator2);
    int newEdgeCount = 0;
//    displayEdges(cheapestedges);
    for(int i = 0;i < cheapestedges.size() - 1;i++){
        if(cheapestedges[i].getSource() == cheapestedges[i+1].getSource() && cheapestedges[i].getDestination() == cheapestedges[i+1].getDestination()){
            newEdgeCount++;
            mstEdges.push_back(edge(cheapestedges[i].getSource(),cheapestedges[i].getDestination(),cheapestedges[i].getWeight(),cheapestedges[i].getSrcOriginal(),cheapestedges[i].getDestOriginal()));
        }
    }
//    cout << "Size of MST list:" << mstEdges.size()<<endl;
//    if(G.edges.size()<G.edges.size()+1)
//    {
//        cout << "MST Edges List:" << endl;
//        displayEdges(mstEdges);
//    }
//    cout << "MST Edges List:" <<endl;
//    displayEdges(mstEdges);
    G.numvertices-=newEdgeCount;
}
void MinSpanTree::renameVertices() {
//    cout << "Before renaming vertices:"<<endl;
//    displayEdges(G.edges);
    for (int i = 0; i < G.edges.size(); ++i) {
        for (int j = mstcounter; j < mstEdges.size(); ++j) {
            if(G.edges[i].getSource() == mstEdges[j].getDestination())
            {
//                array<int, 6> temp = {mstEdges[j].getSource(),G.edges[i].getDestination(),G.edges[i].getWeight(),G.edges[i].getSource(),G.edges[i].getDestination(),G.edges[i].getWeight()};
//                edgemapping.push_back(temp);
                G.edges[i].setSource(mstEdges[j].getSource());
//                break;
            }
            if(G.edges[i].getDestination() == mstEdges[j].getDestination())
            {
//                array<int, 6> temp = {G.edges[i].getSource(),mstEdges[j].getSource(),G.edges[i].getWeight(),G.edges[i].getSource(),G.edges[i].getDestination(),G.edges[i].getWeight()};
//                edgemapping.push_back(temp);
                G.edges[i].setDestination(mstEdges[j].getSource());
//                break;
            }
        }
    }
//    cout << "After renaming vertices:"<<endl;
//    displayEdges(G.edges);
//    cout << endl <<"newEdge->oldEdge"<<endl;
//    for(int i = 0; i < edgemapping.size(); i++){
//        cout << "(" << edgemapping[i][0] << "," << edgemapping[i][1] << "," << edgemapping[i][2] << ")->(" << edgemapping[i][3] << "," << edgemapping[i][4]<< "," << edgemapping[i][5] << ")" << endl;
//    }
}
void MinSpanTree::updateOriginalEdgeList() {
    sort(G.edges.begin(),G.edges.end(),G.comparator2);
//    displayEdges(G.edges);
    vector<edge> newEdgeList;
    G.edges.push_back(edge(0,0,0,0,0));
    for (int i = 0; i < G.edges.size()-1; ++i) {
        if(G.edges[i].getSource() == G.edges[i+1].getSource() && G.edges[i].getDestination() == G.edges[i+1].getDestination())
        {
            if(G.edges[i].getWeight() < G.edges[i+1].getWeight())
            {
                newEdgeList.push_back(edge(G.edges[i].getSource(),G.edges[i].getDestination(),G.edges[i].getWeight(),G.edges[i].getSrcOriginal(),G.edges[i].getDestOriginal()));
            }
            else if(G.edges[i].getWeight() > G.edges[i+1].getWeight()){
                newEdgeList.push_back(edge(G.edges[i+1].getSource(),G.edges[i+1].getDestination(),G.edges[i+1].getWeight(),G.edges[i+1].getSrcOriginal(),G.edges[i+1].getDestOriginal()));
            }
            i++;
        }
        else{
            newEdgeList.push_back(edge(G.edges[i].getSource(),G.edges[i].getDestination(),G.edges[i].getWeight(),G.edges[i].getSrcOriginal(),G.edges[i].getDestOriginal()));
        }
    }
    graph newGraph(G.numvertices,newEdgeList.size(),newEdgeList);
    G = newGraph;
    mstcounter = mstEdges.size();
//    cout << "New graph:" << endl;
//    newGraph.displayGraph();
}
void MinSpanTree::recoverOrigEdges(int round) {
    for (int k = 0; k < round; ++k) {
        for (int i = mstcounter; i < mstEdges.size(); ++i) {
            for (int j = 0; j < edgemapping.size(); ++j) {
                if (edgemapping[j][0] == mstEdges[i].getSource() && edgemapping[j][1] == mstEdges[i].getDestination() &&
                    edgemapping[j][2] == mstEdges[i].getWeight()) {
                    mstEdges[i].setDestination(edgemapping[j][4]);
                    mstEdges[i].setSource(edgemapping[j][3]);
                }
            }
        }
    }
    mstcounter = mstEdges.size();
}
vector<edge> MinSpanTree::findMST() {
    int round = 0;
//    while (this->mstEdges.size())
    chrono::duration<double> time_selectingMSTEdges;
    chrono::duration<double> time_renameVerts;
    chrono::duration<double> time_updateEdgelist;
    while (G.edges.size() != 0)
    {
//        cout << "Size of vertex list now:" << G.numvertices<<endl;
//        cout << "Size of edge list now:" << G.edges.size()<<endl;
//        if(G.edges.size()<G.edges.size()+1)
//        {
//            displayEdges(G.edges);
//        }
        chrono::time_point<std::chrono::system_clock> start1, end1, start2, end2, start3, end3;
        start1 = chrono::system_clock::now();
        selectMSTEdges();
        end1 = chrono::system_clock::now();
        start2 = chrono::system_clock::now();
        renameVertices();
        end2 = chrono::system_clock::now();
        start3 = chrono::system_clock::now();
        updateOriginalEdgeList();
        end3 = chrono::system_clock::now();
        //recoverOrigEdges(round);
        time_selectingMSTEdges += (end1 - start1);
        time_renameVerts += (end2 - start2);
        time_updateEdgelist += (end3 - start3);
        round++;
    }
//    selectMSTEdges();
//    renameVertices();
//    updateOriginalEdgeList();
//    selectMSTEdges();
//    renameVertices();
//    updateOriginalEdgeList();
    cout << "Total Time selecting MST Edges: " << time_selectingMSTEdges.count() << "s" << endl;
    cout << "Total Time renaming vertices: " << time_renameVerts.count() << "s" << endl;
    cout << "Total Time Updating Edge list: " << time_updateEdgelist.count() << "s" << endl;

    return mstEdges;
}

int MinSpanTree::getMstcounter() const {
    return mstcounter;
}

const vector<edge> &MinSpanTree::getMstEdges() const {
    return mstEdges;
}
