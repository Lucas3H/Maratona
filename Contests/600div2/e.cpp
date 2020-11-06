#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
    int n, m;
    cin >> n >> m;

    pii x[100];

    int pos, range;

    int left[2*MAXN], right[2*MAXN];
    mem(left, 0);
    mem(right, 0);


    frr(i, n) {
        cin >> pos >> range;

        x[i] = mp(pos, range);

        if(pos - range >= 1 && pos - range <= m){
            left[pos-range] = pos+range;
        }
        if(pos + range >= 1 && pos + range <= m){
            right[pos+range] = pos-range;
        }
    }



    sort(x+1, x + n + 1);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int ans = 0;
    int l, r;

    l = x[1].f + x[1].s + max(x[1].f - x[1].s - 1, 0);
    ans += max(x[1].f - x[1].s - 1, 0);

    cout << ans << endl;

    r = x[n].f - x[n].s - max(0, m - (x[n].f + x[n].s));
    ans += max(m - (x[n].f + x[n].s), 0);

    while(l < r){
        int antena_l = lower_bound(left.begin(), left.end(), )    
    }
/*
    frr(i, n){
        if((x[i].f - x[i].s - x[i-1].f - x[i-1].s) > 1){
            ans+=(x[i].f - x[i].s - x[i-1].f - x[i-1].s - 1);
            x[i].s += (x[i].f - x[i].s - x[i-1].f - x[i-1].s - 1); 
        }

        if((x[n+2-i].f - x[n+2-i].s - x[n+1-i].f - x[n+1-i].s) > 1){
            ans+=(x[n+2-i].f - x[n+2-i].s - x[n+1-i].f - x[n+1-i].s - 1);
            x[n+1-i].s += (x[n+2-i].f - x[n+2-i].s - x[n+1-i].f - x[n+1-i].s - 1); 
        }

        cout << ans << endl;
    }*/
}