//
// Created by tanmaypoke on 27/4/19.
//

#ifndef GRAPHCOLOURING_GRAPH_H
#define GRAPHCOLOURING_GRAPH_H

#include "edge.h"
#include <vector>
using namespace std;
class graph {
public:
    int numedges,numvertices;
    vector<edge> edges;

    graph();
    //Constructor which initializes the number of vertices and number of edges.
    graph(int, int);
    //Constructor which initializes edge list as well.
    graph(int, int, vector<edge>);
    //Creates undirected graph structure using the undirected graph input edges provided from the file.
    //***Random numbers representing edge numbers not assigned yet.
    void createUndGrpfrmfile(string);
    //Creates undirected graph from the directed graph provided in the file.
    //Makes it easy to assign the random numbers that represent the edge numbers.
    void createUndGrpFrmDGrp(string);
    //Displays the graph in the form of an edge list.
    void displayGraph();
    //Displays the graph in the form of an edge list along with edge numbers.
    void displayGraph1();
    //Comparator for sorting edges by means of source vertex only.
    static bool comparator1(edge, edge);
    //Comparator for sorting edges by means of source vertex first and then by destination vertex.
    static bool comparator2(edge, edge);
    //Comparator for sorting edges by means of source vertex first and then by weights.
    static bool comparator3(const edge&, const edge&);
    //Comparator for sorting edges by means of random number only.
    static bool comparator4(edge, edge);
    int getNumedges();
    int getNumvertices();
    vector<edge> getEdges();
};


#endif //GRAPHCOLOURING_GRAPH_H
