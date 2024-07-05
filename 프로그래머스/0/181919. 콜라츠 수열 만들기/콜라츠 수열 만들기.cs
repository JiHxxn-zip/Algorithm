using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int n) {
        List<int> answerList = new List<int>();
        answerList.Add(n);
        
        while(n != 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else
            {
                n = n * 3 + 1;
            }
            answerList.Add(n);
        }

        return answerList.ToArray();
    }
}