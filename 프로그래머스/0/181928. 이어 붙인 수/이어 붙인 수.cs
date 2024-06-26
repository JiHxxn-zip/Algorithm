using System;

public class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
            string a = string.Empty;
            string b = string.Empty;

            for (int i = 0; i < num_list.Length; i++)
            {
                if(num_list[i] % 2 == 0)
                {
                    a += num_list[i].ToString();
                }
                else
                {
                    b += num_list[i].ToString();
                }
            }

            return answer = int.Parse(a) + int.Parse(b);
    }
}