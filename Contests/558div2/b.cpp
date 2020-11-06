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
	int n;
	cin >> n;
	int fr[11];

	map<int, int> m;

	m[0] = 11;

	int resp = 0;
	fr(i, n){
		int x;
		cin >> x;

		fr[x]++;

		auto it = m.find(fr[x]);
		auto it1 = m.find(fr[x] - 1);

		(*it1).second--;
		if((*it1).second == 0) m.erase(it1);

		if(it == m.end()){
			m[fr[x]] = 1;
		}
		else{
			(*it).second++;
		}

		if(m.size() > 3) continue;

		else if(m.size() == 2){
			if((*m.begin()).first == 1) resp = i+1;
		}

		else{

			auto j = m.begin();

			for(auto k: m){

				if(k.first == 1 && k.second == 1) resp = i+1;

				if((*j).second == 1 && (*j).first == (*j).first + 1) resp = i+1;
			
					
				if(k.second == 1 && k.first == (*j).first + 1) resp = i+1;				
			}
		}
	}

	cout << resp << endl;
}