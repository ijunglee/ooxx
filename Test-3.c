#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define N 5

char map[N][N];

// Implement reading the map
void readMap(){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			scanf("%c", &map[i][j]);
		}
		scanf("\n");
	}
}

// DFS run the game
bool dfs(int ){
	/*
		1. judge the O
		2. judge the X
		3. 
	*/
	return false;
}

// Print the map
void printMap(){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
}

int main(){
	FILE *fptr1, *fptr2;
	freopen("movein.txt", "r", stdin);
	//freopen("movein.txt", "w", stdout);

	// read the map
	readMap();

	printMap();

	// recursive judge the game
	dfs();
}
