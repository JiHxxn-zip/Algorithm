#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int solution(vector<int> array) {
    int answer = 0;
    
    sort(array.begin(), array.end());
 
    // 최빈값이 들어갈 vector
    vector<int> numbers;
    
    // 최대로 나온 갯수 count
    // 최빈값 max
    // 이전 값 temp
    int count = 0, max = 0, temp;
    for(int i = 0; i < array.size(); i++)
    {
        // i == 0 일때는 저장만 한다.
        if (i == 0)
        {   
            temp = array[i];
            count = 1, max = 1;
            numbers.push_back(array[i]);
        }
        // 그 이외에는
        else
        {
            // 이전 값과 현재 값이 같다면 count++
            if(temp == array[i]) count++;
            // 다르다면 temp를 바꾸고 count = 1
            else 
            {
                temp = array[i];
                count = 1;
            }
            
            // 만약 최빈값이 갱신된다면 numbers를 비우고
            // max를 갱신한 뒤, numbers에 해당 값을 넣어준다.
            if (max < count)
            {
                numbers.clear();
                numbers.push_back(array[i]);
                max = count;
            }
            // 동일한 최빈값이 있다면 numbers에 최빈값을 넣어준다.
            else if (max == count)
            {
                numbers.push_back(array[i]);
            }
        }
    }
    
    if (numbers.size() == 1)
    {
        return numbers[0];
    }
    else return -1;
}