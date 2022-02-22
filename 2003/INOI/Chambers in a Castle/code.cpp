#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define pf push_front
#define fi first
#define se second

int a = 2;
vector<int> dict;

vector<vector<int>> recursiveFill(int i, int j, vector<vector<int>> array, bool isRoot) {
    array[i][j] = a;
    if (array[i+1][j] == 0) {
        array = recursiveFill(i+1, j, array, false);
        if (dict.size() == a-1) {
            dict[a-2] += 1;
        } else {
            dict.pb(1);
        }
    }
    if (array[i-1][j] == 0) {
        array = recursiveFill(i-1, j, array, false);
        if (dict.size() == a-1) {
            dict[a-2] += 1;
        } else {
            dict.pb(1);
        }
    }
    if (array[i][j+1] == 0) {
        array = recursiveFill(i, j+1, array, false);
        if (dict.size() == a-1) {
            dict[a-2] += 1;
        } else {
            dict.pb(1);
        }
    }
    if (array[i][j-1] == 0) {
        array = recursiveFill(i, j-1, array, false);
        if (dict.size() == a-1) {
            dict[a-2] += 1;
        } else {
            dict.pb(1);
        }
    }
    if (isRoot==true) {
        a += 1;
    } 
    return array;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int m,n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                arr = recursiveFill(i, j, arr, true);
            }
        }
    }

    cout << dict.size() << endl << *max_element(dict.begin(), dict.end()) + 1;
}