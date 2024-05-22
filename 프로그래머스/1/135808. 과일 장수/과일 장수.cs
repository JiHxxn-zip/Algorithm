using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int k, int m, int[] score) {
        int answer = 0;
        score = score.OrderByDescending(c => c).ToArray();

        Queue<int> queue = new Queue<int>();

        for (int i = 0; i < score.Length; i++)
        {
            queue.Enqueue(score[i]);
        }

        int loopCount = score.Length / m;

        List<int> box;
        for (int i = 0; i < loopCount; i++)
        {
            box = new List<int>();

            for (int j = 0; j < m; j++)
            {
                box.Add(queue.Dequeue());
            }

            answer += box.Min() * m;
        }

        return answer;
    }
}