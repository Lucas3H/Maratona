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

vector<int> a, b;

int ok =1;

int resp[MAXN];

int lis(vector<int> v){
	vector<int> pilha;

	pilha.pb(v[0]);

	frr(i, v.size()-1){
		vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);

		if(it == pilha.end()){
			pilha.pb(v[i]);
		}
		else{
			(*it) = v[i];
		}
	}

	if(ok){
		fr(i, n)
	}

	ok = 0

	return pilha.size();
}

int main(){
	int n;
	cin >> n;

	fr(i, n){
		int x;
		cin >> x;
		a.pb(x);
	}

	fr(i, n) b.pb(a[n-1-i]);

	int A = lis(a), B = lis(b);

	if(A)
}