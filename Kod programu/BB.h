#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <climits>
using namespace std;


struct Vertex{

    vector<pair<int, int>> path;
    int** minMatrix;      
    int cost;   
    int value;
    int level;
};

class BB{

    private:
        int size;
        Vertex* minVertex;

    public:
        Vertex* newVertex(int** parentMatrix, vector<pair<int, int>> path, int level, int i, int j);
        int bound(int** minMatrix);
        void show();
        int TSP(int** mainMatrix, int mainSize);


};