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

#define MAXN 1000000005

int main(){
	int n;

	cin >> n;

	int min;

	int c, p, soma, resp = 0;
	cin >> c >> p;
	min = p;
	soma = c;

	resp += soma*min;

	soma = 0;

	for(int i = 0; i < n-1; i++){
		cin >> c >> p;

		if(p > min) soma += c;

		if(p <= min){
			resp += min*soma;
			soma = 0;
			soma += c;
			min = p;
		}
	}

	if(min <= p) resp += soma*min;
	else resp += c*p;

	cout << resp << endl;

	return 0;	
}
