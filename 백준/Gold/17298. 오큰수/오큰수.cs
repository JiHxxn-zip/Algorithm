using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] nums = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

            StringBuilder sb = new StringBuilder();

            Stack<(int, int)> stack = new Stack<(int, int)>();

            int[] answerArray = new int[n];

            for (int i = 0; i < n; i++)
            {
                while (stack.Count > 0 && (stack.Peek().Item1 < nums[i]))
                {
                    answerArray[stack.Peek().Item2] = nums[i];
                    stack.Pop();
                }

                stack.Push((nums[i], i));
            }

            while(stack.Count > 0)
            {
                answerArray[stack.Peek().Item2] = -1;
                stack.Pop();
            }

            answerArray[n - 1] = -1;

            foreach (int answer in answerArray)
            {
                sb.Append(answer + " ");
            }

            Console.WriteLine(sb);
        }
    }
}