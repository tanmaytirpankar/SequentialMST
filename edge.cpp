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

edge::edge(int s, int d, int w) {
    this->source = s;
    this->destination = d;
    this->weight = w;
}
edge::edge(int s, int d, int w, int r) {
    this->source = s;
    this->destination = d;
    this->weight = w;
    this->randnum = r;
}
int edge::getSource() {
    return source;
}
void edge::setSource(int source) {
    edge::source = source;
}
int edge::getRandnum() {
    return randnum;
}
void edge::setRandnum(int randnum) {
    edge::randnum = randnum;
}
int edge::getDestination() {
    return destination;
}
void edge::setDestination(int destination) {
    edge::destination = destination;
}
int edge::getWeight() {
    return weight;
}
void edge::setWeight(int weight) {
    edge::weight = weight;
}


