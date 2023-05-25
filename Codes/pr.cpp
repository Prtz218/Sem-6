#define N 4
#include<stdbool.h>
#include<stdio.h>

int ld[30]={0};
int rd[30]={0};
int cl[30]={0};

void printsolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d", board[i][j]);
           
        }
        printf("\n");
    }
    
}

bool utilNQ(int board[N][N], int col)
{
    if (col>=N)
    {
        return true;
    }

    for (int i = 0; i < N; i++)
    {
        if((ld[i-col+N-1]!=1 && rd[i+col]!=1) && cl[i]!=1)
        {
            board[i][col]=1;
            ld[i-col+N-1]= rd[i+col]=1;

            if(utilNQ(board, col+1))
            return true;

            board[i][col]=0;
            ld[i-col+N-1]=rd[i+col]=cl[i]=0;
        }
    }
    return false;
}

bool solve()
{
    int board[N][N] = {{0},{0}};
    if (utilNQ(board,0) == false)
    {
        printf("Solution does not exist");
        return false;
    }
    printsolution(board);
    return true;
}

int main()
{
    solve();
    return 0;
}