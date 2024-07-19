using System;

public class Solution {
    public int[] solution(int[] num_list) {
        
        int[] a = new int[num_list.Length - 5];
        Array.Sort(num_list);
        
        for (int i = 5; i < num_list.Length; i++)
        {
            a[i - 5] = num_list[i];

        }
        
        return a;
    }
}