#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> input;
    int temp;

    for(int i = 0; i < 3; i++){
        int num = 0;
        cin >> num;
        input.push_back(num);
    }

    sort(input.begin(), input.end());

    for(int i = 0; i < 3; i++){
        cout << input[i] << " " ;
    }
}