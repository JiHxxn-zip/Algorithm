using System;
using System.Linq;

public class Solution {
    public string solution(string my_string, int[] index_list) {
        string answer = "";

        char[] strArray = my_string.ToArray();

        for (int i = 0; i < index_list.Length; i++)
        {
            answer += strArray[index_list[i]];
        }

        return answer;
    }
}