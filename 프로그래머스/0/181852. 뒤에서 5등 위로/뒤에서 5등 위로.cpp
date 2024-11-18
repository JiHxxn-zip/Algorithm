#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    sort(num_list.begin(), num_list.end());
    num_list.erase(num_list.begin(), num_list.begin()+5);
  
    return num_list;
}