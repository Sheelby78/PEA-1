#include "DP.h"

//glowna funkcja rozwiazujaca TSP
int DP::TSP(int** mainMatrix, int mainSize){

    int curr_distance, min_distance;
    size = mainSize;

    Matrix = new int* [size];
    temp = new int*[1 << size];
	temp2 = new int*[1 << size];

    for(int i=0;i<size;i++){
        Matrix[i] = new int [size];
        for(int j=0;j<size;j++){
            Matrix[i][j] = mainMatrix[i][j];
        }
    }

	for (int i = 0; i < (1 << size); i++) {
        temp[i] = new int[size];
		temp2[i] = new int[size];

		for (int j = 0; j < size; j++){
			temp[i][j] = INF;
			temp2[i][j] = INF;
		}
	}

	for (int i = 0; i < size; i++){
		temp[(1 << i) | 1][i] = Matrix[0][i];
		temp2[(1 << i) | 1][i] = 0;
	}

	for (int bitMask = 0; bitMask < 1 << size; bitMask++){
		for (int v = 0; v < size; v++){
			if (!(bitMask & (1 << v)))
				continue;

			for (int j = 0; j < size; j++){
				if (!(bitMask & (1 << j))){
					if (temp[bitMask][v] + Matrix[v][j] < temp[bitMask | (1 << j)][j]){
						temp2[bitMask | (1 << j)][j] = v;
						temp[bitMask | (1 << j)][j] = temp[bitMask][v] + Matrix[v][j];
					}
				}
			}
		}
	}

	min_distance = INF;
	curr_distance = 0;
    lastVertex = 0;

	for (int i = 0; i < size; i++){
		curr_distance = temp[(1 << size) - 1][i] + Matrix[i][0];
		if (curr_distance < min_distance){
			min_distance = curr_distance;
			lastVertex = i;
		}
	}

	delete[] temp;
    delete[] Matrix;

    return min_distance;
}

//funnkcja wyswietlajaca finalna sciezke
void DP::show(){

	int bitMask = (1 << size) - 1;
	int prevVertex;
	vector<int> finalPath;

	finalPath.push_back(lastVertex);

	for (int i = size - 2; i > 0; i--){
		prevVertex = temp2[bitMask][lastVertex];
		finalPath.push_back(prevVertex);
		bitMask = bitMask ^ (1 << lastVertex);
		lastVertex = prevVertex;
	}

    cout << 0 << "->";

	for(int i=finalPath.size()-1; i>=0; i--){
        if(i==0){
            cout << finalPath[i] <<endl;    
            continue;
        }
        cout << finalPath[i] << "->";
    }
	delete temp2;
}