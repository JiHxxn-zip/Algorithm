using System;
using System.Collections.Generic;

class Solution {
    public int solution(int[,] maps) {
         int answer = -1;

        int yy = maps.GetLength(0);
        int xx = maps.GetLength(1);

        bool[,] visited = new bool[yy, xx];
        visited[0, 0] = true;

        // 큐에 [x, y, 현재 깊이] 저장
        Queue<(int x, int y, int v)> q = new Queue<(int, int, int)>();

        q.Enqueue((0, 0, 1));

        int currentX = 0;
        int currentY = 0;
        int visitedDepth = 0;

        int[] dx = new int[4] { 0, 0, 1, -1 };
        int[] dy = new int[4] { -1, 1, 0, 0 };

        while (q.Count != 0)
        {
            var currentLocation = q.Dequeue();
            currentY = currentLocation.Item1;
            currentX = currentLocation.Item2;
            visitedDepth = currentLocation.Item3;

            if (currentY == yy -1 && currentX == xx -1)
            {
                return visitedDepth;
            }

            for (int i = 0; i < dx.Length; i++)
            {
                // 상하좌우 값 구하기
                int nextX = currentX + dx[i];
                int nextY = currentY + dy[i];

                // 맵을 벗어나면 continue
                if (nextX < 0 || nextX >= xx || nextY < 0 || nextY >= yy)
                    continue;

                if (visited[nextY, nextX] == false && maps[nextY, nextX] == 1)
                {
                    visited[nextY, nextX] = true;
                    q.Enqueue((nextY, nextX, visitedDepth + 1));
                }
            }
        }

        return answer;
    }
}