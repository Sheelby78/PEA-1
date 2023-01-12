#include "BB.h"

//funkcja liczaca ograniczenie 
int BB::bound(int** minMatrix){

    int cost = 0;
    int* row;
    int* col;
    row = new int[size];
    col = new int[size];

    for(int i=0;i<size;i++){
        row[i]=INT_MAX;
    }
 
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (minMatrix[i][j] < row[i]) {
                row[i] = minMatrix[i][j];
            }
        }
    }
 
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (minMatrix[i][j] != INT_MAX && row[i] != INT_MAX){
                minMatrix[i][j] -= row[i];
            }
        }
    }

    for(int i=0;i<size;i++){
    col[i]=INT_MAX;
    }
 
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (minMatrix[i][j] < col[j]) {
                col[j] = minMatrix[i][j];
            }
        }
    }
 
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (minMatrix[i][j] != INT_MAX && col[j] != INT_MAX){
                minMatrix[i][j] -= col[j];
            }
        }
    }
 
    for (int i = 0; i < size; i++){
        cost += (row[i] != INT_MAX) ? row[i] : 0,
            cost += (col[i] != INT_MAX) ? col[i] : 0;
    }
    delete row;
    delete col;

    return cost;
}

//struktura uzywana do porownania wartosci w kolejce priorytetowej
struct comp{
    bool operator()(const Vertex* lhs, const Vertex* rhs) const{
        return lhs->cost > rhs->cost;
    }
};

//glowna funkcja rozwiazujaca tsp
int BB::TSP(int** mainMatrix, int mainSize){

    size=mainSize;
    int** Matrix;
    Matrix = new int *[mainSize];
    
    for(int i=0; i<size; i++){
        Matrix[i] = new int [mainSize];

        for (int j=0; j<size; j++){
            Matrix[i][j] = mainMatrix[i][j];
        }
    }

    priority_queue<Vertex*, vector<Vertex*>, comp> cities;
    vector<pair<int, int>> current_path;
    Vertex* root = newVertex(Matrix, current_path, 0, -1, 0);

    root->cost = bound(root->minMatrix);
    cities.push(root);
 
    while (!cities.empty()){

        Vertex* minDistance = cities.top();
        cities.pop();
        int i = minDistance->value;

        if (minDistance->level == size - 1){

            minDistance->path.push_back(make_pair(i, 0));
            while(!cities.empty()){
                minVertex = cities.top();
                cities.pop();
                delete minVertex->minMatrix;
                delete minVertex;
            }
            minVertex = minDistance;
            return minDistance->cost;
        }
 
        for (int j = 0; j < size; j++){

            if (minDistance->minMatrix[i][j] != INT_MAX){

                Vertex* child = newVertex(minDistance->minMatrix, minDistance->path, minDistance->level + 1, i, j);
                child->cost = minDistance->cost + minDistance->minMatrix[i][j] + bound(child->minMatrix);
                cities.push(child);
            }
        }

        delete minDistance->minMatrix;
        delete minDistance;
    }
}

//funkcja tworzaca nowy wezel do kolejki
Vertex* BB::newVertex(int** parentMatrix, vector<pair<int, int>> path, int level, int i, int j){

    Vertex* vertex = new Vertex;
    vertex->path = path;

    if (level != 0){
        vertex->path.push_back(make_pair(i, j));
    }
 
    vertex->minMatrix = new int*[size];

    for(int i=0; i<size; i++){
        vertex->minMatrix[i] = new int[size];
        for (int j=0; j<size; j++){
            vertex->minMatrix[i][j] = parentMatrix[i][j];
        }
    }

    for (int k = 0; level != 0 && k < size; k++){

        vertex->minMatrix[i][k] = INT_MAX;
        vertex->minMatrix[k][j] = INT_MAX;
    }

    vertex->minMatrix[j][0] = INT_MAX;
    vertex->level = level;
    vertex->value = j;
 
    return vertex;
}
 
//funkcja wyswietlajaca finalna sciezke
void BB::show(){


    for (int i = 0; i < minVertex->path.size(); i++){
        if(i==minVertex->path.size()-1){
            cout << minVertex->path[i].first <<endl;    
            continue;
        }
        cout << minVertex->path[i].first << "->";
    }

    delete minVertex;
}
 