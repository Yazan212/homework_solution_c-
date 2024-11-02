

#include <iostream>

int main()
{
    int n, m, head[100], head_size;
    int mat[100][100];
    bool mat_vis[100][100];

    std::cout << "Enter the values of m, n :"; std::cin >> m >> n;

    std::cout << "Enter the total number of integers in the linked list: ";
    std::cin >> head_size;

    std::cout << "Enter the values of the integers in the linked list: ";
    for (int i = 0; i < head_size; ++i)
    {
        std::cin >> head[i];
    }

    int x = 0, y = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int cnt = 0;

    for (int i = 0; i < head_size; i++)
    {
        if (mat_vis[x][y] == false && x >= 0 && x < m && y >= 0 && y < n)
        {
            mat[x][y] = head[i];
            mat_vis[x][y] = true;

            x += dx[cnt];
            y += dy[cnt];
        }
        else
        {
            x -= dx[cnt];
            y -= dy[cnt];

            cnt++;
            cnt %= 4;

            x += dx[cnt];
            y += dy[cnt];

            i--;
        }
    }

    std::cout << "The output matrix is:\n";
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (mat_vis[i][j] == false)
            {
                std::cout << -1 << " ";
            }
            else
            {
                std::cout << mat[i][j] << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
