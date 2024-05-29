using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;

        int max = priorities.Max();
        while (true)
        {
            for (int i = 0; i < priorities.Length; i++)
            {
                if(max == priorities[i])
                {
                    answer++;

                    if(location == i)
                    {
                        return answer;
                    }

                    priorities[i] = 0;
                    max = priorities.Max();
                }
            }
        }
    }
}