/*    brioso     */
#include <iostream>
#include <iterator>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include "stdio.h"
/*
* this fun calculate how many rows have more than 3 'x' and 0 'o'
*/
int threexc(char* G){
    int num = 0;
    for(int i = 0; i < 4; i++)
    {
            int numofx = 0;
            int flag = 1;
            
            for(int j = 0; j < 4; j++)
            {
                    if(G[4 * i + j] == 'o')
                    {
                           flag = 0;
                           break;
                    }
                    else if(G[4 * i + j] == 'x')
                    {
                         numofx++;
                    }
            }
            if(numofx >= 3)
            {
                      num++;
            }
    }
    return num;
}

int threexr(char* G){
        int num = 0;
    for(int j = 0; j < 4; j++)
    {
            int numofx = 0;
            int flag = 1;
            
            for(int i = 0; i < 4; i++)
            {
                    if(G[4 * i + j] == 'o')
                    {
                           flag = 0;
                           break;
                    }
                    else if(G[4 * i + j] == 'x')
                    {
                         numofx++;
                    }
            }
            if(numofx >= 3)
            {
                      num++;
            }
    }
    return num;
}

int threexd(char* G){
    int num = 0;
    int numofx = 0;
    for(int i = 0; i < 4; i++)
    {
            
           
            if(G[5 * i] == 'o')
            {
                   continue;
            }
            if(G[5 * i] == 'x')
            {
                   numofx++;
            }
    }
    if(numofx >= 3)
    {
              num++;
    } 
    numofx = 0;
    for(int i = 0; i < 4; i++)
    {
           
            if(G[3 * i + 3] == 'o')
            {
                   continue;
            }
            if(G[3 * i + 3] == 'x')
            {
                   numofx++;
            }
    }
    if(numofx >= 3)
    {
              num++;
    }
     return num;
}
int threex(char* G){
    int x = threexc(G) + threexr(G) + threexd(G);
    return x;
}
void PrintPos(char* G)
{
     int flag = 0;
     for(int i = 0; i < 16; i++)
     {
             if(G[i] == '.')
             {
                     G[i] = 'x';
                     if(threex(G) > 1)
                     {
                                  flag = 1;
                                  printf("(%d, %d)\n",i / 4 ,i % 4);
                     }
                     G[i] = '.';
             }
     }
     
     if(flag == 0)
     {
             printf("#####\n");
     }
     
     printf("\n");
}

int main()
{
    freopen("moves.in","r",stdin);
    freopen("moves.out","w",stdout);
    char s[10];
	int t, cases = 0;
	scanf("%d", &t);
	char G[20];
	char c;
	while (t--) {
        int i = 0;
		cases++;
		printf("Test Case #%d: \n", cases);
		for(int i = 0 ; i < 4 ; i++){
                scanf("%s",s);
                for(int j = 0 ; j < 4 ; j++){
                        G[i*4+j] = s[j];
                }
        }
        G[16] = '\0';
        
        PrintPos(G);
	}
	char c11 = getchar();
	c11 = getchar();
    return 0;
}

