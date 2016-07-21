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

int pos = 0;

int fourxc(char* G){
    int num = 0;
    for(int i = 0; i < 5; i++)
    {
            int numofx = 0;
            int flag = 1;

            for(int j = 0; j < 5; j++)
            {
                    if(G[5 * i + j] == 'o')
                    {
                           flag = 0;
                           break;
                    }
                    else if(G[5 * i + j] == 'x')
                    {
                         numofx++;
                    }
            }
            if(numofx >= 4)
            {
                      num++;
            }
    }
    return num;
}

int fourxr(char* G){
        int num = 0;
    for(int j = 0; j < 5; j++)
    {
            int numofx = 0;
            int flag = 1;

            for(int i = 0; i < 5; i++)
            {
                    if(G[5 * i + j] == 'o')
                    {
                           flag = 0;
                           break;
                    }
                    else if(G[5 * i + j] == 'x')
                    {
                         numofx++;
                    }
            }
            if(numofx >= 4)
            {
                      num++;
            }
    }
    return num;
}

int fourxd(char* G){
    int num = 0;
    int numofx = 0;
    for(int i = 0; i < 5; i++)
    {


            if(G[6 * i] == 'o')
            {
                   continue;
            }
            if(G[6 * i] == 'x')
            {
                   numofx++;
            }
    }
    if(numofx >= 4)
    {
              num++;
    }
    numofx = 0;
    for(int i = 0; i < 5; i++)
    {

            if(G[4 * i + 4] == 'o')
            {
                   continue;
            }
            if(G[4 * i + 4] == 'x')
            {
                   numofx++;
            }
    }
    if(numofx >= 4)
    {
              num++;
    }
     return num;
}
int fourx(char* G){
    int x = fourxc(G) + fourxr(G) + fourxd(G);
    return x;
}

void findNextPos(char* G)
{
    for(int i = 0; i < 25; i++)
    {
        G[i] = 'x';
        if(fourx(G) > 1)
        {
            printf("%d\n", G[i]);
        }
        else
        {
            for(int j = 0; j < 25; j++)
            {
                   if(G[j] == '.')
                   {
                            G[j] = 'o';
                            findNextPos(G);
                            G[j] = '.';
                    }
            }
        }
        G[i] = '.';
    }
}

void push(int *StackG, int value)
{
    StackG[pos++] = value;
}

int pop(int* StackG)
{
    return StackG[--pos];
}

void PrintPos(char* G, int* StackG)
{
     int flag = 0;
     int finish = 0;

     for(int i = 0; i < 25; i++)
     {
        if(G[i] == 'x')
        {
            push(StackG, i);
        }
     }
     for(int i = 0; i < sizeof(StackG); i++)
     {
         printf("%d\n", StackG[i]);
     }
     if(flag == 0)
     {
             printf("#####\n");
     }

     printf("\n");
}

void PrintG(char *G)
{
    for(int i = 0; i < 25; i++)
    {
        printf("%c", G[i]);
        if((i + 1) % 5 == 0)
            printf("\n");
    }

}



int main()
{
    freopen("moves.in","r",stdin);
    freopen("moves.out","w",stdout);
    char s[10];
	int t, cases = 0;
	scanf("%d", &t);
	char G[29];
	int StackOfG[100];
	char c;
	while (t--) {
        int i = 0;
		cases++;
		printf("Test Case #%d: \n", cases);
		for(int i = 0 ; i < 5 ; i++){
                scanf("%s",s);
                for(int j = 0 ; j < 5 ; j++){
                        G[i*5+j] = s[j];
                }
        }
        G[25] = '\0';
        PrintG(G);
        PrintPos(G, StackOfG);

        //PrintPos(G);
	}
	char c11 = getchar();
	c11 = getchar();
    return 0;
}

