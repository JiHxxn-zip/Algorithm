using System;
using System.Collections;

public class Solution {
    public string[] solution(string[] players, string[] callings) {
        Hashtable hash = new Hashtable();

            for (int i = 0; i < players.Length; i++)
            {
                hash.Add(players[i] , i);
            }

            for (int i = 0; i < callings.Length; i++)
            {
                // 해당 인덱스 꺼냄
                int a = (int)hash[callings[i]];

                // 저장, 스왑
                string temp = players[a];
                players[a] = players[a - 1];
                players[a - 1] = temp;

                hash.Remove(players[a]);
                hash.Remove(players[a - 1]);

                hash.Add(players[a], a);
                hash.Add(players[a - 1], a - 1);

            }

            return players;
    }
}