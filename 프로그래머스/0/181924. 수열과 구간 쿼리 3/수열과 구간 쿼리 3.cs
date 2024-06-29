using System;

public class Solution {
    public int[] solution(int[] arr, int[,] queries) {
        int temp = 0;

            for (int i = 0; i < queries.GetLength(0); i++)
            {
                for (int j = 0; j < arr.Length; j++)
                {
                    if (queries[i,0] == j)
                    {
                        temp = arr[j];

                        arr[j] = arr[queries[i, 1]];
                    }
                    else if (queries[i, 1] == j)
                    {
                        arr[j] = temp;
                    }
                }
            }
            return arr;
    }
}