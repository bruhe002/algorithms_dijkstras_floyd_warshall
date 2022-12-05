#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

#include "dijkstras.h"
#include "fw.h"

using namespace std;

void printMatrix(int **matrix, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void deleteMatrix(int **matrix, int n) {
    for(int i = 0; i < n; i++) {
        delete matrix[i];
    }

    delete matrix;
}

void randWeightGenerator(int **matrix, int n) {
    for(int i = 0; i < n; i++) {
        matrix[i][i] = 0;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int weight = (rand() % 10) + 1;
            if(weight >= 8) {
                weight = 9999;
            }
            if(i != j) {
                matrix[i][j] = weight;
            }
            
        }
    }
}

int main() {
    cout << "Testing SHORTEST Path alforithms Algorithm" << endl << endl;
    cout << "Please enter the amount of nodes in the graph: ";
    int numOfNodes = 0;
    cin >> numOfNodes;

    // Graph Matrix
    int **weightMatrix = new int *[numOfNodes];
    for(int i = 0; i < numOfNodes; i++) {
        weightMatrix[i] = new int[numOfNodes];
    }

    // Seed for random number generator
    srand(time(0));
    randWeightGenerator(weightMatrix, numOfNodes);
    printMatrix(weightMatrix, numOfNodes);

    // Create Pair
    pair<int*, int*> dist_and_prev;
    dist_and_prev.first = new int[numOfNodes];
    dist_and_prev.second = new int[numOfNodes];

    
    // Perform Dijkstra's Algorithm
    for(int i = 0; i < numOfNodes; i++) {
        cout << "Starting point: " << i << endl;
        dijkstraSP(weightMatrix, dist_and_prev, numOfNodes, i);
    }
    
    
    // Does it work?
    
    // Perform Floyd-Warshall
    int** shortestPathMatrix = allPairShortestPath(weightMatrix, numOfNodes);
    printMatrix(shortestPathMatrix, numOfNodes);

    // delete the pointers
    delete dist_and_prev.first;
    dist_and_prev.first = nullptr;
    delete dist_and_prev.second;
    dist_and_prev.second = nullptr;

    deleteMatrix(weightMatrix, numOfNodes);
    deleteMatrix(shortestPathMatrix, numOfNodes);

    cout << endl;
    system("Pause");
    return 0;
}