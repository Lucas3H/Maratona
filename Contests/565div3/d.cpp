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

#define MAXN 200010
#define MAX 2750131
int main(){
	   ios::sync_with_stdio(false);

		 int n;
		 cin >> n;
		 n = n*2;
		 vector<int> a;
		 fr(i, n) {
			 	int x;
			 	cin >> x;
				a.pb(x);
		}
		 sort(a.begin(), a.end());

		 int ehprimo[MAX];
		 mem(ehprimo, 0);
		 vector<int> p;
		 p.pb(0);
		 int indp[MAXN];

		 int j = 1;
		 for(int i = 2; i < MAXN; i++){
			 		if(ehprimo[i] == 0){
							for(int j = 2*i; j < MAXN; j+=i){
									ehprimo[j] = 1;
							}
							p.pb(i);
							indp[i] = j++;
							}
		 }

		 vector<int> resp;
	  	stack<int> peguei;

		 frm(i, n){

			 		if(peguei.size()> 0 && peguei.top() == a[i]){
							peguei.pop();
							continue;
					}
			 		if(ehprimo[a[i]] == 0){
							//	cout << indp[a[i]] << endl;
								peguei.push(indp[a[i]]);
								resp.pb(indp[a[i]]);
					}
					else{
							int j = 1;
							while(a[i]%p[j] != 0) j++;

							peguei.push(a[i]/p[j]);
							resp.pb(a[i]);
					}

		 }
		 fr(i, n/2) cout << resp[i] << " ";
}
