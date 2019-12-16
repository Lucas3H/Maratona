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
		 fr(i, n) cin >> a[i];

		vector<int> v[6];

		 int rem = 0;
		 fr(i, n){
			 		if(a[i] == 4) v[0].pb(i);
					else if(a[i] == 8) v[1].pb(i);
					else if(a[i] == 15) v[2].pb(i);
					else if(a[i] == 16) v[3].pb(i);
					else if(a[i] == 23) v[4].pb(i);
					else if(a[i] == 42) v[5].pb(i);
		 }

		 frr(k, 5){
	 	 		int j = 0, i = 0;
	 	 		for(i = 0; i<v[k].size() && j < v[k-1].size(); i++){
			 				if(v[k][i] < v[k-1][j]){
									rem++;
									v[k].erase(v[k].begin() + i, v[k].begin()+i+1);
							}
							else j++;
		    }

				rem += v[k].size() - i;
	 	 }


		 cout << rem << endl;
}
