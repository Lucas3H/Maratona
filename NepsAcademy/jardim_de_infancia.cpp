#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int, int> racional; 
typedef pair<racional, racional> reta;
typedef pair<int, int> ponto;
typedef pair<int, int> vetor;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 100010

int produto_escalar(vetor a, vetor b){
	return a.first*b.first + a.second*b.second;
}

int modulo_produto_vetorial(vetor a, vetor b){
	return a.first*b.second - a.second*b.first;
}

int dist(ponto a, ponto b){
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

racional soma(racional a, racional b){
	return mp(a.first*b.second + a.second*b.first, a.second*b.second);
}

racional subtracao(racional a, racional b){
	return mp(a.first*b.second - a.second*b.first, a.second*b.second);
}

racional mult(racional a, racional b){
	return mp(a.first*b.first, a.second*b.second);
}

racional div(racional a, racional b){
	return mp(a.first*b.second, a.second*b.first);
}

reta reta_por_dois_pontos(ponto a, ponto b){
	racional inclinacao = mp(a.second - b.second, a.first - b.first);
	racional eixo_y = subtracao( mp(a.second, 1), mult(inclinacao, mp(a.first, 1)));

	return mp(inclinacao, eixo_y);
}

racional intersec_x(reta r, reta s){
	 return div(subtracao(r.second, s.second), subtracao(s.first, r.first));
}

int main(){	
	ponto p[8];
	frr(i, 7) {
		int x, y;
		cin >> x >> y;

		p[i] = mp(x, y);
	}
	int pinheiro = 1;

	// Condicao 1:
	vetor v1 = mp(p[2].first - p[1].first, p[2].second - p[1].second);
	vetor v2 = mp(p[3].first - p[1].first, p[3].second - p[1].second); 
	if(produto_escalar(v1, v2) <= 0) pinheiro = 0;
	
	//Condicao 2:
	if(dist(p[1], p[2]) != dist(p[1], p[3])) pinheiro = 0;

	//Condicao 3:
	vetor u1 = mp(p[3].first - p[2].first, p[3].second - p[2].second);
	vetor u2 = mp(p[4].first - p[2].first, p[4].second - p[2].second);
	vetor u3 = mp(p[5].first - p[2].first, p[5].second - p[2].second);

	if(modulo_produto_vetorial(u1, u2) != 0 || modulo_produto_vetorial(u1, u3) != 0) pinheiro = 0;

	//Condicao 4:
	ponto p1 = mp(p[2].first+p[3].first, p[2].second + p[3].second);

	ponto p2 = mp(p[4].first+p[5].first, p[4].second + p[5].second);

	if(p1 != p2) pinheiro = 0;

	//Condicao 5:
	if(dist(p[2], p[3]) <= dist(p[4], p[5])) pinheiro = 0;

	//Condicao 6:
	vetor w1 = mp(p[6].first - p[4].first, p[6].second - p[4].second);
	vetor w2 = mp(p[7].first - p[5].first, p[7].second - p[5].second);
	vetor w3 = mp(p[3].first - p[2].first, p[3].second - p[2].second);

	if(produto_escalar(w1, w3) != 0 || produto_escalar(w2, w3) != 0) pinheiro = 0;
	

	//Condicao 7:
	if(dist(p[4], p[6]) != dist(p[5], p[7])) pinheiro = 0;

	// Condicao 8:
	reta r = reta_por_dois_pontos(p[2], p[3]);
	reta s = reta_por_dois_pontos(p[1], p[6]);

	racional q = intersec_x(r, s);

	if(q.second == 0) pinheiro = 0;
	else{
		double k = (double)q.first/(double)q.second;

		if(k > max(p[1].first, p[6].first) || k < min(p[1].first, p[6].first)) pinheiro = 0;

		if(k > max(p[2].first, p[3].first) || k < min(p[2].first, p[3].first)) pinheiro = 0;
	}

	if(pinheiro) cout << "S" << endl;
	else cout << "N" << endl;

	return 0;
	
}