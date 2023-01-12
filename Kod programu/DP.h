#include <iostream>
#include <string>
#include <vector>

#define INF 99999

using namespace std;

class DP{
	
private:
	int **Matrix;
	int size;
	int **temp;
	int **temp2;
	int lastVertex;
	
public:
	int TSP(int** mainMatrix, int mainSize);
	void show();
};
