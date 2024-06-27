using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] num_list) {
       List<int> a = num_list.ToList();
        int lastNum = num_list[num_list.Length - 1];
        int prvNum = num_list[num_list.Length - 2];

        if(lastNum > prvNum)
        {
            a.Add(lastNum - prvNum);
        }
        else
        {
            a.Add(lastNum * 2);
        }

        return num_list = a.ToArray();
    }
}