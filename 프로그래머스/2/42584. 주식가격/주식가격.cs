using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.Length];

        Queue<int> q = new Queue<int>(prices);

        int time = 0;
        int temp = 0;

        for (int i = 0; i < prices.Length; i++)
        {
            time = 0;
            temp = q.Dequeue();

            for (int j = i + 1; j < prices.Length; j++)
            {
                time++;

                if (j == prices.Length - 1 || temp > prices[j])
                {
                    answer[i] = time;
                    break;
                }
            }
        }

        return answer;
    }
}