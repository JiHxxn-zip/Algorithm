using System;

public class Solution {
    public bool solution(bool x1, bool x2, bool x3, bool x4) {
        bool answer = true;

            bool temp1 = x1 || x2 ? true : false;
            bool temp2 = x3 || x4 ? true : false;

            return answer = temp1 && temp2 ? true : false;
    }
}