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

int n, S;
int a[11];

int lsb(int x){
  return x&-x;
}

int sum(int x){
  int s = 0;
  int i = 0;

  while(x > 0){
    s+=(x%2)*a[i];
    x/=2;
    i++;
  }

  return s;
}

int sumbits(int x){
  int ans = 0;
  while(x > 0){
    ans+=x%2;
    x/=2;
  }

  return ans;
}

int main(){
		ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while(tests--){
      cin >> n >> S;

      fr(i, n) cin >> a[i];
      sort(a, a+n);

      int mV = 0;

      fr(i, 1 << n){
        int s = sum(i);

        if(s < S) continue;

        int b = floor((log(lsb(i))+0.001)/log(2));

        if(s - a[b] < S){
//cout << i << endl;
          mV = max(mV, sumbits(i));
        }
      }

      cout << mV << endl;
    }
}
