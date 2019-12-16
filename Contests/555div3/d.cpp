#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 100010

int main(){
	ll n, k;
	cin >> n >> k;

	ll x = n - k*(k-1)/2;

	x = x/k;

	if(x > 1){
		cout << "YES" << endl;
		for(int i = 0; i < k-1; i++){
			cout << x + i << " ";
		}
		cout << x + k-1 + n - x*k - k*(k-1)/2 << endl;
	}
	else{
		if(n < k*(k+1)/2) cout << "NO" << endl;
		else{
			if(k == 2){
				if(n==4) cout<< "NO" << endl;
				else{

					cout << "YES" << endl;
					cout << 1 << " " << 2 << endl;
				}
			}
			else if(k == 3){
				if(n == 6){
					cout << "YES" << endl;
					cout << "1 2 3" << endl;
				}
				else if(n == 7){

					cout << "YES" << endl;
					cout << "1 2 4" << endl;
				}
				else cout << "NO" << endl;
			}
			else{

					cout << "YES" << endl;
				if(n == k*(k+1)/2 || n == k*(k+1)/2 + 1){
					fr(i, k-1) cout << 1+i << " ";

					cout << x + k-1 + n - x*k - k*(k-1)/2 << endl;
				}

				else{
					for(int i = 0; i < k-2; i++) cout << 1 + i << " ";
					cout << x + k - 1 << " " << x + k-2 + n - x*k - k*(k-1)/2 << endl;
				}
			}
		}
	}
}	