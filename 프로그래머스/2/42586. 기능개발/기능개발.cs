using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Queue<int> queue = new Queue<int>();
        List<int> answerList = new List<int>();

        for (int i = 0; i < progresses.Length; i++)
        {
            // 며칠이 걸리는지 계산
            int day = 100 - progresses[i];
            int remainder = day % speeds[i];
            day /= speeds[i];

            if(remainder != 0)
            {
                day++;
            }

            queue.Enqueue(day);
        }

        while (queue.Count != 0)
        {
            int currentValue = queue.Dequeue();
            int point = 1;

            while(queue.Count != 0 && currentValue >= queue.Peek())
            {
                point++;
                queue.Dequeue();
            }

            answerList.Add(point);
        }

        return answerList.ToArray();
    }
}