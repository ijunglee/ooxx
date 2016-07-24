#include<stdio.h>
#include<cmath>
#define N 5
using namespace std;

int map[N][N];

// Implement reading the map
void readMap(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
		}
	}
}

// DFS run the game
bool dfs(){
	return false;
}

// Print the map
void printMap(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			cout << map[i][j] << '\t';
		cout << endl;
	}
}

int main(){
	// read the map
	readMap();

	printMap();

	// recursive judge the game
	dfs();
}
