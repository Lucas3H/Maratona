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

#define MAXN 100010

int main(){
	   ios::sync_with_stdio(false);

		 int queries;
		 cin >> queries;
		 while(queries--){
			 		int n;
					cin >> n;

					int	v[110];
					int a = 0, b = 0, c = 0;

					fr(i, n) {
						cin >> v[i];

						if(v[i]%3 == 0) a++;

						if(v[i]%3 == 1) b++;

  					if(v[i]%3 == 2) c++;

					}

					int resp = 0;

					resp+=a;

					resp += min(b, c);

					resp += (max(b, c) - min(b,c))/3;

					cout << resp << endl;
		 }
}
