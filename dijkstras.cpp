#include <iostream>
#include <utility>

#include "dijkstras.h"

using namespace std;

void relax(const int** graph, int* dist, int* prev, int nodeToConnect, int nodeDestination) {
    if(dist[nodeDestination] > dist[nodeToConnect] + graph[nodeToConnect][nodeDestination]) {
        dist[nodeDestination] = dist[nodeToConnect] + graph[nodeToConnect][nodeDestination];
        prev[nodeDestination] = nodeToConnect;
    }
}

int lowestDistanceIndex(const int* dist, const int* mark, int numOfNodes) {
    int lowestIdx = 0;
    int lowestDistance = 1000;
    for(int i = 0; i < numOfNodes; i++) {
        if(mark[i] == 0 && dist[i] < lowestDistance) {
            lowestDistance = dist[i];
            lowestIdx = i;
        }
    }

    return lowestIdx;
}

void dijkstraSP(const int **graph, pair<int*, int*> returnArrays, int numOfNodes, int startingNode) {

    // Mark array
    int *mark = new int[numOfNodes];

    // initialize arrays
    for(int i = 0; i < numOfNodes; i++) {
        returnArrays.first[i] = graph[startingNode][i];
        returnArrays.second[i] = startingNode;
        mark[i] = 0;
    }

    mark[startingNode] = 1;

    for(int nodesLeft = 1; nodesLeft < numOfNodes; nodesLeft++) {
        int lowestDistNode = lowestDistanceIndex(returnArrays.first, mark, numOfNodes);
        mark[lowestDistNode] = 1;
        for(int i = 0; i < numOfNodes; i++) {
            if(mark[i] == 0) {
                relax(graph, returnArrays.first, returnArrays.second, lowestDistNode, i);
            }
        }
    }
}

 