using System;

public class Solution {
        public int solution(int a, int d, bool[] included) {
            int answer = included[0] == true ? a : 0;
            int sum = a;

            for (int i = 1; i < included.Length; i++)
            {
                sum += d;

                answer = included[i] == true ? answer += sum : answer;
            }
            return answer;
        }
}