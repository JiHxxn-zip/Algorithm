using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int a, int b, int c, int d) {
        List<int> answerList = new List<int>() { a, b, c, d };

        int maxValue = answerList.Max();
        int minValue = answerList.Min();

        int maxCount = 0;
        int minCount = 0;

        // 
        for (int i = 0; i < answerList.Count; i++)
        {
            if(answerList[i] == maxValue)
            {
                maxCount++;
            }
            else if(answerList[i] == minValue)
            {
                minCount++;
            }
        }

        // 4자리 모두 같을 경우
        if(maxCount == answerList.Count || minCount == answerList.Count)
        {
            return answerList[0] * 1111;
        }

        // 3자리만 같을 경우
        if(maxCount == answerList.Count - 1)
        {
            return (int)Math.Pow((maxValue * 10 + minValue), 2);
        }
        else if (minCount == answerList.Count - 1)
        {
            return (int)Math.Pow((minValue * 10 + maxValue), 2);
        }

        // 2개씩 같을 경우
        if(maxCount == answerList.Count - 2 && minCount == answerList.Count - 2)
        {
            return (maxValue + minValue) * (maxValue - minValue);
        }

        // 2개가 같고 나머지는 다른 경우
        if (a == b)
        {
            return c * d;
        }
        if (a == c)
        {
            return b * d;
        }
        if (a == d)
        {
            return b * c;
        }
        if (b == c)
        {
            return a * d;
        }
        if (b == d)
        {
            return a * c;
        }
        if (c == d)
        {
            return a * b;
        }

        // 4자리 다 다른경우
        return minValue;
    }
}