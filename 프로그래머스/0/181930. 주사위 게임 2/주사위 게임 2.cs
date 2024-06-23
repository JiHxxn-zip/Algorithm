using System;

public class Solution {
    public int solution(int a, int b, int c) {
        int answer = 0;
            if (a == b && b == c)
            {
                answer = (a + b + c) * ((int)(Math.Pow(a, 2) + Math.Pow(b, 2) + Math.Pow(c, 2)) * ((int)(Math.Pow(a, 3) + Math.Pow(b, 3) + Math.Pow(c, 3))));
                return answer;
            }
            else if (a == b || a == c || b == c)
            {
                answer = (a + b + c) * (int)(Math.Pow(a, 2) + Math.Pow(b, 2) + Math.Pow(c, 2));
                return answer;
            }
            else
            {
                answer = a + b + c;
                return answer;
            }
    }
}