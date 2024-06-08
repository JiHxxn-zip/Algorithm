using System;

public class Example
{
    public static void Main()
    {
        String s;

        Console.Clear();
        s = Console.ReadLine();

        foreach(var a in s)
        {
            Console.WriteLine(a);
        }

    }
}