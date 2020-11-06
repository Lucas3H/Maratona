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

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
	ios::sync_with_stdio(false);

    int R, C;
    cin >> R >> C;
    int r[1010], c[1010];

    int m[1010][1010];

    fr(i, R) cin >> r[i];
    fr(i, C) cin >> c[i];

    mem(m, -1);

    fr(i, R){
        if(r[i] == 0){
            m[i][0] = 0;
        }
    }

    fr(i, C){
        fr(j, c[i]){

            if(r[j] == 1){
                r[j]--;
                m[j][i+1] = 0;
            }
            else if(r[j] > 0) r[j]--;

            if(m[j][i] == 0){
                cout << 0 << endl;

                //cout << "!ooo" << endl;
                return 0;
            }

            m[j][i] = 1;
        }

		if(r[c[i]] > 0){
			cout << 0 << endl;
			return 0;
		}

        m[c[i]][i] = 0;

        for(int j = c[i] + 1; j < R; j++){

            if(r[j] == 0) continue;

            if(m[j][i] == 0){
                cout << 0 << endl;
                //cout << j << " " << i << endl;
                //cout << "!OK" << endl;
                return 0;
            }

            if(r[j] == 1){
                r[j]--;
                m[j][i] = 1;
                m[j][i+1] = 0;
            }
            else if(r[j] > 0){
                m[j][i] = 1;
                r[j]--;
            }
        }
    }

    int ans = 0;
    fr(i, R){
        fr(j, C){
            if(m[i][j] == -1) ans++;
        }
    }

    ll t = 1;

    fr(i, ans){
        t = (t*(ll)2)%MOD;
    }

    cout << t << endl;
}
