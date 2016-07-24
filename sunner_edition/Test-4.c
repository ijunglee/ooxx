#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define N 4
#define win -N
#define lose N

char map[N][N];						// map
int xSet[N*N]={0}, ySet[N*N]={0};	// set

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

// Print the map
void printMap(char _map[N][N]){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			printf("%c", _map[i][j]);
		printf("\n");
	}
}

// DFS run the game
int dfs(int check_i, int check_j, int new_i, int new_j, char _map[N][N], int round){
	/*
		1. judge the row
		2. judge the column
		3. if no side win, update map and play next round
	*/
	int i, j, row, col, x, count;

	// Judge the row
	count = 0;
	for(row=0; row<N; row++){
		if(_map[row][check_j]=='o')
			count++;
		if(_map[row][check_j]=='x')
			count--;
	}
	if(count == win){
		//printf("row win: (%d, %d)\n", check_i, check_j);
		return win;
	}
	else if(count == lose){
		//printf("row lose: (%d, %d)\n", check_i, check_j);
		return lose;
	}
	// Judge the column
	count = 0;
	for(col=0; col<N; col++){
		if(_map[check_i][col]=='o')
			count++;
		if(_map[check_i][col]=='x')
			count--;
	}
	if(count == win){
		//printf("col win: (%d, %d)\n", check_i, check_j);
		return true;
	}
	else if(count == lose){
		//printf("row lose: (%d, %d)\n", check_i, check_j);
		return false;
	}
	// Judge the diagonal
	count = 0;
	for(x=0; x<N; x++){
		if(_map[x][x]=='o')
			count++;
		if(_map[x][x]=='x')
			count--;
	}
	if(count == win){
		//printf("diagonal win: (%d, %d)\n", check_i, check_j);
		return win;
	}
	else if(count == lose){
		//printf("diagonal lose: (%d, %d)\n", check_i, check_j);
		return lose;
	}
	count = 0;
	for(x=0; x<N; x++){
		//printf("map[%d][%d]:%c\n", x, N-x, _map[x][N-x]);
		if(_map[x][N-x-1]=='o')
			count++;
		if(_map[x][N-x-1]=='x')
			count--;
	}
	//printf("diagonal: %d\n", count);
	if(count == win){
		//printf("row win: (%d, %d)\n", check_i, check_j);
		return win;
	}
	else if(count == lose){
		//printf("row lose: (%d, %d)\n", check_i, check_j);
		return lose;
	}
	
	// Update and recursive
	// Assign the variable
	if(_map[new_i][new_j] == '.'){
		char newMap[N][N];
		int k, l;
		for(k=0; k<N; k++){
			for(l=0; l<N; l++)
				newMap[k][l] = _map[k][l];
		}


		if(round%2==0)
			newMap[new_i][new_j] = 'x';
		else
			newMap[new_i][new_j] = 'o';

		//printf("new map:\n");
		//printMap(newMap);
		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				if(dfs(new_i, new_j, i, j, newMap, round+1) == lose){
					//printf("LOSE!!!\n");
					return lose;
				}
			}	
		}	
		return win;	
	}

	// Judge tie
	bool isTie = true;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			if(_map[i][j]=='.')
				isTie = false;
	//printf("tie: %s\n", (isTie?"Win":"Lose"));
	if(isTie)
		return win;
}

int main(){
	FILE *fptr1, *fptr2;
	int i, j;
	freopen("movein.txt", "r", stdin);
	freopen("moveout.txt", "w", stdout);

	// read the map
	readMap();

	//printMap(map);

	// recursive judge the game
	int index = 0;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			//printf("do: (%d, %d)\n", i, j);
			if(map[i][j]=='.'){
				if(dfs(i, j, i, j, map, 0) == win){
					//printf("( %d, %d )\n", i, j);
					xSet[index] = i;
					ySet[index++] = j;
				}
			}
		}
	}

	// print the result
	printf("-----Result:-----\n");
	if(index>0){
		for(i=0; i<index; i++)
			printf("( %d , %d )\n", xSet[i], ySet[i]);
	}else
		printf("#####\n");
}
