#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 50010
#define MOD 1000000007

int main(){
    int prime[MAXN];
    vector<int> p;
    for(int i = 2; i < MAXN; i++){
        if(prime[i] == 0){
            p.pb(i);
            for(int j = 2*i; j < MAXN; j += i) prime[j] = 1;
        }
    }

    int n, i, phi;

    while(cin >> n){
        i = 0;
      	phi = 1;

        while(n > 1 && i < p.size()){
            if(n%p[i] == 0){
                phi *= (p[i] - 1);
                n /= p[i];
                while(n%p[i] == 0){
                    n /= p[i];
                    phi *= p[i];
                }
            }

            i++;
        }

        if(n > 1) phi *= (n-1);

				cout << phi/2 << endl;
    }

    return 0;
}
