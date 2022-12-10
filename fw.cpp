#include <iostream>

#include "fw.h"

using namespace std;

int** allPairShortestPath(int** graph, int numOfNodes) {
    int** copyGraph = new int*[numOfNodes];
    for(int i = 0; i < numOfNodes; i++) {
        copyGraph[i] = new int[numOfNodes];
        for(int j = 0; j < numOfNodes; j++) {
            copyGraph[i][j] = graph[i][j];
        }
    }
    for(int k = 0; k < numOfNodes; k++) {
        for(int i = 0; i < numOfNodes; i++) {
            for(int j = 0; j < numOfNodes; j++) {
                if(copyGraph[i][k] + copyGraph[k][j] < copyGraph[i][j])
                    copyGraph[i][j] = copyGraph[i][k] + copyGraph[k][j];
            }
        }
    }

    return copyGraph;
}