#Use this scripts to get a reduced set of undirected graph from the original set where the first line is num vertices and num edges.
#If you take some lines from the original set, the edges in them may or may not contain the second edge where u and v are flipped.
#This script helps to create an undirected graph from such a set and builds a smaller undirected graph.
#To use this set cut the last line which is the numverts and numedges and paste it on first line.
#Make sure there is no blank last line.

import random
f1= open("3980.edges","r")
f2= open("temp1","w")
edgeset = set()
set_verts = set()
x = f1.readline()
for linenum in range(10):
    x = f1.readline()
    x = x.split(",")
    edgeset.add(tuple([int(x[0]), int(x[1]), int(x[2].rstrip())]))
    edgeset.add(tuple([int(x[1]), int(x[0]), int(x[2].rstrip())]))
    set_verts.add(int(x[0]))
    set_verts.add(int(x[1]))
for edge in edgeset:
    y = str(edge[0]) + ',' + str(edge[1]) + ',' + str(edge[2]) + '\n'
    f2.write(y)
f2.write(str(len(set_verts))+','+str(len(edgeset)))
f2.close()
f1.close()