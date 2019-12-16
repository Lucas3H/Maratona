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

#define MAXN 500010

int main(){
	   ios::sync_with_stdio(false);
     int n;
     cin >> n;

     int a[MAXN];

     int tam[7];

		 fr(i, 7) tam[i] = 0;

		int resp = 0;

     fr(i, n){
					cin >> a[i];

          if(a[i] == 4) tam[1]++;
          else if(a[i] == 8){
              if(tam[1] > tam[2]) tam[2]++;
              else resp++;
          }
          else if(a[i] == 15){
              if(tam[2] > tam[3]) tam[3]++;
              else resp++;
          }
          else if(a[i] == 16){
              if(tam[3] > tam[4]) tam[4]++;
              else resp++;
          }
          else if(a[i] == 23){
              if(tam[4] > tam[5]) tam[5]++;
              else resp++;
          }
          else if(a[i] == 42){
              if(tam[5] > tam[6]) tam[6]++;
              else resp++;
          }
     }

		 frr(i, 5){
			 		resp+= tam[i] - tam[6];
		 }

     cout << resp << endl;
}
