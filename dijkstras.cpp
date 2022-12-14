#include <iostream>
#include <string>
#include <utility>

#include "dijkstras.h"

using namespace std;

void relax(int** graph, int* dist, int* prev, int nodeToConnect, int nodeDestination) {
    if(dist[nodeDestination] > dist[nodeToConnect] + graph[nodeToConnect][nodeDestination]) {
        dist[nodeDestination] = dist[nodeToConnect] + graph[nodeToConnect][nodeDestination];
        prev[nodeDestination] = nodeToConnect;
    }
}

int lowestDistanceIndex(int* dist, int* mark, int numOfNodes) {
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

void printPair(pair<int*, int*> dist_prev, int numOfNodes) {
    cout << "Dist: ";
    for(int i = 0; i < numOfNodes; i++) {
        cout << dist_prev.first[i] << " ";
    }

    cout << endl << "Prev: ";

    for(int i = 0; i < numOfNodes; i++) {
        cout << dist_prev.second[i] << " ";
    }

    cout << endl << endl;
    
}

void dijkstraSP(int **graph, pair<int*, int*> returnArrays, int numOfNodes, int startingNode) {

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
        //printPair(returnArrays, numOfNodes);
    }

    printPair(returnArrays, numOfNodes);


    // Printing the shortest Path for all verticies with respect to startingNode
    for(int i = 0; i < numOfNodes; i++) {
        int tempIdx = i; 
        string path = "";
        int pathCost = 0;
        while (tempIdx != startingNode) { 
            if(tempIdx == i) {
                path = path +  + " -> " + to_string(tempIdx);
            } else {
                path = " -> " + to_string(tempIdx) + path;
            }       
            
            pathCost += returnArrays.first[tempIdx]; 
            tempIdx = returnArrays.second[tempIdx];
        }

        cout << startingNode << path << " = " << pathCost << endl;
        
    }
    cout << endl;
}

 