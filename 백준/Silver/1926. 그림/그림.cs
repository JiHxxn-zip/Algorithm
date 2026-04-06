using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;

class program
{
   
    static void Main()
    {
        int[] dx = new int[4] { 0, 0, -1, 1 };
        int[] dy = new int[4] { -1, 1, 0, 0 };

        var sr = new StreamReader(Console.OpenStandardInput());

        string[] s = sr.ReadLine().Split();
        int n = int.Parse(s[0]); 
        int m = int.Parse(s[1]); 

        int[,] board = new int[n,m];

        for (int i = 0; i < n; i++)
        {
            string[] input = sr.ReadLine().Split();
            for (int j = 0; j < m; j++)
                board[i, j] = int.Parse(input[j]);
        }

        List<List<bool>> vis = new List<List<bool>>();

        for (int i = 0; i < n; i++)
        {
            List<bool> row = new List<bool>();
            for (int j = 0; j < m; j++)
                row.Add(false);

            vis.Add(row);
        }

        int count = 0;
        int pMx = 0;
        Queue<(int x, int y)> q = new Queue<(int x, int y)>();        
        // 전수 검사
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == true || board[i, j] == 0)
                    continue;

                count++;
                int mx = 0;

                q.Enqueue((i, j));
                vis[i][j] = true;

                while (q.Count > 0)
                {
                    var cur = q.Dequeue();
                    mx++;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = dx[k] + cur.y;
                        int ny = dy[k] + cur.x;

                        if (nx >= m || nx < 0 || ny >= n || ny < 0)
                            continue;

                        if (board[ny, nx] == 0 || vis[ny][nx])
                            continue;

                        q.Enqueue((ny, nx));
                        vis[ny][nx] = true;
                    }
                }
                pMx = Math.Max(pMx, mx);
            }
        }

        Console.WriteLine(count);
        Console.WriteLine(pMx);
    }
}

