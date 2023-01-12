#include "BF.h"
#include <vector>
#include <algorithm>
#include <climits>

//glowna funkcja rozwiazujaca TSP
int BF::TSP(int** mainMatrix, int mainSize){

    vector<int> cities;
	size=mainSize;
	finalPath = new int [size+1];
	int* tempPath = new int [size+1];

	for (int i = 0; i < size; i++){
		if (i != 0){
			cities.push_back(i);
		}
	}

	int minDistance = INT_MAX;

	do{
		int currDistance = 0;

		int k = 0;
		for (int i = 0; i < cities.size(); i++){
			currDistance += mainMatrix[k][cities[i]];
			tempPath[i]=k;
			k = cities[i];
		}
		currDistance += mainMatrix[k][0];
		tempPath[size-1] = k;

		if(minDistance>currDistance){

			minDistance=currDistance;

			for(int z=0;z<size+1;z++){
				finalPath[z]=tempPath[z];
			}
		}

	}
	while(next_permutation(cities.begin(), cities.end()));

	delete tempPath;

	return minDistance;
}

//funkcja wyswietlajaca finalna sciezke
void BF::show(){
	for(int i=0;i<size;i++){
		 if(i==size-1){
           cout<<finalPath[i]<<endl;
            continue;
        }
        cout<<finalPath[i]<<"->";
	}
	delete finalPath;
}