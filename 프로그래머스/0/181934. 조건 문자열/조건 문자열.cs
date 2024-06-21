using System;

public class Solution {
    public int solution(string ineq, string eq, int n, int m) {
        int answer = 0;
        bool isEqual = string.Equals("=", eq) ? true: false;

        if(ineq.Equals(">"))
        {
            if(isEqual)
            {
                return answer = n >= m ? 1 : 0;
            }

            return answer = n > m ? 1 : 0;
        }
        else
        {
            if (isEqual)
            {
                return answer = n <= m ? 1 : 0;
            }

            return answer = n < m ? 1 : 0;
        }    
    }
}