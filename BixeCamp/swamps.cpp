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

#define MAXN 2500010


int m[25][50001];
int total[50001];
vector<int> a;
int n;

ll inv(vector<int> &v){
			int m = v.size();

			if(m == 1) return 0;

			vector<int> v1, v2;

			for(int i = 0; i < m/2; i++) v1.pb(v[i]);
			for(int i = m/2; i < m; i++) v2.pb(v[i]);

			ll resp = 0;
			resp += inv(v1) + inv(v2);

			v1.pb(50001);
			v2.pb(50001);

			int i1 = 0, i2 = 0;
			fr(i, m){
						if(v[i1] <= v2[i2]) v[i] = v1[i1++];
						else{
								v[i] = v2[i2++];
								resp += (ll)v1.size() - (ll)i1 - 1;
						}
			}

			return resp;
}

int main(){
	   ios::sync_with_stdio(false);

		 cin >> n;

		 int x;
		 for(int i = 0; i < 25; i++){
			 		for(int j = 10000*i; j < 10000*(i+1) && j < n; j++){
								cin >> x;
								a.pb(x);
								total[x]++;
					}
					int sum = 0;
					for(int j = 0; j < 50001; j++){
								m[i][j] = sum;
								sum += total[j];
					}
		 }

		 ll r = inv(a);

		 int k;
		 cin >> k;

		 int a, b;
		 while(k--){
			   cin >> a >> b;

				 
		 }
}
