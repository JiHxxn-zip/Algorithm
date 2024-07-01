using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr, int[,] queries) {
        int[] answer = new int[queries.GetLength(0)];

        for (int i = 0; i < queries.GetLength(0); i++)
        {
            List<int> tempList = null;

            for (int j = 0; j < arr.Length; j++)
            {
                if(queries[i,0] > j || j > queries[i,1])
                {
                    continue;
                }

                if(arr[j] > queries[i,2])
                {
                    if (tempList == null)
                    {
                        tempList = new List<int>();
                    }

                    tempList.Add(arr[j]);
                }
            }

            if (tempList == null)
            {
                answer[i] = -1;
            }
            else
            {
                answer[i] = tempList.Min();
            }
        }

        return answer;
    }
}