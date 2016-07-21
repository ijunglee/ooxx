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
bool dfs(char map[N][N], int side, int round){
	/*
		1. judge the O
		2. judge the X
		3. if no match, update map and play next round
	*/

	// Judge the O
	bool isGetLine = false;
	for(int row=0; row<N; row++){
		if(row_check(matrix, row, round) == -5)
			return false;
	}
	for(int col=0; col<N; col++){
		if(col_check(matrix, col, round) == -5)
			return false;
	}
	for(int x=0; x<N; x++){
		if(x_check(matrix, x, round) == -5)
			return false;
	}
	
	// Judge the X
	bool isGetLine = false;
	for(int row=0; row<N; row++){
		if(row_check(matrix, row, round) == 5)
			return false;
	}
	for(int col=0; col<N; col++){
		if(col_check(matrix, col, round) == 5)
			return false;
	}
	for(int x=0; x<N; x++){
		if(x_check(matrix, x, round) == 5)
			return false;
	}

	// If no dot, return true
	bool hasDot = false;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(map[i][j]=='.')
				hasDot = true;
	if(!hasDot)
		return true;

	// else, recursive doing
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] == '.'){
				char newMap[N][N];
				newMap = map;
				if(rount%2==0)
					newMap[i][j] = 'x';
				else
					newMap[i][j] = 'o';
				bfs()
			}
		}
	}
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

// Check if the row is complete
int row_check(char matrix[][N], int row, int round)
{
	int n_row=0;
	for(int col=0; col<N; col++){
		if(matrix[row][col]=='x'){
				n_row++;
		}
		if(matrix[row][col]=='o'){
				n_row--;
		}
	}
	return n_row; 
}

// Check if the column is complete
int col_check(char matrix[][N], int col)
{
	int n_col=0;
	for(int row=0; row<N; row++){
		if(matrix[row][col]=='x'){
			n_col++;
		}
		if(matrix[row][col]=='o'){
			n_col--;
		}
	}
	return n_col;
}

// Check if the diagonal is complete
int x_check(char matrix[][N], int x)
{
	int n_x=0;
	if(x==1){
		for(int r=0; r<N; r++){
			if(matrix[r][r]=='x'){
				n_x++;
			}
			if(matrix[r][r]=='o'){
				n_x--;
			}
		}
	}
	else if(x==2){
		for(int r=0; r<N; r++){
			if(matrix[r][N-r]=='x'){
				n_x++;
			}
			if(matrix[r][N-r]=='o'){
				n_x--;
			}
		}
	}
	return n_x;
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
