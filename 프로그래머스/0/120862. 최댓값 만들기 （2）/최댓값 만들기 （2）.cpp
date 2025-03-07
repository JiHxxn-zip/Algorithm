#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int solution(vector<int> numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());    
    
    answer = max(numbers[0] * numbers[1], *(numbers.end() - 1) * *(numbers.end() - 2) );
    return answer;
}
