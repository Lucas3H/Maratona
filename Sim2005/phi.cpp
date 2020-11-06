#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 1000010

int main(){
	int test;
	cin >> test;
	
	int primo[MAXN];
	mem(primo, 0);
	
	primo[1] = 1;
	
	vector<int> p;
	
	for(int i = 2; i < MAXN; i++){
		if(primo[i] == 0){
			for(int j = 2*i; j < MAXN; j += i){
				primo[j] = 1;
			}
			
			p.pb(i);
		}
	}
	
	while(test--){
		int m;
		cin >> m;
		
		ll phi = m;
		int i = 0;
		
		while(p[i] <= m){
			
			if(primo[m] == 0){
				phi -= (phi/m);
				break;
			}

			if(m%p[i] == 0){
				//cout << i << endl;
				phi = phi/p[i];
				phi *= (p[i]-1);
					
				m = m/p[i];
			}

			i++;
		}
		
				
		cout << phi << endl;
	}	
}