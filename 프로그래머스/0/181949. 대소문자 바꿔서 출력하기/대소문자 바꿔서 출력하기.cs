using System;

public class Example
{
    public static void Main()
    {
        String s;
        string x = string.Empty;

        Console.Clear();
        s = Console.ReadLine();

        for (int i = 0; i < s.Length; i++)
        {
            if (char.IsLower(s[i]))
            {
                x += char.ToUpper(s[i]);
            }
            else
            {
                x += char.ToLower(s[i]);
            }
        }
            Console.Write(x);

    }
}