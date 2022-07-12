/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define N 9
#define empty 0
using namespace std;

/* Checking  entries that don't possess a value. */
bool isEmptyLocation(int grid[N][N], int &row, int &col)
{
    for (row=0;row<9;row++){
        for (col=0;col<N;col++){
            if (grid[row][col] == empty){return true;}
        }
    }
    return false;
}

bool isGridSafe(int grid[N][N], int row, int col, int num);////checking if a number can be assigned or not to the grid cell

bool SolveSudoku(int grid[N][N])
{
    int row, col;
    if(!isEmptyLocation(grid,row,col)){return true;}
    for (int num=1;num<=N;num++)
    {
        if (isGridSafe(grid,row,col,num))
        {
            grid[row][col]=num;
            if(SolveSudoku(grid)){return true;}
            else{grid[row][col]=empty;}
        }
    }
    return false;
}

// Check for number already present in row
bool UsedInRow(int grid[N][N],int p_row,int number)
{
    for (int col=0;col<N;col++){
        if (grid[p_row][col]==number){return true;}
    }
    return false;
}

//Check for number already present in column
bool UsedInCol(int grid[N][N],int p_col,int number)
{
    for (int row=0;row<N;row++){
        if (grid[row][p_col]==number){return true;}

  else {return false;}
    }
}

//Check for number already used in the grid box 3x3
bool UsedInBox(int grid[N][N],int boxBeginRow,int boxBeginCol,int number)

{
    bool val=0;
    for (int row =0;row<3;row++){
        for (int col = 0; col < 3; col++){
            if (grid[row+boxBeginRow][col+boxBeginCol] == number){val=1;}
        }
    }
    return val;
}

//checking if a number can be assigned or not to the grid cell
bool isGridSafe(int grid[N][N], int prow, int pcol, int number)
{
    return{!UsedInRow(grid,prow,number)&&!UsedInCol(grid,pcol,number)&&!UsedInBox(grid,prow-prow%3,pcol-pcol%3,number)};
}
//printing results
void printResult(int finalgrid[N][N])
{
    for (int row =0;row<N;row++)
    {
        for (int col=0;col<N;col++){cout<<finalgrid[row][col]<<"  ";}
        cout<<endl;
    }
}

/* Main code */
int main()
{int grid[N][N];
    for(int i=0;i<N;i++){
                  for(int j=0;j<N;j++){
                      cin>>grid[i][j];
                  }
}

if (SolveSudoku(grid)==true){printResult(grid);}
else{cout<<"No solution"<<endl;}
return 0;
}
