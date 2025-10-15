using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, l;
    cin >> k >> l;

    unordered_map<string, int> wating_list;
    int cnt{};
    string studentID{};
    while (l--)
    {
        cin >> studentID;
        wating_list[studentID] = cnt;
        cnt++;
    }

    vector<pair<int, string>>result_list;
    for (auto st : wating_list)
        result_list.push_back({st.second, st.first});

    sort(result_list.begin(), result_list.end());

    for (int i = 0; i < k && i < result_list.size(); i++) 
        cout << result_list[i].second << "\n";

    return 0;
}