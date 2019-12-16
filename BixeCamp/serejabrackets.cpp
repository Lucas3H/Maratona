#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 1000010

int resp[4*MAXN], op[4*MAXN], cl[4*MAXN];
int n;
string s;

void build(int i, int l, int r){
	if(l == r){
		resp[i] = 0;
		
		if(s[l] == ')') {
			cl[i] = 1;
			op[i] = 0;
		}
		else{
			cl[i] = 0;
			op[i] = 1;
		} 
	}
	else{
		int mid = (l+r)/2;
		build(2*i, l, mid);
		build(2*i+1, mid+1, r);

		resp[i] = resp[2*i] + resp[2*i+1] + min(op[2*i], cl[2*i+1]);

		if(op[2*i] > cl[2*i+1]){
			op[i] = op[2*i+1] + op[2*i] - cl[2*i+1];
			cl[i] = cl[2*i];
		}
		else{
			cl[i] = cl[2*i] + cl[2*i+1] - op[2*i];
			op[i] = op[2*i+1];
			
		}
	}

}

pair<int, pii> query(int i, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr) return mp(resp[i], mp(op[i], cl[i]));
	if(ql > r || qr < l) return mp(0, mp(0, 0));

	int mid = (l+r)/2;

	pair<int, pii> a = query(2*i, l, mid, ql, qr), b = query(2*i+1, mid+1, r, ql, qr);

	r = a.first + b.first + min(a.second.first, b.second.second);

	int o, c;
	if(a.second.first > b.second.second){
		o = b.second.first + a.second.first - b.second.second;
		c = a.second.second;
	}
	else{
		c = a.second.second + b.second.second - a.second.first;
		o = b.second.first;
	}

	return mp(r, mp(o, c));
}

int main(){
	cin >> s;
	cin >> n;

	build(1, 0, s.size() - 1);

	fr(i, n){
		int a, b;
		cin >> a >> b;
		a--;
		b--;

		cout << 2*(query(1, 0, s.size()- 1, a, b).first) << endl;
	}
}