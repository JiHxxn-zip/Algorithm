using System;
using System.Collections.Generic;
using System.IO;

class Program
{
    static readonly int[] dy4 = { -1, 1, 0, 0 };
    static readonly int[] dx4 = { 0, 0, -1, 1 };

    static readonly int[] dy8 = { -2, -2, -1, -1, 1, 1, 2, 2 };
    static readonly int[] dx8 = { -1, 1, -2, 2, -2, 2, -1, 1 };

    static void Main()
    {
        var sr = new StreamReader(Console.OpenStandardInput());

        int K = int.Parse(sr.ReadLine());
        string[] input = sr.ReadLine().Split();
        int W = int.Parse(input[0]);
        int H = int.Parse(input[1]);

        int[,] board = new int[H, W];
        for (int i = 0; i < H; i++)
        {
            string[] line = sr.ReadLine().Split();
            for (int j = 0; j < W; j++)
            {
                board[i, j] = int.Parse(line[j]);
            }
        }

        int[,,] dist = new int[H, W, K + 1];

        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                for (int k = 0; k <= K; k++)
                {
                    dist[y, x, k] = -1;
                }
            }
        }

        Queue<(int y, int x, int used)> q = new Queue<(int y, int x, int used)>();
        q.Enqueue((0, 0, 0));
        dist[0, 0, 0] = 0;

        while (q.Count > 0)
        {
            var cur = q.Dequeue();
            int y = cur.y;
            int x = cur.x;
            int used = cur.used;

            if (y == H - 1 && x == W - 1)
            {
                Console.WriteLine(dist[y, x, used]);
                return;
            }

            // 원숭이 이동 4방향
            for (int dir = 0; dir < 4; dir++)
            {
                int ny = y + dy4[dir];
                int nx = x + dx4[dir];

                if (ny < 0 || ny >= H || nx < 0 || nx >= W)
                    continue;
                if (board[ny, nx] == 1)
                    continue;
                if (dist[ny, nx, used] != -1)
                    continue;

                dist[ny, nx, used] = dist[y, x, used] + 1;
                q.Enqueue((ny, nx, used));
            }

            // 말 이동 8방향
            if (used < K)
            {
                for (int dir = 0; dir < 8; dir++)
                {
                    int ny = y + dy8[dir];
                    int nx = x + dx8[dir];
                    int nextUsed = used + 1;

                    if (ny < 0 || ny >= H || nx < 0 || nx >= W)
                        continue;
                    if (board[ny, nx] == 1)
                        continue;
                    if (dist[ny, nx, nextUsed] != -1)
                        continue;

                    dist[ny, nx, nextUsed] = dist[y, x, used] + 1;
                    q.Enqueue((ny, nx, nextUsed));
                }
            }
        }

        Console.WriteLine(-1);
    }
}