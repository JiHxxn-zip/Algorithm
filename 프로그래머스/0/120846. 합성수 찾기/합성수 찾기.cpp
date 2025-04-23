#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=4;i<=n;i++)
    {
        // i가 합성수인지 판단
        int cnt=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)cnt++;
        }
        if(cnt>=3)answer++;
    }
    
    return answer;
}