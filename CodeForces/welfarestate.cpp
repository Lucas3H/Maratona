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

ll p[2*MAXN], nd[8*MAXN], lz[8*MAXN];

void build(int n, int l, int r){
  if(l == r) nd[n] = p[l];
  else{
    int mid = (l+r)/2;

    build(2*n, l, mid);
    build(2*n+1, mid+1, r);

    nd[n] = min(nd[2*n], nd[2*n+1]);
  }
}

void push(int n, int l, int r){
  nd[n] = max(nd[n], lz[n]);

  if(l < r){
    int mid = (l+r)/2;

    lz[2*n] = max(lz[n], lz[2*n]);
    lz[2*n+1] = max(lz[n], lz[2*n+1]);
  }
  else{
    p[l] = nd[n];
  }

  lz[n] = -1;
}

void atualiza(int n, int l, int r, int x, int value){
  push(n, l, r);

  if(l == r){
    nd[n] = value;
    p[l] = value;
  }

  else{
    int mid = (l+r)/2;
    if(x <= mid) atualiza(2*n, l, mid, x, value);
    else atualiza(2*n+1, mid+1, r, x, value);

    nd[n] = min(nd[2*n], nd[2*n+1]);
  }
}

void atu(int i, int l, int r){
  push(i, l, r);

  if(l == r) return;

  int mid = (l+r)/2;
  atu(2*i, l, mid);
  atu(2*i+1, mid+1, r);
}

int main(){
   ios::sync_with_stdio(false);
   int n;
   cin >> n;


   mem(lz, -1);

   frr(i, n) cin >> p[i];

   build(1, 1, n);

   int q;
   cin >> q;

   while(q--){
     int z, y, w;
     cin >> z >> y;

     if(z == 1){
       cin >> w;

       atualiza(1, 1, n, y, w);

     }
     else{
       lz[1] = max(lz[1], (ll)y);
     }
   }

   atu(1, 1, n);

   frr(i, n) cout << p[i] << " ";

}
