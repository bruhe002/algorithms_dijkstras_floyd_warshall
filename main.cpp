#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>


using namespace std;

void printMatrix(int **matrix, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
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



    // Necessary Arrays
    int *dist = new int[numOfNodes];
    int *prev = new int[numOfNodes];

    // Build arrays


    // Deleting Memory
    delete dist;
    dist = nullptr;
    delete prev;
    prev = nullptr;
    for(int i = 0; i < numOfNodes; i++) {
        delete weightMatrix[i];
        weightMatrix = nullptr;
    }

    delete weightMatrix;
    weightMatrix = nullptr;

    cout << endl;
    system("Pause");
    return 0;
}