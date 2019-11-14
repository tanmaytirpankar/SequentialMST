//
// Created by tanmaypoke on 27/4/19.
//

#ifndef GRAPHCOLOURING_EDGE_H
#define GRAPHCOLOURING_EDGE_H



class edge {
    int source,destination,src_original,dest_original,weight;
public:
    //Constructor initializing everything to -1.
    edge();
    //Constructor which initializes the sources vertex, destination vertex and weight of edge.
    edge(int,int,int,int,int);

    int getSource() const;

    int getDestination() const;

    int getWeight() const;

    int getSrcOriginal() const;

    int getDestOriginal() const;

    void setSource(int source);

    void setDestination(int destination);

    void setWeight(int weight);

};


#endif //GRAPHCOLOURING_EDGE_H
