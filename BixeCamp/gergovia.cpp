#include<bits/stdc++.h>

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 

#define mk make_pair
#define pq priority_queue

#define MAXN 100010

using namespace std;

int main(){
	int n;
	cin >> n;

	while(n != 0){
		deque<pair<int, int>> vender, comprar;

		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			if(x > 0) vender.pb(mk(x, i));
			else comprar.pb(mk(-x, i));
		}

		long long resp = 0;
		
		while(!vender.empty()){

			if(comprar.front().first > vender.front().first){

				int x = comprar.front().first - vender.front().first;
				int y = comprar.front().second;
				int z = comprar.front().second - vender.front().second;

				resp += vender.front().first*(abs(z));
				
				vender.pop_front();
				comprar.pop_front();
				comprar.push_front(mk(x, y));

			}
			else if(comprar.front().first == vender.front().first){

				int z = comprar.front().second - vender.front().second;

				resp += vender.front().first*(abs(z));

				vender.pop_front();
				comprar.pop_front();
			}
			else{
				int x = vender.front().first - comprar.front().first;
				int y = vender.front().second;
				int z = comprar.front().second - vender.front().second;


				resp += comprar.front().first*(abs(z));

				vender.pop_front();
				comprar.pop_front();
				vender.push_front(mk(x, y));
			}
		}

		cout << resp << endl;
	
		cin >> n;
	}	
}
