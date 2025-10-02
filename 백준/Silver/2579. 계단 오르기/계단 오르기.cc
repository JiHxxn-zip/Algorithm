    using namespace std;
    #include <iostream>
    #include <algorithm>
    #include <vector>

    int a[301];
    int b[301];

    int main() 
    {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n{}, tot{};
        cin >> n;

        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
            tot += a[i];
        }

        if (n == 1 || n == 2)
        {
            cout << tot;
            return 0;
        }


        b[0] = a[0];
        b[1] = a[1];
        b[2] = a[2];

        for (size_t i = 3; i < n; i++)
            b[i] = min(b[i-2], b[i-3]) + a[i];

        cout << tot - min(b[n-2], b[n-3]);

        return 0;
    }