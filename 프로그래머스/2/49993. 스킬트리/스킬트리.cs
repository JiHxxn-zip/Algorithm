using System;
using System.Linq;

public class Solution {
    public int solution(string skill, string[] skill_trees) {
        int answer = 0;
        
        for (int i = 0; i < skill_trees.Length; i++)
            {
                bool flag = false;

                string result = new string(skill_trees[i].Where(c => skill.Contains(c)).ToArray());

                for (int j = 0; j < result.Length; j++)
                {
                    if (skill[j] != result[j])
                    {
                        flag = true;
                        break;
                    }
                }

                if (flag == false)
                {
                    answer++;
                }
            }
        
        return answer;
    }
}