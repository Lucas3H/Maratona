#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);

#define ll long long

#define MAXN 300010

int winner[4*MAXN], defeated[MAXN];

set<int> survivors;

void build(int i, int l, int r){
    if(l == r) winner[i] = l;
    else{
        winner[i] = 0;
        int mid = (l+r)/2;

        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
    }
}

void query(int i, int l, int r, int ql, int qr){
    if(ql > r || l > qr) return;
    if(winner[i] == -1) return;

    if(ql <= l && r <= qr && winner[i] > 0){
        survivors.insert(winner[i]);
        return;
    }
    else{
      int mid = (l+r)/2;

      query(2*i, l, mid, ql, qr);
      query(2*i+1, mid+1, r, ql, qr);
    }
}

void update(int i, int l, int r, int ql, int qr, int win){
    if((ql > r || l > qr)) return;

    //cout << l << " " << r << " " << win << endl;

    if(win == -1){
          winner[i] = -1;
          return;
    }

    int mid = (l + r)/2;
    if(ql <= l && r <= qr) {
          winner[i] = win;

          if(l == r) return;

          if(win <= mid){
                update(2*i, l, mid, ql, qr, win);
                update(2*i+1, mid+1, r, ql, qr, -1);
          }
          else{
                update(2*i, l, mid, ql, qr, -1);
                update(2*i+1, mid+1, r, ql, qr, win);
          }

          return;
    }

    if(l == r) return;

    update(2*i, l, mid, ql, qr, win);
    update(2*i+1, mid+1, r, ql, qr, win);
}

int main(){
	   ios::sync_with_stdio(false);

     int n, m;
     cin >> n >> m;

     build(1, 1, n);

     fr(i, m){
          int a, b, c;
          cin >> a >> b >> c;

          survivors.clear();
          query(1, 1, n, a, b);

          for(auto x: survivors) {
              if(x >= a && x <= b)defeated[x] = c;
              //3cout << x << endl;
          }
          update(1, 1, n, a, b, c);
     }

     survivors.clear();
     query(1, 1, n, 1, n);

     defeated[(*survivors.begin())] = 0;

     frr(i, n) cout << defeated[i] << " ";

     cout << endl;
}
