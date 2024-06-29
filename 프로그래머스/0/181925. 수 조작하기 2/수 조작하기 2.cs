using System;

public class Solution {
    public string solution(int[] numLog) {
         string answer = "";

        for (int i = 1; i < numLog.Length; i++)
        {
            if(numLog[i]  == numLog[i-1] + 1)
            {
                answer += 'w';
            }
            else if (numLog[i] + 1 == numLog[i - 1])
            {
                answer += 's';
            }
            else if(numLog[i] == numLog[i - 1] + 10)
            {
                answer += 'd';
            }
            else if (numLog[i] + 10 == numLog[i - 1] )
            {
                answer += 'a';
            }

        }
        return answer;
    }
}