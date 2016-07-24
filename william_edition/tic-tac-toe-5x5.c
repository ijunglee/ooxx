#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int size = 5;


int print(char matrix[][size]);
int row_check(char matrix[][size], int);
int col_check(char matrix[][size], int);
int x_check(char matrix[][size], int);
int analyze(char matrix[][size]);

// position structure
struct pos{
	int row;
	int col;
};


int main(){
	int n, k;
    int n_c[size], n_r[size],n_x[2];
    char matrix[size][size];
    int nothing=0;
    FILE *fPtr1, *fPtr2;

    fPtr1 = freopen("moveIn.txt","r",stdin);
    //fPtr2 = freopen("movesOut.txt","w",stdout);
    if (!fPtr1) {
        printf("檔案建立失敗...\n");
        exit(1);
    }
    /*
	if (!fPtr2) {
        printf("檔案建立失敗...\n");
        exit(1);
    }
	*/

	// get the times
	scanf("%d\n", &n);
	printf("%d round(s)\n", n);
	
	/* 	Start 
		Get the map
	*/
	for(k=0; k<n; k++)
	{
		printf("Test Case #%d:\n", k+1);
		/* Get Board */
		for(int row=0; row<size; row++){
			for(int col=0; col<size; col++)
				scanf("%c", &matrix[row][col]);
			scanf("\n");
		}
		
		print(matrix);
		analyze(matrix);
		
			
		printf("\n");
	}
	
	system("pause");
    return 0;
}

// Print the matrix
int print(char matrix[][size])
{
	for(int row=0; row<size; row++){
		for(int col=0; col<size; col++)
			printf("%c", matrix[row][col]);
		//printf(" %2d", row_check(matrix, row));
		printf("\n");
		}
}

int row_check(char matrix[][size], int row)
{
	int n_row=0;
	for(int col=0; col<size; col++){
		if(matrix[row][col]=='x'){
			n_row++;
		}
		if(matrix[row][col]=='o'){
			n_row--;
		}
	}
	return n_row; 
	//if(n_row == (size-1)) return 1;
	//else return 0;
}

int col_check(char matrix[][size], int col)
{
	int n_col=0;
	for(int row=0; row<size; row++){
		if(matrix[row][col]=='x'){
			n_col++;
		}
		if(matrix[row][col]=='o'){
			n_col--;
		}
	}
	return n_col;
	//if(n_col == (size-1)) return 1;
	//else return 0;
}

int x_check(char matrix[][size], int x)
{
	int n_x=0;
	if(x==1){
		for(int r=0; r<size; r++){
			if(matrix[r][r]=='x'){
				n_x++;
			}
			if(matrix[r][r]=='o'){
				n_x--;
			}
		}
	}
	else if(x==2){
		for(int r=0; r<size; r++){
			if(matrix[r][size-r]=='x'){
				n_x++;
			}
			if(matrix[r][size-r]=='o'){
				n_x--;
			}
		}
	}
	return n_x;
	//if(n_x == size-1) return 1;
	//else return 0;
}

int analyze(char matrix[][size])
{
	// row check
	for(int row=0; row<size; row++){
		row_check(matrix, row);
	}

	// column check
	for(int col=0; col<size; col++){
		col_check(matrix, col);
	}

	// diagonal
	for(int x=0; x<2; x++){
		x_check(matrix, x);
	}
}

