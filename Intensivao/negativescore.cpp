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

int tree[4*MAXN], ev[MAXN];

void build(int i, int l, int r){
  if(l == r){
    tree[i] = ev[l];
    return;
  }

  int mid = (l+r)/2;

  build(2*i, l, mid);
  build(2*i+1, mid+1, r);

  tree[i] = min(tree[2*i], tree[2*i+1]);
}

int query(int i, int l, int r, int ql, int qr){
  if(ql <= l && r <= qr) return tree[i];
  else if(ql > r || l > qr) return 1000000000;
  else{
    int mid = (l+r)/2;

    int left = query(2*i, l, mid, ql, qr);
    int right = query(2*i+1, mid+1, r, ql, qr);

    return min(left, right);
  }
}

int main(){
		ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    frr(ts, tests){
      int e, q;
      cin >> e >> q;

      frr(i, e) cin >> ev[i];
      build(1, 1, e);

      cout << "Scenario #" << ts << ": " << endl;

      int a, b;
      fr(i, q){
        cin >> a >> b;

        cout << query(1, 1, e, a, b) << endl;
      }
    }
}
