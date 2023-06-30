#include <bits/stdc++.h> 
using namespace std; 
  
#define int long long 
#define endl '\n' 
  
signed main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
  
    auto (get_mex = &) 
{       int n = a.size(); 
        vector<int> b(n); 
        for (auto &i : a) 
        { 
            if (i < n) 
                b[i]++; 
        } 
        int mex = 0; 
        while (mex < n && b[mex]) 
            mex++; 
        return mex; 
    }
  
    int t = 1; 
    cin >> t; 
    while (t--) 
    { 
        int n; 
        cin >> n; 
        vector<int> a(n), b(n); 
        for (auto &i : a) 
            cin >> i; 
  
        int mex = get_mex(a); 
        if (mex == n) 
        { 
            cout << "No" << endl; 
            continue; 
        } 
  
        vector<int> to_rem; 
        if (find(a.begin(), a.end(), mex + 1) != a.end()) 
        { 
            for (int i = 0; i < n; i++) 
            { 
                if (a[i] == mex + 1) 
                    to_rem.push_back(i); 
            } 
  
            for (int i = to_rem.front(); i <= to_rem.back(); i++) 
                a[i] = mex; 
  
            if (get_mex(a) == mex + 1) 
                cout << "Yes" << endl; 
            else 
                cout << "No" << endl; 
        } 
        else 
            cout << "Yes" << endl; 
    }; 
}}