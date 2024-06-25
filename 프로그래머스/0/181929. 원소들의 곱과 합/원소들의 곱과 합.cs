using System;
using System.Linq;

public class Solution {
    public int solution(int[] num_list) {
        int answer = 0;

        int sum = num_list[0];
        int pow = (int)Math.Pow(num_list.Sum(),2);

        for (int i = 1; i < num_list.Length; i++)
        {
            sum *= num_list[i];
        }

        return answer = sum > pow ? 0 : 1;
    }
}