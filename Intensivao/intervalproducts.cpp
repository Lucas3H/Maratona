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

int n, k;
int tree[4*MAXN], x[MAXN];

void build(int i, int l, int r){
  if(l == r){
    if(x[l] == 0) tree[i] = 0;
    else if(x[l]>0) tree[i] = 1;
    else tree[i] = -1;
  }
  else{
    int mid = (l+r)/2;

    build(2*i, l, mid);
    build(2*i+1, mid+1, r);

    tree[i] = tree[2*i]*tree[2*i+1];
  }
}

void update(int i, int l, int r, int pos, int value){
  if(l == r) {
    if(value < 0) tree[i] = -1;
    else if(value == 0) tree[i] = 0;
    else tree[i] = 1;
  }
  else{
    int mid = (l+r)/2;

    if(pos <= mid) update(2*i, l, mid, pos, value);
    else update(2*i+1, mid+1, r, pos, value);

    tree[i] = tree[2*i]*tree[2*i+1];
  }
}

int query(int i, int l, int r, int ql, int qr){
  if(ql <= l && r <= qr) return tree[i];
  else if(ql > r || l > qr) return 1;

  int mid = (l+r)/2;

  int left = query(2*i, l, mid, ql, qr), right = query(2*i+1, mid+1, r, ql, qr);

  return left*right;
}

int main(){
		while(cin >> n >> k){
      frr(i, n) cin >> x[i];

      build(1, 1, n);

      char c;
      int a, b;
      frr(i, k){
        cin >> c;
        cin >> a >> b;

        //cout << c << endl;

        if(c == 'C') update(1, 1, n, a, b);
        else if(c == 'P'){
          int p = query(1, 1, n, a, b);

          //cout << i << " " << p << " ";
          if(p == 0) cout << '0';
          else if(p > 0) cout << '+';
          else cout << '-';
        }
      }

      cout << endl;
    }
}
