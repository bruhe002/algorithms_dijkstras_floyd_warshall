#ifndef DIJKSTRAS_H
#define DIJKSTRAS_H

#include <utility>

using namespace std;

void relax(const int** graph, int* dist, int* prev, int nodeToConnect, int nodeDestination);

int lowestDistanceIndex(const int* dist, const int* mark, int numOfNodes);

void dijkstraSP(const int **graph, pair<int*, int*> returnArrays, int numOfNodes, int startingNode);



#endif
