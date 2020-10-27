#include <iostream>
#include <queue>

#define row 3
#define col 3

bool isPath(char (&grid)[row][col])
{
    const int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int a, b, i;
    std::queue<std::pair<int,int>> q;
    q.push({0,0});

    while(q.size() > 0) {
        grid[q.front().first][q.front().second] = 'W';

        if(q.front() == std::make_pair(row - 1,col - 1)) return true;

        for(i = 0; i < 4 ;i++) {
            a = q.front().first + dir[i][0];
            b = q.front().second + dir[i][1];
            if(grid[a][b] != 'W' && 0 <= a && a < row && 0 <= b && b < col) q.push({a,b});
        }
        q.pop();
    }
    return false;
}

int main()
{
    char grid[row][col] = {{ '.', 'W', '.'},
                           { '.', 'W', '.'},
                           { '.', '.', '.'},};

    if(isPath(grid))
        printf("Yes\n");
    else
        printf("No\n");
}
