#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#define P pair<int, int>
#define F first
#define S second
#define INF 987654321
using namespace std;

int N;

int main(){
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = N; i >= 1; i--){
        for(int j = i; j < N; j++) cout << " ";
        for(int j = 1; j <= i*2-1; j++) cout << "*";
        cout << "\n";
    }
    for(int i = 2; i <= N; i++){
        for(int j = i; j < N; j++) cout << " ";
        for(int j = 1; j <= i*2-1; j++) cout << "*";
        cout << "\n";
    }
    return 0;
}