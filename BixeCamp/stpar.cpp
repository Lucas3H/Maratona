#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;
#define mk make_pair
#define pq priority_queue

#define MAXN 100010

int main(){
	int n;
	cin >> n;

	while(n > 0){
		
		stack<int> m, st;

		int deu = 1;
		int i = 1;


		for(int j = 0; j < n; j++){
			int x;
			cin >> x;
			
			int usei = 1;
			
			if(x == i){
				usei = 0;
				m.push(x);
				i++;
			}

			while(true){
				if(st.empty()) break;

				else if(st.top() == i){
					m.push(st.top());
					st.pop();
					i++;
					usei = 0;
				}

				else break;
			}

			if(usei) {
				st.push(x);
			}
		}

		for(int j = 0; j < st.size(); j++){
			if(st.top() != i){
				deu = 0;
				break;
			}
			else{
				m.push(st.top());
				st.pop();
				i++;
			}
		}

		if(deu) cout << "yes" << endl;
		else cout << "no" << endl;

		cin >> n;
	}	
}
