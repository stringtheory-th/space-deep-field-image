/*
TASK: space.cpp
LANG: C++
AUTHOR: Yongyuth Chuankhuntod
CENTER: NO (I'm not a computer olympic racer.)
*/
#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1010][1010];
int mem[1010][1010];
char keep[1010][1010];
queue<array<int, 2>> q;
int go[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", keep[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = keep[i][j] - '0';
        }
    }
    int sq = 0, lam = 0, tri = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int ind = 0;
            int min_x = INT_MAX, min_y = INT_MAX, max_x = 0, max_y = 0;
            if (arr[i][j] && !mem[i][j])
            {
                mem[i][j] = 1;
                q.push({i, j});
                ind++;
                while (!q.empty())
                {
                    int y = q.front()[0];
                    int x = q.front()[1];
                    min_x = min(min_x, x);
                    max_x = max(max_x, x);
                    min_y = min(min_y, y);
                    max_y = max(max_y, y);
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int fy = y + go[k][0];
                        int fx = x + go[k][1];
                        if (fy >= 0 && fy < n && fx >= 0 && fx < m && arr[fy][fx] && !mem[fy][fx])
                        {
                            mem[fy][fx] = 1;
                            ind++;
                            q.push({fy, fx});
                        }
                    }
                }
                int len_x = abs(min_x - max_x) + 1;
                int len_y = abs(min_y - max_y) + 1;
                if (len_y == len_x && len_y * len_x == ind)
                    sq++;
                else if (len_y == len_x)
                    lam++;
                else if (len_y != len_x)
                    tri++;
            }
        }
    }
    printf("%d %d %d", sq, lam, tri);
}
