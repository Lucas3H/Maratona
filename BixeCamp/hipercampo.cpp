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

#define MAXN 110

int memo[MAXN];
pair<int, int> pt[MAXN];

pii A, B;

int det(pii a, pii b, pii c){
    return a.first*b.second + a.second*c.first + b.first*c.second - c.first*b.second - c.second*a.first - b.first*a.second;
}

int dp(int h){
    if(memo[h] >= 0) return memo[h];

    int maximo = -1;

    fr(i, h){
      //  cout << i << " " << h << endl;
        //cout << det(B, pt[h], pt[i]) << " " << det(pt[h], A, pt[i]) << endl;

        if(det(B, pt[h], pt[i]) > 0 && det(pt[h], A, pt[i]) > 0){
              int x = dp(i);
              if(x > maximo) maximo = x;
        }
    }

    if(maximo == -1) return 1;
    else return memo[h] = maximo + 1;
}

bool ord(pii a, pii b){
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main(){
  	 ios::sync_with_stdio(false);
     int n, a, b;
     cin >> n >> a >> b;

     A = mp(a, 0);
     B = mp(b, 0);

     mem(memo, -1);

     fr(i, n){
         int x, y;
         cin >> x >> y;

         pt[i] = mp(x, y);
     }

     sort(pt, pt+n, ord);

     int resp = 0;
     fr(i, n){
          int x = dp(i);
          //cout << x << endl;
          if(x > resp) resp = x;
     }

     cout << resp << endl;
}
