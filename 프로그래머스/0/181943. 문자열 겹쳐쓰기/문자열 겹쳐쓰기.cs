using System;

public class Solution {
    public string solution(string my_string, string overwrite_string, int s) {
        string answer = "";
            string str = my_string.Substring(0, s);
            string ostr = my_string.Substring(s + overwrite_string.Length);
            answer = str + overwrite_string + ostr;


        return answer;
    }
}