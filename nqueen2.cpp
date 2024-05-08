#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<string>> &answers, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << answers[i][j] << "   \n";
        }
        cout << endl;
    }

    cout << "------------------------" << endl;
}

bool check(vector<string> chessboard, int i, int j, int n)
{
    // left diagonal
    int row = i;
    int col = j;
    while (row >= 0 && col >= 0)
    {
        if (chessboard[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    // upper column
    row = i;
    col = j;
    while (row >= 0)
    {
        if (chessboard[row][col] == 'Q')
            return false;
        row--;
    }

    // right diagonal
    row = i;
    col = j;
    while (row >= 0 && col < n)
    {
        if (chessboard[row][col] == 'Q')
            return false;
        row--;
        col++;
    }

    return true;
}
void solve(vector<vector<string>> &ans, vector<string> &chessboard, int nq /*no of rows filled*/, int n)
{
    if (nq == n)
    {
        ans.push_back(chessboard);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check(chessboard, nq, i, n))
        {
            chessboard[nq][i] = 'Q';
            solve(ans, chessboard, nq + 1, n);
            chessboard[nq][i] = '-';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> chessboard(n);
    string s(n, '-');
    for (int i = 0; i < n; i++)
    {
        chessboard[i] = s;
    }
    solve(ans, chessboard, 0, n);

    return ans;
}

int main()
{
    int n = 6;

    vector<vector<string>> ans = solveNQueens(n);

    printBoard(ans, n);
}