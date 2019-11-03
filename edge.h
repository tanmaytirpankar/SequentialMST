//
// Created by tanmaypoke on 27/4/19.
//

#ifndef GRAPHCOLOURING_EDGE_H
#define GRAPHCOLOURING_EDGE_H



class edge {
    int source,destination,weight,randnum;
public:
    //Constructor initializing everything to -1.
    edge();
    //Constructor which initializes the sources vertex, destination vertex and weight of edge.
    edge(int,int,int);
    //Constructor which initializes the sources vertex, destination vertex, weight of edge and random number
    // representing edge number.
    edge(int,int,int,int);
    void operator =(edge const &edge2);
    int getSource() const;
    int getDestination() const;
    int getWeight() const;
    int getRandnum();

    void setSource(int source);

    void setDestination(int destination);

    void setWeight(int weight);

    void setRandnum(int randnum);
};


#endif //GRAPHCOLOURING_EDGE_H
