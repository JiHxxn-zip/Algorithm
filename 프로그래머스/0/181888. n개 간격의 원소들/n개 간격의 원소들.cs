using System;

public class Solution {
    public int[] solution(int[] num_list, int n) {
        string a = string.Empty;

            for (int i = 0; i < num_list.Length; i += n)
            {
                a += num_list[i];
            }
            int[] answer = new int[a.Length];

            for (int i = 0; i < a.Length; i++)
            {
                answer[i] = int.Parse(a[i].ToString());
            }
            return answer;
    }
}