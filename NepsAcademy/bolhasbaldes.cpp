#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);

#define ll long long

#define MAXN 100010

ll inv(vector<int> &v){
    int k = v.size();

    if(k == 1) return 0;

    vector<int> v1, v2;

    fr(i, k/2) v1.pb(v[i]);
    for(int i = k/2; i < k; i++) v2.pb(v[i]);

    ll resp = inv(v1) + inv(v2);

    v1.pb(MAXN);
    v2.pb(MAXN);

    int i1 = 0, i2 = 0;
    fr(i, k){
        if(v1[i1] < v2[i2]) v[i] = v1[i1++];
        else{
            v[i] = v2[i2++];
            resp += (ll)v1.size() - i1 - 1;
         }
    }

    return resp;
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while(n > 0){
        vector<int> v;
        fr(i, n){
            int x;
            cin >> x;
            v.pb(x);
        }

        ll p = inv(v);

        if(p%2 == 1) cout << "Marcelo\n";
        else cout << "Carlos\n";

        cin >> n;
    }
}
