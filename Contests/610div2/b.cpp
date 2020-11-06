#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

int n, P, k, p;
		

int main(){
	ios::sync_with_stdio(false);
	int t;
	scanf("%d", &t);

	while(t--){
		scanf("%d %d %d", &n, &P, &k);

		int a[2*MAXN], aux;

		frr(i, n) {
			scanf("%d", &a[i]);
		}
		a[n+1] = 2*MOD;

		sort(a + 1, a + n + 2);
		int sum = 0, i = 1, ans;
		p =P;
		while(i <= n && p > 0){
			if(a[i+1] <= p){
				p-=a[i+1];
				sum+=2;
				//cout << i << endl;
				i+=2;
			}
			else{
				if(a[i] <= p){

					p-=a[i];
					sum++;
					i++;
				}
				break;
			}
		}

		ans = sum;
		p=P;
		sum = 0, i = 2;
		if(a[1]<=p){
			sum++;
			p-=a[1];
		}

		while(i <= n && p > 0){
			if(a[i+1] <= p){
				p-=a[i+1];
				sum+=2;
				i+=2;
			}
			else{
				if(a[i] <= p){

					p-=a[i];
					sum++;
					i++;
				}
				break;
			}
		}
		//cout << "O " << sum << " " << ans << ' ';

		printf("%d\n", max(ans, sum));


	}
}
