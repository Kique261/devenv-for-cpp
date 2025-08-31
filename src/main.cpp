#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <map>
#include <set>
using namespace std;

ifstream fin("in");
ofstream fout("out");

struct IOInitializer
{
    IOInitializer()
    {
        if (fin.is_open())
            cin.rdbuf(fin.rdbuf());
        if (fout.is_open())
            cout.rdbuf(fout.rdbuf());
    }
    ~IOInitializer()
    {
        if (fin.is_open())
            fin.close();
        if (fout.is_open())
            fout.close();
    }
} io_initializer;

vector<pair<int, int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

void dfs(int x, int y, vector<vector<int>>& edges, vector<vector<int>>& memory)
{
    if (memory[x][y] == 1)
        return;
    int n = edges.size();
    int m = edges[0].size();
    if (edges[x][y] == 1)
    {
        memory[x][y] = 1;
    }
    else
    {
        memory[x][y] = 2;
        return;
    }
    for (auto [dx, dy] : dirs)
    {
        int nx = x + dx;
        int ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || memory[nx][ny] == 1 || memory[nx][ny] == 2)
            continue;
        dfs(nx, ny, edges, memory);
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grip(n, vector<int>(m, 0));
    auto edges = grip;
    auto memory = grip;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grip[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grip[i][j] == 5)
            {
                for (auto [dx, dy] : dirs)
                {
                    int nx = i + dx;
                    int ny = j + dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || grip[nx][ny] == 5 || edges[nx][ny] == 1)
                    {
                        continue;
                    }
                    edges[nx][ny] = 1;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (edges[i][j] == 1 && memory[i][j] == 0)
            {
                res++;
                dfs(i, j, edges, memory);
            }
        }
    }
    cout << res;
}
