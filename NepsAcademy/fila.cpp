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

int main(){
	   ios::sync_with_stdio(false);

     int h[MAXN], esta[MAXN];
     int n;

     mem(esta, 0);

     cin >> n;
     fr(i, n) {
        cin >> h[i];
        esta[h[i]] = 1;
        }

      int m;
      cin >> m;

      fr(i, m){
          int x;
          cin >> x;

          esta[x] = 0;
      }

      fr(i, n){
          if(esta[h[i]]) cout << h[i] << " ";
      }

      cout << endl;
}
