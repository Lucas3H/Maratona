// https://www.spoj.com/problems/TAP2013F/
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

#define eps 0.0000000001

struct vetor{

	double x, y;

	inline vetor operator +(vetor a){ 
		return {x + a.x, y + a.y}; 
	}

	inline vetor operator -(vetor a){
		return {x - a.x, y - a.y};
	}

	inline vetor operator *(double t){
		return {x*t, y*t};
	}

	inline vetor operator /(double t){
		return {x/t, y/t};
	}
	inline double operator ^(vetor a){
		return x*a.y - y*a.x;
	}

	inline double operator *(vetor a){
		return a.x*x + a.y*y;
	}

	inline double comp2(){
		return (*this)*(*this);
	}

	inline double comp(){
		return sqrt((*this)*(*this));
	}

	inline double dist2(vetor a){
		return (a - (*this)).comp2();
	}

	inline double dist(vetor a){
		return sqrt((a - (*this)).comp2());
	}

	inline double angle(vetor a) {
		return atan2((*this)^a, (*this)*a);
	}

	inline vetor proje(vetor a){
		return a*((a*(*this))/a.comp2());
	}

	inline vetor rotate (double a) { 
		return {cos(a)*x - sin(a)*y, sin(a)*x + cos(a)*y};
	}

	inline vetor rot90 () {
		return {y, -x};
	}

	// this is to the (1 left, 0 over, -1 right) of a
	inline int side(vetor a) {
		return (eps < ((*this)^a)) - (((*this)^a) < -eps);
	}

	double dist_line(vetor a, vetor b){
		return (*this)^(b - a)/a.dist(b);
	}
};

struct circle{
	vetor c;
	double r;

	inline int is_inside(vetor a){
		return (r - a.dist(c) > -eps);
	}
};

circle find_circle(vetor a, vetor b, vetor c){
	circle o;
	o.c.y = -((a.x*a.x - c.x*c.x)*(a.x - b.x) + (a.y*a.y - c.y*c.y)*(a.x - b.x) + (b.x*b.x - a.x*a.x)*(a.x - c.x) + (b.y*b.y - a.y*a.y)*(a.x - c.x))/((c.y - a.y)*(a.x - b.x) - (b.y - a.y)*(a.x - c.x))/2;
	o.c.x = -((a.x*a.x - c.x*c.x)*(a.y - b.y) + (a.y*a.y - c.y*c.y)*(a.y - b.y) + (b.x*b.x - a.x*a.x)*(a.y - c.y) + (b.y*b.y - a.y*a.y)*(a.y - c.y))/((c.x - a.x)*(a.y - b.y) - (b.x - a.x)*(a.y - c.y))/2;

	o.r = o.c.dist(a);

	return o;
}

int t;
int n, p;
vetor pt[510];

bool comp1(pair<vetor, int> a, pair<vetor, int> b){
	if(abs(a.f.x - b.f.x) < eps) return a.f.y > b.f.y;
	else return a.f.x < b.f.x;
}

bool comp2(pair<vetor, int> a, pair<vetor, int> b){
	if(abs(a.f.x - b.f.x) < eps) return a.f.y < b.f.y;
	else return a.f.x < b.f.x;
}

