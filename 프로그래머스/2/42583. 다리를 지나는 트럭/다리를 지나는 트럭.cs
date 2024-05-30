using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<int> queue = new Queue<int>();
        int truckCount = 0;
        int sumWeight = 0;
        int time = 0;

        while (true)
        {
            // 트럭이 모두 다리에 올라왔다면 반복문 종료
            if (truckCount == truck_weights.Length) break;

            // queue가 가득 찼다면 처음 담아둔 트럭이 다 건넜다는 뜻
            if (queue.Count == bridge_length) sumWeight -= queue.Dequeue();

            // 현재 더 해진 값과 다음 트럭 값의 합이 다리의 무게 보다 같거나 작으면 더 해줌.
            if(sumWeight + truck_weights[truckCount] <= weight)
            {
                sumWeight += truck_weights[truckCount];
                queue.Enqueue(truck_weights[truckCount]);
                truckCount++;
            }
            else
            {
                // 무게가 넘었다면 0을 담아줌.
                queue.Enqueue(0);
            }

            // 건넌 시간 체크
            time++;
        }

        // 트럭이 다 올라온 시점에 반복문이 끊겼기 때문에 마지막 트럭이 건넌 시간은 다리 길이를 더 해주면 됨.
        time += bridge_length;

        return time;
    }
}