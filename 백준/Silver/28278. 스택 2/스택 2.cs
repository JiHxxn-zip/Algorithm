using System;
using System.Collections.Generic;
using System.Text;

class Program
    {
        static void Main(string[] args)
        {
            int index = int.Parse(Console.ReadLine());

            Stack<string> stack = new Stack<string>();
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < index; i++)
            {
                string[] temp = Console.ReadLine().Split();

                switch (temp[0])
                {
                    case "1":
                        stack.Push(temp[1]);
                        break;

                    case "2":
                        if (stack.Count > 0)
                            sb.Append(stack.Pop() + "\n");
                        else
                            sb.Append("-1" + "\n");
                        break;

                    case "3":
                        sb.Append(stack.Count + "\n");
                        break;

                    case "4":
                        if (stack.Count == 0)
                            sb.Append("1" + "\n");
                        else
                            sb.Append("0" + "\n");
                        break;

                    case "5":
                        if (stack.Count > 0)
                            sb.Append(stack.Peek() + "\n");
                        else
                            sb.Append("-1" + "\n");
                        break;

                }
            }
            Console.WriteLine(sb);
        }
}