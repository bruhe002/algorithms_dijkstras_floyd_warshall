#ifndef DIJKSTRAS_H
#define DIJKSTRAS_H

#include <utility>

using namespace std;

void relax(int** graph, int* dist, int* prev, int nodeToConnect, int nodeDestination);

int lowestDistanceIndex(int* dist, int* mark, int numOfNodes);

void printArray(pair<int*, int*> dist_prev, int numOfNodes);

void dijkstraSP(int **graph, pair<int*, int*> returnArrays, int numOfNodes, int startingNode);



#endif