circle solve(int a, int b){
	if(pt[a].x > pt[b].x) swap(a, b);

	int sempre_esta = 2;
	int nunca_esta = 0;

	vector<vetor> centro_dir_ponto_dir; 
	vector<vetor> centro_dir_ponto_esq;
	vector<vetor> centro_esq_ponto_dir; 
	vector<vetor> centro_esq_ponto_esq;
	
	fr(i, n){
		if(i == a || i == b) continue;

		circle aux = find_circle(pt[a], pt[b], pt[i]);

		int ss = (pt[i] - pt[a]).side(pt[b] - pt[a]);
		int cs = (aux.c - pt[a]).side(pt[b] - pt[a]);

		if(ss == 0){
			if(abs(pt[i].x - pt[a].x) < eps){
				if((pt[i].y - pt[a].y) >= -eps && (pt[i].y - pt[b].y) <= eps) sempre_esta++;
				else if((pt[i].y - pt[a].y) <= eps && (pt[i].y - pt[b].y) >= -eps) sempre_esta++;
				else nunca_esta++;
			}
			else{
				if((pt[i].x - pt[a].x) >= -eps && (pt[i].x - pt[b].x) <= eps) sempre_esta++;
				else if((pt[i].x - pt[a].x) <= eps && (pt[i].x - pt[b].x) >= -eps) sempre_esta++;
				else nunca_esta++;
			}
		}
		else if(ss == 1 && cs == 1) centro_dir_ponto_dir.pb(aux.c);
		else if(ss == 1 && cs == -1) centro_esq_ponto_dir.pb(aux.c);
		else if(ss == -1 && cs == 1) centro_dir_ponto_esq.pb(aux.c);
		else if(ss == -1 && cs == -1) centro_esq_ponto_esq.pb(aux.c);
	}
/*
	cout << centro_dir_ponto_dir.size() << " " << centro_dir_ponto_esq.size() << " " << centro_esq_ponto_dir.size() << " " << centro_esq_ponto_esq.size() << endl;
	cout << sempre_esta << " " << nunca_esta << endl;
*/
	vector<pair<vetor, int>> direita;
	vector<pair<vetor, int>> esquerda;

	fr(i, centro_dir_ponto_dir.size()) direita.pb(mp(centro_dir_ponto_dir[i], 1));
	fr(i, centro_dir_ponto_esq.size()) direita.pb(mp(centro_dir_ponto_esq[i], -1));

	fr(i, centro_esq_ponto_dir.size()) esquerda.pb(mp(centro_esq_ponto_dir[i], -1));
	fr(i, centro_esq_ponto_esq.size()) esquerda.pb(mp(centro_esq_ponto_esq[i], 1));

	if(pt[a].y < pt[b].y){
		sort(direita.begin(), direita.end(), comp1);
		sort(esquerda.begin(), esquerda.end(), comp2);
	}
	else{
		sort(direita.begin(), direita.end(), comp2);
		sort(esquerda.begin(), esquerda.end(), comp1);
	}
	int dentro = centro_dir_ponto_esq.size() + centro_esq_ponto_dir.size() + sempre_esta;
	int deu1 = 0;
	vetor ans1;
	ans1 = {(pt[a].x + pt[b].x)/2, (pt[a].y + pt[b].y)/2};

	fr(i, direita.size()){
		if(dentro >= p){
			deu1 = 1;
			break;
		}

		dentro+=direita[i].s;
		ans1 = direita[i].f;
	}

	if(dentro >= p){	
		deu1 = 1;
	}

	dentro = centro_dir_ponto_esq.size() + centro_esq_ponto_dir.size() + sempre_esta;
	
	int deu2 = 0;
	vetor ans2;
	ans2= {(pt[a].x + pt[b].x)/2, (pt[a].y + pt[b].y)/2};

	fr(i, esquerda.size()){
		if(dentro >= p){
			deu2 = 1;
			break;
		}

		dentro += esquerda[i].s;
		ans2 = esquerda[i].f;
	}

	if(dentro >= p){
		deu2 = 1;
	}

	circle ret;
	if(deu1 && deu2){
		if(ans1.dist(pt[a]) > ans2.dist(pt[a])){
			ret.c = ans1;
			ret.r = ans1.dist(pt[a]);
		}
		else{
			ret.c = ans2;
			ret.r = ans2.dist(pt[a]);
		}
	}
	else if(deu1 && !deu2){
		ret.c = ans1;
		ret.r = ans1.dist(pt[a]);	
	}
	else if(!deu1 && deu2){
		ret.c = ans2;
		ret.r = ans2.dist(pt[a]);		
	}
	else{
		ret.r = 100000000;
	}

	//cout << a << " " << b << " " << sempre_esta << " " << nunca_esta << endl;

	return ret;
}

void read(){
	cin >> n >> p;
	fr(i, n) cin >> pt[i].x >> pt[i].y;
}

int main(){
	//cin >> t;

	//while(t--){
		read();

		if(p == 1) {
			printf("0.0000\n");
			return 0;
			//continue;
		}
		circle ans;
		ans.r = 100000000;

		circle aux;

		fr(i, n){
			fr(j, i){
				aux = solve(j, i);

				if(-eps < ans.r - aux.r) {
					ans = aux;
				}
			}
		}
		
	/*	fr(i, n) cout << ans.c.dist(pt[i]) <<  " ";
		cout << endl;
 */
		//ans = find_circle(pt[0], pt[1], pt[2]);

		printf("%.4lf\n", ans.r);
		//printf("%.4lf %.4lf %.4lf\n", ans.c.x, ans.c.y, ans.r);
	//}
}
