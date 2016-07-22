#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define N 2
#define win N
#define lose -N

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
bool dfs(int check_i, int check_j, int new_i, int new_j, char _map[N][N], int round){
	/*
		1. judge the row
		2. judge the column
		3. if no side win, update map and play next round
	*/
	int i, j, row, col, x, count;
	if(_map[cor_i][cor_j] == '.'){
		// Judge the row
		count = 0;
		for(row=0; row<N; row++){
			if(_map[row][cor_j]=='o')
				count++;
			if(_map[row][cor_j]=='x')
				count--;
		}
		if(count == win)
			return false;
		else if(count == lose)
			return true;

		// Judge the column
		count = 0;
		for(col=0; col<N; col++){
			if(_map[cor_i][col]=='o')
				count++;
			if(_map[cor_i][col]=='x')
				count--;
		}
		if(count == win)
			return false;
		else if(count == lose)
			return true;

		// Judge the diagonal
		count = 0;
		for(x=0; x<N; x++){
			if(_map[x][x]=='o')
				count++;
			if(_map[x][x]=='x')
				count--;
		}
		if(count == win)
			return true;
		else if(count == lose)
			return false;
		count = 0;
		for(x=0; x<N; x++){
			if(_map[x][N-x]=='o')
				count++;
			if(_map[x][N-x]=='x')
				count--;
		}
		if(count == win)
			return true;
		else if(count == lose)
			return false;

		

		// Update and recursive
		// Assign the variable
		char newMap[N][N];
		int k, l;
		for(k=0; k<N; k++){
			for(l=0; l<N; l++)
				newMap[k][l] = map[k][l];
		}


		if(round%2==0)
			newMap[cor_i][cor_j] = 'x';
		else
			newMap[cor_i][cor_j] = 'o';

		printf("new map:\n");
		printMap(newMap);
		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				if(!dfs(i, j, newMap, round+1))
					return false;
			}
			return true;
		}		
	}

	// Judge tie
	bool isTie = true;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			if(_map[i][j]=='.')
				isTie = false;
	return isTie;
}

// Print the map
void printMap(char _map[N][N]){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			printf("%c", _map[i][j]);
		printf("\n");
	}
}

int main(){
	FILE *fptr1, *fptr2;
	int i, j;
	freopen("movein.txt", "r", stdin);
	//freopen("movein.txt", "w", stdout);

	// read the map
	readMap();

	printMap(map);

	// recursive judge the game
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("do: (%d, %d)\n", i, j);
			if(dfs(i, j, i, j, map, 0))
				printf("win: (%d, %d)\n", i, j);
		}
	}
}
