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

#define MAXN 100001

int main(){
	   ios::sync_with_stdio(false);

     int n;
     cin >> n;

     int a[MAXN], b[MAXN], c[MAXN];
     map<int, int> fr;

     frr(i, n){
          cin >> a[i];

          if(fr.find(a[i]) == fr.end()){
              fr[a[i]] = 1;
              b[i] = 1;
          }
          else{
              fr[a[i]]++;
              b[i] = fr[a[i]];
          }
     }

     frr(i, n) c[i] = fr[a[i]] - b[i] + 1;

     sort(b, b+n);
     sort(c, c+n);

     int i1 = 1, i2 = 1, resp = 0;

		 b[n+1] = MAXN+1;
		 c[n+1] = MAXN+1;

     fr(i, 2*n){
          if(b[i1] <= c[i2]){
              i1++;
              resp += i2;
          }
          else i2++;

					cout << resp << endl;
     }

     cout << resp << endl;

     return 0;
}
