//
// Created by tanmaypoke on 25/6/19.
//

#ifndef GRAPHCOLOURING_MINSPANTREE_H
#define GRAPHCOLOURING_MINSPANTREE_H


#include "graph.h"
#include <vector>
#include <array>
//Contains all the operations needed for our algorithm to find the minimum spanning tree.
class MinSpanTree {
    graph G;
    int mstcounter;
    vector<edge> mstEdges;
    vector<array<int, 6>> edgemapping;
public:
    MinSpanTree();
    MinSpanTree(graph);
    void selectMSTEdges();
    void addEdgesToMST(vector<edge>);
    void renameVertices();
    void updateOriginalEdgeList();
    void displayEdges(vector<edge>);
    void recoverOrigEdges(int round);
    vector<edge> findMST();
    int getMstcounter() const;
    const vector<edge> &getMstEdges() const;
};


#endif //GRAPHCOLOURING_MINSPANTREE_H
