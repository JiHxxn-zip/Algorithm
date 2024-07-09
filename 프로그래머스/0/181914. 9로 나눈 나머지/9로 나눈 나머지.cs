using System;

public class Solution {
    public int solution(string number) {
        int add = 0;

        for (int i = 0; i < number.Length; i++)
        {
            add += int.Parse(number[i].ToString());
        }

        return add % 9;
    }
}