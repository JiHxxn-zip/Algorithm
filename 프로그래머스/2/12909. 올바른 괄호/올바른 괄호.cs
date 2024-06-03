using System;
using System.Collections.Generic;

public class Solution {
    public bool solution(string s) {
        Stack<char> stack = new Stack<char>();

        for (int i = 0; i < s.Length; i++)
        {
            if (s[i].Equals('('))
            {
                stack.Push(s[i]);
                continue;
            }

            if(s[i].Equals(')'))
            {
                if(stack.Count == 0 || stack.Peek() == ')')
                {
                    return false;
                }

                stack.Pop();
            }
        }

        return stack.Count == 0;
    }
}