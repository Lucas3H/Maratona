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

int n;
double dp[(1 << 20)];
double prob[21][20];

int sumbits(int m){
    int ans = 0;
    while(m > 0){
        ans+=(m%2);
        m/=2;
    }

    return ans;
}

void func(){

    for(int mask = 0; mask < (1 << n); mask++){

        int S = n - sumbits(mask);

    //    cout << mask << " kjkjh " << (1 << n) << endl;

        if(S == 1) continue;

        fr(i, n){
            if((mask & (1 << i)) > 0) continue;

            double p = 0;
            fr(j, n) {
                if((mask & (1 << j)) == 0) p+=prob[j][i];
            }
            p*=2*dp[mask];
            p/=(S*(S-1));

            //cout << mask << " da " << i << " " << p << endl;

            dp[ (mask | (1 << i)) ] += p;

        //    cout << S-1 << " oko " << (mask | (1 << i)) << endl;
        }

    ///    cout << mask << "Ook " << endl;
    }

    return;
}

int main(){

    int t;
    cin >> t;

    frr(ts, t){
        cin >> n;

        fr(i, (1 << n)) dp[i] = 0;
        dp[0] = 1;

        fr(i, n){
            fr(j, n) cin >> prob[i][j];
        }

        printf("Case %d: ", ts);
        if(n == 1) printf("1.000000\n");
        else{
            func();
/*
            fr(i, (1 << n)) cout << dp[i] << endl;
            cout << endl;
*/
            fr(i, n) printf("%.6lf ", dp[(1 << n) - 1 - (1 << i)]);
            printf("\n");
        }
    }
}
