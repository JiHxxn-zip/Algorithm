using System;

public class Solution {
    public int solution(int a, int b) {
        int ee = int.Parse($"{a}{b}");
                int ee3 = int.Parse($"{b}{a}");
                int answer = ee > ee3 ? ee : ee3;
        return answer;
    }
}