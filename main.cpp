#include <iostream>
#include <string>
#include "cmake-build-debug/graph.h"
#include "cmake-build-debug/MinSpanTree.h"

using namespace std;
int main() {
    //CSV file to be taken which contains edges in the form <source,destination,weight> and first line is number of vertices,number of edges..
    string file = "CMakeFiles/temp";
    graph G = graph();
    //G.createUndGrpfrmfile(file);
    G.createUndGrpFrmDGrp(file);
    MinSpanTree mst = MinSpanTree(G);
//    mst.selectMSTEdges();
//    mst.renameVertices();
//    mst.updateOriginalEdgeList();
//    mst.selectMSTEdges();
    vector<edge> finalMST = mst.findMST();
    mst.displayEdges(finalMST);
    return 0;
}

//Algorithm: MinimumSpanningTree()
//Input: A list of edges say E(u,v,w).
//Output: MST edge List say MSTEdgeList.
//1) Sort E by u and then by w.
//2) For each distinct u, we pick the cheapest weighted edge. If (u>v) then flip u,v to v,u and store in cheapestEdgesList.
//3) Sort the cheapestEdgesList by u and then v. Traverse the cheapestEdgesList and check for consecutive duplicate edges. If found, add it to MSTEdgeList.
//4) Rename all vertices in E for every new MST edge added by finding matching MSTEdge(v) and replacing with MSTEdge(u).
//5) Sort E by u and then v, delete consecutive duplicate edges with same wieght and if consecutive duplicates with different weight found, delete the one with greater weight.
//6) Repeat from step 1.

//Parallel version for shared address space:
//Input: A list of edges say E(u,v,w).
//Output: MST edge List say MSTEdgeList.
//1) Sort E by u. Pass this sorted list to the next step.
//2) Sort by u,w for each processor. For each distinct u, we pick the cheapest weighted edge. If (u>v) then flip u,v to v,u and store in cheapestEdgesList.
//3) Sort the cheapestEdgesList by u,v globally. Traverse the cheapestEdgesList and check for consecutive duplicate edges. If found, add it to MSTEdgeList.
//4) Sort
//Structures that are parallel:
//The original edge list is parallel on u and can be partitioned.
//The cheapest edges list is also parallel on u and can be mapped to original edge list.
//The cheapest edges list needs global sorting so not good for distributed system. ok in shared address space.
//The cheapest
//The MSTEdges list is also parallel

//Parallel version for shared address space:
//Input: A list of edges say E(u,v,w).
//Output: MST edge List say MSTEdgeList.
//1) Sort E by u. Pass this sorted list to the next step.
//2) Sort by u,w for each processor. For each distinct u, we pick the cheapest weighted edge. If (u>v) then flip u,v to v,u and store in cheapestEdgesList.
//3) .....Step left to be done in distributed...... Traverse the cheapestEdgesList and check for consecutive duplicate edges. If found, add it to MSTEdgeList.
//4)