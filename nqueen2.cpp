#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<string>> &chessBoard, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << chessBoard[i][j] << "   \n";
        }
        cout << endl;
    }

    cout << "------------------------" << endl;
}

bool check(vector<string> pp, int i, int j, int n)
{
    // left diagonal
    int row = i;
    int col = j;
    while (row >= 0 && col >= 0)
    {
        if (pp[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    // upper column
    row = i;
    col = j;
    while (row >= 0)
    {
        if (pp[row][col] == 'Q')
            return false;
        row--;
    }

    // right diagonal
    row = i;
    col = j;
    while (row >= 0 && col < n)
    {
        if (pp[row][col] == 'Q')
            return false;
        row--;
        col++;
    }

    return true;
}
void pq(vector<vector<string>> &ans, vector<string> &pp, int nq /*no of rows filled*/, int n)
{
    if (nq == n)
    {
        ans.push_back(pp);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check(pp, nq, i, n))
        {
            pp[nq][i] = 'Q';
            pq(ans, pp, nq + 1, n);
            pp[nq][i] = '-';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> pp(n);
    string s(n, '-');
    for (int i = 0; i < n; i++)
    {
        pp[i] = s;
    }
    pq(ans, pp, 0, n);

    return ans;
}

int main()
{
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);

    printBoard(ans, n);
}