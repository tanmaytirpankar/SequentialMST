//
// Created by tanmaypoke on 25/6/19.
//

#include "MinSpanTree.h"
#include <iostream>
#include <array>
#include <algorithm>
#include <chrono>

#define debuground -1
using namespace std;

MinSpanTree::MinSpanTree() {

}
MinSpanTree::MinSpanTree(graph graph1) {
    this->G = graph1;
    this->mstcounter = 0;
}
void MinSpanTree::selectMSTEdges() {
    vector<edge> cheapestedges;
//    if(round == debuground) {
//        cout << "In Cheapest Edges list before sorting:"<<endl;
//        G.displayGraph();
//    }
//    cout << "In Cheapest Edges list before first sorting:"<<endl;
//    G.displayGraph();
//    long sum=0, sumw=0;
//    edge g1;
//    g1 = G.edges[5];
//    cout << "g1:"<<g1.getSource()<<","<<g1.getDestination()<<","<<g1.getWeight();
//    std::cout << "sums = " << sum << ", " << sumw << std::endl;

    std::sort(G.edges.begin(), G.edges.end(), graph::comparator3);

//    if(round == debuground) {
//        cout << "In Cheapest Edges list after sorting:"<<endl;
//        G.displayGraph();
//    }
//    cout << "In Cheapest Edges list after first sorting:"<<endl;
//    G.displayGraph();
    graph G1 = G;
    std::sort(G1.edges.begin(), G1.edges.end(), graph::comparator6);

//    if(round == debuground) {
//        cout << "In Cheapest Edges list after sorting:"<<endl;
//        G1.displayGraph();
//    }
//    cout << "In Cheapest Edges list after second sorting:"<<endl;
//    G1.displayGraph();

    int tempSourcei = G.edges[0].getSource();
    int tempSourcej = G1.edges[0].getDestination();
    int i = 0;
    int j = 0;
    while(i < G.edges.size() && j < G1.edges.size())
    {
        if(G.edges[i].getSource() < G1.edges[j].getDestination())
        {
            cheapestedges.push_back(edge(G.edges[i].getSource(),G.edges[i].getDestination(),G.edges[i].getWeight(),G.edges[i].getSrcOriginal(),G.edges[i].getDestOriginal()));
            while(tempSourcei == G.edges[i].getSource())
            {
                i++;
                if(i == G.edges.size()) break;
            }
            if(i != G.edges.size()) {
                tempSourcei = G.edges[i].getSource();
            }
        }
        else if(G.edges[i].getSource() > G1.edges[j].getDestination())
        {
            cheapestedges.push_back(edge(G1.edges[j].getSource(),G1.edges[j].getDestination(),G1.edges[j].getWeight(),G1.edges[j].getSrcOriginal(),G1.edges[j].getDestOriginal()));
            while(tempSourcej == G1.edges[j].getDestination())
            {
                j++;
                if(j == G1.edges.size()) break;
            }
            if(j != G1.edges.size()) {
                tempSourcej = G1.edges[j].getDestination();
            }
        }
        else
        {
            if(G.edges[i].getWeight() < G1.edges[j].getWeight())
            {
                cheapestedges.push_back(edge(G.edges[i].getSource(),G.edges[i].getDestination(),G.edges[i].getWeight(),G.edges[i].getSrcOriginal(),G.edges[i].getDestOriginal()));
            }
            else
            {
                cheapestedges.push_back(edge(G1.edges[j].getSource(),G1.edges[j].getDestination(),G1.edges[j].getWeight(),G1.edges[j].getSrcOriginal(),G1.edges[j].getDestOriginal()));
            }
            while(tempSourcei == G.edges[i].getSource())
            {
                i++;
                if(i == G.edges.size()) break;
            }
            if(i != G.edges.size()) {
                tempSourcei = G.edges[i].getSource();
            }
            while(tempSourcej == G1.edges[j].getDestination())
            {
                j++;
                if(j == G1.edges.size()) break;
            }
            if(j != G1.edges.size()) {
                tempSourcej = G1.edges[j].getDestination();
            }
        }
    }
    while(i < G.edges.size()) {
        cheapestedges.push_back(edge(G.edges[i].getSource(),G.edges[i].getDestination(),G.edges[i].getWeight(),G.edges[i].getSrcOriginal(),G.edges[i].getDestOriginal()));
        while(tempSourcei == G.edges[i].getSource())
        {
            i++;
            if(i == G.edges.size()) break;
        }
        if(i != G.edges.size()) {
            tempSourcei = G.edges[i].getSource();
        }
    }
    while(j < G1.edges.size()) {
        cheapestedges.push_back(edge(G1.edges[j].getSource(),G1.edges[j].getDestination(),G1.edges[j].getWeight(),G1.edges[j].getSrcOriginal(),G1.edges[j].getDestOriginal()));
        while(tempSourcej == G1.edges[j].getDestination())
        {
            j++;
            if(j == G1.edges.size()) break;
        }
        if(j != G1.edges.size()) {
            tempSourcej = G1.edges[j].getDestination();
        }
    }

//    if(round == debuground) {
//        cout << "Cheapest Edges List: " << cheapestedges.size() << " vertices" << endl;
//        displayEdges(cheapestedges);
//    }
//    cout << "Unsorted Cheapest Edges List: " << cheapestedges.size() << " vertices" << endl;
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
    cout << "Sorted Cheapest Edges List: " << cheapestedges.size() << " vertices" << endl;
    displayEdges(cheapestedges);
    int newEdgeCount = 0;
    for(int i = 0;i < cheapestedges.size() - 1;i++){
        if(cheapestedges[i].getSource() == cheapestedges[i+1].getSource() && cheapestedges[i].getDestination() == cheapestedges[i+1].getDestination()){
            newEdgeCount++;
            mstEdges.push_back(edge(cheapestedges[i].getSource(),cheapestedges[i].getDestination(),cheapestedges[i].getWeight(),cheapestedges[i].getSrcOriginal(),cheapestedges[i].getDestOriginal()));
        }
    }
    if(round == debuground) {
        cout << "Size of MST list:" << mstEdges.size()<<endl;
        cout << "MST Edges List:" <<endl;
        displayEdges(mstEdges);
    }
    cout << "Size of MST list:" << mstEdges.size()<<endl;
    cout << "MST Edges List:" <<endl;
    displayEdges(mstEdges);
    G.numvertices-=newEdgeCount;
    exit(0);
}
void MinSpanTree::renameVertices() {
    std::sort(G.edges.begin(), G.edges.end(), graph::comparator1);
    std::sort(mstEdges.begin()+mstcounter,mstEdges.end(),graph::comparator4);
    if(round == debuground) {
        cout << "Before renaming vertices:"<<endl;
        displayEdges(G.edges);
    }
//    cout << "Before renaming vertices:"<<endl;
//    displayEdges(G.edges);
    for (int i = 0, j = mstcounter; i < G.edges.size(); ++i) {
        if(G.edges[i].getSource() > mstEdges[j].getDestination()) {
            j++;
            if (j >= mstEdges.size()) break;
        }
        if(G.edges[i].getSource() == mstEdges[j].getDestination())
        {
//            array<int, 6> temp = {mstEdges[j].getSource(), G.edges[i].getDestination(), G.edges[i].getWeight(),
//                                  G.edges[i].getSource(), G.edges[i].getDestination(), G.edges[i].getWeight()};
//            edgemapping.push_back(temp);
            G.edges[i].setSource(mstEdges[j].getSource());
//            break;
        }
    }
    std::sort(G.edges.begin(), G.edges.end(), graph::comparator4);
    for (int i = 0, j = mstcounter; i < G.edges.size(); ++i) {
        if(G.edges[i].getDestination() > mstEdges[j].getDestination()) {
            j++;
            if (j >= mstEdges.size()) break;
        }

        if(G.edges[i].getDestination() == mstEdges[j].getDestination()) {
//            array<int, 6> temp = {G.edges[i].getSource(), mstEdges[j].getSource(), G.edges[i].getWeight(),
//                                  G.edges[i].getSource(), G.edges[i].getDestination(), G.edges[i].getWeight()};
//            edgemapping.push_back(temp);
            G.edges[i].setDestination(mstEdges[j].getSource());
//            break;
        }
    }
    if(round == debuground) {
        cout << "After renaming vertices:"<<endl;
        displayEdges(G.edges);
    }
//    cout << "After renaming vertices:"<<endl;
//    displayEdges(G.edges);
//    cout << endl <<"newEdge->oldEdge"<<endl;
//    for(int i = 0; i < edgemapping.size(); i++){
//        cout << "(" << edgemapping[i][0] << "," << edgemapping[i][1] << "," << edgemapping[i][2] << ")->(" << edgemapping[i][3] << "," << edgemapping[i][4]<< "," << edgemapping[i][5] << ")" << endl;
//    }
}
void MinSpanTree::updateOriginalEdgeList() {
    sort(G.edges.begin(), G.edges.end(), G.comparator5);
    if(round == debuground) {
        cout << "Before Updating Edge List:" << endl;
        displayEdges(G.edges);
    }
//    cout << "Before Updating Edge List:" << endl;
//    displayEdges(G.edges);
    vector<edge> newEdgeList;
    edge tempedge(-1,-1,-1,-1,-1);
    int i = 0;
    while(i < G.edges.size()){
        if (tempedge.getSource() != G.edges[i].getSource() || tempedge.getDestination() != G.edges[i].getDestination())
        {
            tempedge.setSource(G.edges[i].getSource());
            tempedge.setDestination(G.edges[i].getDestination());
            if (G.edges[i].getSource() != G.edges[i].getDestination()) {
                newEdgeList.push_back(edge(G.edges[i].getSource(), G.edges[i].getDestination(), G.edges[i].getWeight(),
                                           G.edges[i].getSrcOriginal(), G.edges[i].getDestOriginal()));
            }
        }
        while(tempedge.getSource() == G.edges[i].getSource() && tempedge.getDestination() == G.edges[i].getDestination())
        {
            i++;
            if(i == G.edges.size()) break;
        }
    }
//    G.edges.push_back(edge(-1, -1, -1, -1, -1));
//    for (int i = 0; i < G.edges.size() - 1; ++i) {
//        if (G.edges[i].getSource() == G.edges[i + 1].getSource() &&
//            G.edges[i].getDestination() == G.edges[i + 1].getDestination()) {
//            if (G.edges[i].getWeight() < G.edges[i + 1].getWeight()) {
//                newEdgeList.push_back(edge(G.edges[i].getSource(), G.edges[i].getDestination(), G.edges[i].getWeight(),
//                                           G.edges[i].getSrcOriginal(), G.edges[i].getDestOriginal()));
//            } else if (G.edges[i].getWeight() > G.edges[i + 1].getWeight()) {
//                newEdgeList.push_back(
//                        edge(G.edges[i + 1].getSource(), G.edges[i + 1].getDestination(), G.edges[i + 1].getWeight(),
//                             G.edges[i + 1].getSrcOriginal(), G.edges[i + 1].getDestOriginal()));
//            }
//            i++;
//        } else {
//            if (G.edges[i].getSource() != G.edges[i].getDestination()) {
//                newEdgeList.push_back(edge(G.edges[i].getSource(), G.edges[i].getDestination(), G.edges[i].getWeight(),
//                                           G.edges[i].getSrcOriginal(), G.edges[i].getDestOriginal()));
//            }
//        }
//    }
    graph newGraph(G.numvertices, newEdgeList.size(), newEdgeList);
    G = newGraph;
    mstcounter = mstEdges.size();
    if(round == debuground) {
        cout << "After Updating Edge List:" << endl;
        newGraph.displayGraph();
    }
//    cout << "After Updating Edge List:" << endl;
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
    this->round = 0;
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
