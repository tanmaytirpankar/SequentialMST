//
// Created by tanmaypoke on 27/4/19.
//
#include <iostream>
#include "edge.h"
using namespace std;
edge::edge() {
    this->source = -1;
    this->destination = -1;
    this->weight = -1;
}

edge::edge(int s, int d, int w, int os, int od) {
    this->source = s;
    this->destination = d;
    this->weight = w;
    this->src_original = os;
    this->dest_original = od;
}
int edge::getSource() const {
    return source;
}
void edge::setSource(int source) {
    edge::source = source;
}
int edge::getDestination() const{
    return destination;
}
void edge::setDestination(int destination) {
    edge::destination = destination;
}
int edge::getWeight() const {
    return weight;
}
void edge::setWeight(int weight) {
    edge::weight = weight;
}
int edge::getSrcOriginal() const {
    return src_original;
}

int edge::getDestOriginal() const {
    return dest_original;
}