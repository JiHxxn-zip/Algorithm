using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    public enum EClassT
    {
        B = 0,
        S = 1,
        G = 2,
        P = 3,
        D = 4
    }

    static void Main()
    {
        var sr = new StreamReader(Console.OpenStandardInput());

        string s = sr.ReadLine();
        int n = int.Parse(s);

        string[] t = sr.ReadLine().Split();

        string[] sorted = (string[])t.Clone();
        Array.Sort(sorted, Compare);

        int first = -1;
        int second = -1;

        for (int i = 0; i < n; i++)
        {
            if (t[i] != sorted[i])
            {
                if (first == -1) 
                    first = i;
                else 
                    second = i;
            }
        }

        if (first == -1)
            Console.WriteLine("OK");
        else
        {
            Console.WriteLine("KO");
            Console.WriteLine(sorted[first] + " " + sorted[second]);
        }
    }

    static EClassT GetTier(char c)
    {
        switch (c)
        {
            case 'B': 
                return EClassT.B;
            case 'S': 
                return EClassT.S;
            case 'G': 
                return EClassT.G;
            case 'P': 
                return EClassT.P;
            case 'D': 
                return EClassT.D;
            default: 
                throw new ArgumentException();
        }
    }

    static int Compare(string a, string b)
    {
        EClassT ea = GetTier(a[0]);
        EClassT eb = GetTier(b[0]);

        if (ea != eb)
            return ea.CompareTo(eb);

        int na = int.Parse(a.Substring(1));
        int nb = int.Parse(b.Substring(1));

        return nb.CompareTo(na);
    }
}
// 정렬 문제
// 앞자리 문자와 뒷자리 숫자 를 나눠 비교