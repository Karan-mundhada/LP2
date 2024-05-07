#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>>& chessBoard, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << chessBoard[i][j] << "   ";
        }
        cout << endl;
    }

    cout <<"------------------------" << endl;
}

bool isSafe2(vector<vector<char>>& chessBoard, int row, int col, int n)
{
    // cout << "Row : " << row << ", " << "Col: " << col << endl;
    int i = row, j = col;
    

    //Constraints check : 

    //1 Left row till 0th col
    while(j >= 0)
    {
        if(chessBoard[i][j] == 'Q')
        {
            return false;
        }
        j--;
    }
    //2 Upper left diagonal
    i = row; j = col;
    while(i >= 0 && j >= 0)
    {
        if(chessBoard[i][j] == 'Q')
        {
            return false;
        }
        i--;j--;
    }
    //3 Bottom left diagonal
    i = row; j = col;
    while(i < n && j >= 0)
    {
        if(chessBoard[i][j] == 'Q')
        {
            return false;
        }
        i++; j--;
    }

    //If all positions are checked and out of loop --> Correct position
    return true;
}

bool solveQueens(vector<vector<char>>& chessBoard, int col, int n , bool &flag)
{
    if(col == n)
    {
        flag = true;
        return true;
    }
    

    //1 case
    // Try placing queen of every row in single col 
    bool ans = false;
    for(int row = 0; row < n; row++)
    {
        if(isSafe2(chessBoard, row, col, n) == true)
        {
            chessBoard[row][col] = 'Q';
            //multiple case
            bool x = solveQueens(chessBoard, col+1, n , flag);
            if(x == true){
                printBoard(chessBoard, n);
                if(col == 0){
                    cout<<"=========================================\n";
                }
            }
            ans = ans|x;

            //backtrack
            chessBoard[row][col] = '-';
        }
    }

    return ans;
}

int main()
{
    //Problem 3 
    int cols = 0, n ;

    cout<<"Enter n :- ";

    cin>>n;
    if(n<=3){
        cout<<"No solution ";
        return 0;
    }
    vector<vector<char>> chessBoard(n, vector<char>(n, '-'));
    // printBoard(chessBoard, n);
    bool flag = false;

    cout<<"Solutions for n == "<<n<<" is :-\n";
    solveQueens(chessBoard, cols, n , flag);
}