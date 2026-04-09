using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    static int[] dx = new int[4] { 0, 0, -1, 1 };
    static int[] dy = new int[4] { 1, -1, 0, 0 };

    static void Main()
    {
        var sr = new StreamReader(Console.OpenStandardInput());

        string[] s = sr.ReadLine().Split();
        int n = int.Parse(s[0]);
        int m = int.Parse(s[1]);

        char[,] board = new char[n, m];
        for (int i = 0; i < board.GetLength(0); ++i)
        {
            string s1 = sr.ReadLine();
            for (int j = 0; j < board.GetLength(1); ++j)
                board[i, j] = s1[j];
        }

        int[,,] dist = new int[n, m, 2];
        Queue<(int y, int x, int broken)> q = new Queue<(int y, int x, int broken)>();
        q.Enqueue((0, 0, 0));
        dist[0, 0, 0] = 1;

        while(q.Count > 0)
        {
            var cur = q.Dequeue(); ;
            int y = cur.y;
            int x = cur.x;
            int broken = cur.broken;

            if(y == n-1 && x == m-1)
            {
                Console.Write(dist[y, x, broken]);
                return;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= m || nx < 0 || ny >= n || ny < 0)
                    continue;

                //  0이고, broken이 0
                if (dist[ny, nx, broken] == 0 && board[ny,nx] == '0')
                {
                    dist[ny, nx, broken] = dist[y, x, broken] + 1;
                    q.Enqueue((ny, nx, broken));
                }

                if(board[ny, nx] == '1' && dist[ny,nx,1] == 0 && broken == 0)
                {
                    dist[ny, nx, 1] = dist[y, x, broken] + 1;
                    q.Enqueue((ny, nx, 1));
                }
            }
        }
        Console.Write("-1");
    }
}

// dist에 3번 째 인자로 broken 원소 추가 (1은 사용, 0은 미사용)
// queue에도 3번 째 인자 추가