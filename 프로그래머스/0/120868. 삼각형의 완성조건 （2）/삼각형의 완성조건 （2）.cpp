#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> v)
{
    if(v[0] < v[1])
        swap(v[0],v[1]);
    return v[1] * 2 - 1;
}