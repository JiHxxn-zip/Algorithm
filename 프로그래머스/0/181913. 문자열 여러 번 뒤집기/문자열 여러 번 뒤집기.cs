using System;
using System.Collections.Generic;

public class Solution {
    public string solution(string my_string, int[,] queries) {
        char[] charArray = my_string.ToCharArray();
            for (int i = 0; i < queries.GetLength(0); i++)
            {
                int startIndex = queries[i,0];
                int endIndex = queries[i,1] - queries[i,0] + 1;

                Array.Reverse(charArray, startIndex, endIndex);
            }

            return my_string = new string(charArray);
    }
}