using System;

public class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        
        string c = $"{a}{b}";
        
        answer = int.Parse(c) > 2*a*b ? int.Parse(c) : 2*a*b;
        
        return answer;
    }
}