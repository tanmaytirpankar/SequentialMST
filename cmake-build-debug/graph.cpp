//
// Created by tanmaypoke on 27/4/19.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "graph.h"
using namespace std;
graph::graph() {
    this->numedges = 0;
    this->numvertices = 0;
}

graph::graph(int V, int E) {
    this->numvertices = V;
    this->numedges = E;
}
graph::graph(int V, int E, vector<edge> newEdgeList) {
    this->numvertices = V;
    this->numedges = E;
    this->edges = newEdgeList;
}
void graph::createGraph() {

}
void graph::createUndGrpfrmfile(string file) {
    ifstream in;
    in.open(file);
    if (in.is_open())
    {
        string line = "";
        //Reads number of vertices from file.
        getline(in,line,',');
        this->numvertices = stoi(line);
        //Reads number of edges from file.
        getline(in,line,'\n');
        this->numedges = stoi(line);
        int s,d,w = 0;
//        int i = 0;
        //Reads edges from file till end of file.
        while(!in.eof())
        {
            getline(in,line,',');
            s = stoi(line);
            getline(in,line,',');
            d = stoi(line);
            getline(in,line,'\n');
            w = stoi(line);
            edge temp = edge(s,d,w);
            edges.push_back(temp);
//            i++;
        }
        in.close();
        displayGraph();
        //Sorting by means of source vertex.
//        sort(edges.begin(),edges.end(),comparator1);
//        displayGraph();
    }
}
void graph::createUndGrpFrmDGrp(string file) {
    ifstream in;
    in.open(file);
    if (in.is_open())
    {
        string line = "";
        //Reads number of vertices from file.
        getline(in,line,',');
        this->numvertices = stoi(line);
        //Reads number of edges from file.
        getline(in,line,'\n');
        this->numedges = stoi(line) * 2;
        int s,d,w = 0;
//        int i = 0;
        //Reads edges from file till end of file.
        while(!in.eof())
        {
            getline(in,line,',');
            s = stoi(line);
            getline(in,line,',');
            d = stoi(line);
            getline(in,line,'\n');
            w = stoi(line);
            edge temp = edge(s,d,w);
//            edge temp = edge(s,d,w,i);
            edges.push_back(temp);
            temp = edge(d,s,w);
            edges.push_back(temp);
//            temp = edge(d,s,w,i);
//            i++;
        }
        in.close();
        displayGraph();
        //Sorting by means of edge numbers.
//        cout << "Graph sorted by u first then v:\n";
//        sort(edges.begin(),edges.end(),comparator1);
//        displayGraph();
    }
}
void graph::displayGraph() {
    cout << "numVertices:" << getNumvertices();
    cout << "\nnumEdges:" << getNumedges();
    cout << "\nSource Destination Weight\n";
    for (int i = 0; i < edges.size(); ++i) {
        cout << edges[i].getSource() << "\t";
        cout << edges[i].getDestination() << "\t";
        cout << edges[i].getWeight() << "\n";
    }
}
void graph::displayGraph1() {
    cout << "\nnumVertices:" << getNumvertices();
    cout << "\nnumEdges:" << getNumedges();
    cout << "Source Destination Weight EdgeNum\n";
    for (int i = 0; i < edges.size(); ++i) {
        cout << edges[i].getSource() << "\t";
        cout << edges[i].getDestination() << "\t";
        cout << edges[i].getWeight() << "\t";
        cout << edges[i].getRandnum() << "\n";
    }
}
bool graph::comparator1(edge edge1, edge edge2) {
//    cout << "comparing [" << edge1.getSource() <<"," << edge1.getWeight()<<"]";
//    cout << ", [" << edge2.getSource() <<"," << edge2.getWeight()<<"] = " << (edge1.getSource() < edge2.getSource())<<"\n";
    return (edge1.getSource() < edge2.getSource());
}
bool graph::comparator2(edge edge1, edge edge2) {
    if (edge1.getSource() < edge2.getSource())
        return true;
    else if(edge1.getSource() > edge2.getSource())
        return false;
    else {
        if (edge1.getDestination() <= edge2.getDestination())
            return true;
        else
            return false;
    }
}
bool graph::comparator4(edge edge1, edge edge2) {
    return (edge1.getRandnum() < edge2.getRandnum());
}
bool graph::comparator3(edge edge1, edge edge2) {
//    cout << "comparing [" << edge1.getSource() <<"," << edge1.getWeight()<<"]";
//    cout << ", [" << edge2.getSource() <<"," << edge2.getWeight()<<"] = " << (edge1.getSource() < edge2.getSource())<<"\n";
    if (edge1.getSource() < edge2.getSource())
        return true;
    else if(edge1.getSource() > edge2.getSource())
        return false;
    else {
        if (edge1.getWeight() <= edge2.getWeight())
            return true;
        else
            return false;
    }
}
int graph::getNumedges() {
    return numedges;
}

int graph::getNumvertices() {
    return numvertices;
}
vector<edge> graph::getEdges() {
    return this->edges;
}

