using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cctype> 
#include <iomanip>

typedef long long ll;

bool canMake(ll S, const vector<ll>& L, const vector<ll>& R, ll sumL, ll T)
{
    ll sumU = 0;
    int N = L.size();

    for (int i = 0; i < N; i++) 
    {
        sumU += min(R[i], S);
        if (sumU >= T) 
            break;
    }

    return (sumL <= T && T <= sumU);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    ll T;
    cin >> N >> T;

    vector<ll> L(N), R(N);

    ll sumL = 0, sumR = 0;
    ll maxL = 0, maxR = 0;

    for (int i = 0; i < N; i++) 
    {
        cin >> L[i] >> R[i];
        sumL += L[i];
        sumR += R[i];
        maxL = max(maxL, L[i]);
        maxR = max(maxR, R[i]);
    }

    // 아예 불가능한 경우
    if (sumL > T || sumR < T) 
    {
        cout << -1;
        return 0;
    }

    // 이분 탐색
    ll left = maxL;
    ll right = maxR;
    ll answer = maxR;

    while (left <= right) 
    {
        ll mid = (left + right) / 2;

        if (canMake(mid, L, R, sumL, T)) 
        {
            answer = mid;
            right = mid - 1;
        }
        else 
            left = mid + 1;
    }

    cout << answer;

    return 0;
}