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

#define MAXN 100010
#define MOD 1000000007

int mdc(int a, int b){
  if(b == 0) return a;
  else return mdc(b, a%b);
}

int main(){
		ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int g = k;

    int x;
    fr(i, n){
      cin >> x;
      g = mdc(x, g);
    }

    cout << k/g << endl;

    fr(i, k){
      if(i%g == 0) cout << i << " ";
    }
}