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

#define MAXN 150010

int v[4*MAXN], a[MAXN];

int controle = 0;

int build(int i, int l, int r){
			if(l == r){
						v[i] = a[l];
						return 0;
			}
			else{
					int mid = (l+r)/2;

					int k = build(2*i, l, mid);
					k = build(2*i+1, mid+1, r);

					if(k == 0){
							v[i] = v[2*i]|v[2*i+1];
							return 1;
					}
					else{
							v[i] = v[2*i]^v[2*i+1];
							return 0;
					}
			}
}

int update(int i, int l, int r, int pos, int value){
			if(l == r){
						v[i] = value;
						return 0;
			}
			else{
						int mid = (l+r)/2;

						int k;
						if(mid >= pos) k = update(2*i, l, mid, pos, value);
						else k = update(2*i+1, mid+1, r, pos, value);


						if(k == 0){
									v[i] = v[2*i]|v[2*i+1];
									return 1;
						}
						else{
									v[i] = v[2*i]^v[2*i+1];
									return 0;
						}
			}
}

int main(){
			ios::sync_with_stdio(false);

			int n, m;
			cin >> n >> m;

			frr(i, 1 << n) cin >> a[i];

			int t = build(1, 1, 1 << n);

			fr(i, m){
						int c, b;
						cin >> c >> b;

						update(1, 1, 1 << n, c, b);

						cout << v[1] << endl;

			}
}
