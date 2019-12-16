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

#define MOD 1300031

int inverse[MOD];

void EuclideanExtended(int a, int b, int *x, int *y){
  if(b == 0){
    *x = 1;
    *y = 0;
    return;
  }

  int x0, y0;
  EuclideanExtended(b, a%b, &x0, &y0);

  *x = y0;
  *y = x0 - (a/b)*y0;

  return;
}

ll bin(int a, int b){
  ll resp = 1;

  frr(i, b){
    resp *= (ll)(a - b + i);
    resp *= (ll)(inverse[i]);

    //cout << resp << endl;
    mod(resp, MOD);
  }

  return resp;
}

int main(){
		ios::sync_with_stdio(false);

    mem(inverse, 0);

    frr(i, MOD - 1){
        if(inverse[i] > 0) continue;

        int x, y;
        EuclideanExtended(i, MOD, &x, &y);

        x = (x + MOD)%MOD;

        inverse[i] = x;
        inverse[x] = i;
    }

    int test;
    cin >> test;

    while(test--){
        int n, c;
        cin >> n >> c;

        if(n - 1 > c){
            cout << bin(n + c - 1, c) << endl;
        }
        else{
            cout << bin(n + c - 1, n - 1) << endl;
        }
    }
}
