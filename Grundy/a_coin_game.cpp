// https://www.codechef.com/SEP09/problems/G3
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

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		int p[10010], dif[10010];
		
		p[0] = 0;
		frr(i, n) cin >> p[i];

		int sum = 0, j = 0;
		if(n%2 == 0){
			for(int i = 1; i < n; i+=2){
				sum^=(p[i+1] - p[i] - 1);
				dif[j++] = p[i+1] - p[i] - 1;
			}	
		}
		else{
			for(int i = 0; i < n; i+=2){
				sum^=(p[i+1] - p[i] - 1);
				dif[j++] = p[i+1] - p[i] - 1;
			}
		}

		if(sum == 0){
			cout << "Johnny wins\n";
		}
		else{
			cout << "Mary wins\n";

			fr(i, j){
				//cout << (sum^dif[i]) << " " << dif[i] << endl;
				if((sum^dif[i]) > dif[i]){
					if(n%2 == 0){
						if(p[2*i+1] - p[2*i] - 1 + dif[i] >= (sum^dif[i])){
							cout << "Move " << p[2*(i+1) - 1] << " to " << p[2*i + 2] - (sum^dif[i]) - 1 << endl;
							break;
						}
					}
					else{
						if(i > 0 && p[2*i] - p[2*i - 1] - 1 + dif[i] >= (sum^dif[i])){
							cout << "Move " << p[2*i] << " to " << p[2*i + 1] - (sum^dif[i]) - 1 << endl;
							break;
						}
					}
				}
				
				if((sum^dif[i]) < dif[i]){
					if(n%2 == 0){
						cout << "Move " << p[2*(i+1)] << " to " << p[2*(i+1) - 1] + (sum^dif[i]) + 1 << endl;  
					}
					else{
						cout << "Move " << p[2*i+1] << " to " << p[2*i] + (sum^dif[i]) + 1 << endl;  		
					}

					break;
				}
			}
		}

		cout << endl;

		
	}
}
