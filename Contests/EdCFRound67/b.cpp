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


int ap[30];
int fr[30][2*MAXN];

int main(){
		ios::sync_with_stdio(false);
		int n;
		string s;
		cin >> n >> s;

		int m;
		cin >> m;
		string name;

		fr(i, n) fr[(s[i] - 'a')][i] = 1;
		int sum = 0;

		fr(i, 26){
			sum = 0;
			fr(j, n){
				sum+=fr[i][j];
				fr[i][j] = sum;
			}
		}
/*
		fr(i, 26){
			fr(j, n) cout << fr[i][j] << " ";

			cout << endl;
		}
*/
		fr(i, m){
			cin >> name;
			int k = name.size();
			fr(i, 26) ap[i] = 0;

			fr(i, k) {
				ap[name[i] - 'a']++;
			}

			int maxi = -1;
			fr(i, 26){
				int ini = 0, fim = n-1, meio;

				//cout << name
				meio = 0;

				while(ini <= fim){
					meio = (ini+fim)/2;

					if(fr[i][meio] >= ap[i]) fim = meio-1;
					else ini = meio+1;
				}

				//cout << name << " " << i << " " << fim << " " << ap[i] << endl;

				if(fim+1 > maxi) maxi = fim+1;
			}

			cout << maxi+1 << endl;
		}
}
