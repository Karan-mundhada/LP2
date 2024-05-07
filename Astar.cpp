#include <bits/stdc++.h>

using namespace std;

struct Cell {
    int x, y;
    int g, h, f;
};

// Define a comparison operator for the priority queue
struct CompareCells {
    bool operator()(const Cell& a, const Cell& b) {
        return a.f > b.f;  // Priority queue should pop the cell with the lowest f value
    }
};

// Function to check if a cell is within the grid boundaries
bool isValid(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

// A* pathfinding algorithm
void aStar(vector<vector<int>>& grid, Cell start, Cell goal) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Create a 2D array to store information about each cell
    vector<vector<Cell>> cells(rows, vector<Cell>(cols));

    // Initialize the cells with default values
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cells[i][j].x = i;
            cells[i][j].y = j;
            cells[i][j].g = INT_MAX;
            cells[i][j].h = INT_MAX;
            cells[i][j].f = INT_MAX;
        }
    }

    // Priority queue for open list
    priority_queue<Cell, vector<Cell>, CompareCells> openList;

    // Initialize the start cell
    start.g = 0;
    start.h = abs(start.x - goal.x) + abs(start.y - goal.y);
    start.f = start.g + start.h;

    openList.push(start);

    // A* algorithm
    while (!openList.empty()) {
        // Get the cell with the lowest f value from the open list
        Cell current = openList.top();
        openList.pop();

        // Print current step and h, g, f values
        cout << "Step: (" << current.x << "," << current.y << ") - ";
        cout << "h=" << current.h << ", g=" << current.g << ", f=" << current.f << endl;

        // Check if the current cell is the goal
        if (current.x == goal.x && current.y == goal.y) {
            cout << "Goal reached!" << endl;
            break;
        }

        // Explore the neighbors of the current cell
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int newX = current.x + i;
                int newY = current.y + j;

                // Check if the neighbor is within the grid and not blocked
                if (isValid(newX, newY, rows, cols) && grid[newX][newY] != 1) {
                    int newG = current.g + 1;  // Assuming each step has a cost of 1

                    // Update the cell if it has a lower g value
                    if (newG < cells[newX][newY].g) {
                        cells[newX][newY].g = newG;
                        cells[newX][newY].h = abs(newX - goal.x) + abs(newY - goal.y);
                        cells[newX][newY].f = newG + cells[newX][newY].h;

                        // Add the neighbor to the open list
                        openList.push(cells[newX][newY]);
                    }
                }
            }
        }
    }

    if (openList.empty()) {
        cout << "No path found to the goal." << endl;
    }
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    Cell start = {0, 0, 0, 0, 0};
    Cell goal = {4, 4, 0, 0, 0};

    aStar(grid, start, goal);

    return 0;
}