#include <iostream>

using namespace std;

class BF{
    
private:
    int size;
    int* finalPath;

public:
    int TSP(int** mainMatrix, int mainSize);
    void show();
};