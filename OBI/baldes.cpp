#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
typedef pair<int, int> pii;
pii t[4*MAX], b[MAX];
int n, m;
bool folha[4*MAX];

pii juntaFolhas(pii u, pii v){
	pii w;
	if(u.second - v.first > v.second - u.first){
		w = make_pair(v.first, u.second);
	}
	else{
		w = make_pair(u.first, v.second);
	}
	return w;
}

pii juntaFolha(pii f, pii i){
	pii w;
	if(i.second - i.first > i.second - f.first){
		if(i.second - i.first > f.second - i.first) w = i;
		else w = make_pair(i.first, f.second);
	}
	else{
		if(i.second - f.first > f.second - i.first) w = make_pair(f.first, i.second);
		else w = make_pair(i.first, f.second);
	}

	return w;
}

void build(int i, int l, int r){
	if(l == r){
		t[i] = b[l];
		folha[i] = true;
	}
	else{
		int m = (l + r)/2;
		build(2*i, l, m);
		build(2*i + 1, m + 1, r);
		//if(folha[2*i] || folha[2*i + 1]) t[i] = ();
		t[i] = make_pair(min(t[2*i].first, t[2*i + 1].first), max(t[2*i].second, t[2*i + 1].second));
	}
}

void update(int i, int l, int r, int p){
	if(l == r){
		t[i] = b[l];
	}
	else{
		int m = (l+r)/2;
		if(p <= m){
			update(2*i, l, m, p);
		}
		else{
			update(2*i + 1, m+1, r, p);
		}

		if(folha[2*i]){
			if(folha[2*i + 1]) t[i] = juntaFolhas(t[2*i], t[2*i + 1]);
			else t[i] =  juntaFolha(t[2*i], t[2*i + 1]);
		}
		else{
			if(folha[2*i + 1]) t[i] = juntaFolha(t[2*i + 1], t[2*i]);
			else{
				update(2*i, l, m, p);
				update(2*i + 1, m + 1, r, p);
				t[i] =  make_pair(min(t[2*i].first, t[2*i + 1].first), max(t[2*i].second, t[2*i + 1].second));
			}
		}
	}
}

pii ans;

void query(int i, int l, int r, int ql, int qr){
	if(r < ql || l > qr){
		return;
	}
	if(ql <= l && r <= qr){
		if(l == r){
			if()
		}
		else{
			ans.first = min(ans.first, t[i].first);
			ans.second = max(ans.second, t[i].second);
		}

		return;
	}
	int m = (l + r)/2;
	/*
	if(r-l == 1)
		return juntapair(query(2*i, l, m, ql, qr), query(2*i + 1, m+1, r, ql, qr));
	else{
		pair<int, int> u, v;
		u = query(2*i, l, m, ql, qr);
		v = query(2*i + 1, m+1, r, ql, qr);

		return make_pair(min(u.first, v.first), max(u.second, v.second));
	}*/

	pii left = query(2*i, l, m, ql, qr), right = query(2*i+1, m+1, r, ql, qr);
	pii res;
	if(folha[2*i]){
		if(folha[2*i + 1]) res = juntaFolhas(left, right);
		else return res = juntaFolha(left, right);
	}
	else{
		if(folha[2*i + 1]) return res = juntaFolha(right, left);
		else{
			pii u, v;
			query(2*i, l, m, ql, qr);
			query(2*i + 1, m + 1, r, ql, qr);
			res =  make_pair(min(u.first, v.first), max(u.second, v.second));
		}
	}

	ans.first = min(res.first, ans.first);
	ans.second = max(ans.second, res.second);
}


int main(){
	for(int i = 0; i <= 4*MAX; i++) folha[i] = false;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> b[i].first;
		b[i].second = b[i].first;
	}
	build(1, 1, n);

	int op, a, c;
	for(int i = 0; i < m; i++){
		cin >> op >> a >> c;
		if(op == 1){
			b[c].first = min(b[c].first, a);
			b[c].second = max(b[c].second, a);
			update(1, 1, n, c);
		}
		else{
			ans = make_pair(INT_MAX, INT_MIN);

			query(1, 1, n, a, c);
			printf("%d\n", ans.second - ans.first);
		}
	}

}
