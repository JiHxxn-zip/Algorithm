using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int start_num, int end_num) {
        List<int> answerList = new List<int>();

        for (int i = start_num; i <= end_num; i++)
        {
            answerList.Add(i);
        }

        return answerList.ToArray();
    }
}