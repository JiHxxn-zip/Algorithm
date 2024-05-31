using System;
using System.Collections.Generic;

class Solution
{
    public int[] solution(int n, string[] words)
    {
        int[] answer = new int[2];

            // 리스트로 첫번째 인덱스를 저장
            List<string> list = new List<string>();
            list.Add(words[0]);

            int count = 1;
            int round = 1;

            // 인덱스 1부터 시작하여 뒷글자와 앞글자 비교
            for (int i = 1; i < words.Length; i++)
            {
                count = count != n ? count + 1 : 1;
                round = count == 1 ? round + 1 : round;

                char last = words[i - 1][words[i - 1].Length -1];
                char first = words[i][0];

                // 정답이라면
                if(last == first && !list.Contains(words[i]))
                {

                    list.Add(words[i]);
                }
                else
                {
                    answer[0] = count;
                    answer[1] = round;
                    break;
                }
            }

            return answer;
    }
}