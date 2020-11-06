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
typedef pair<ll, ll> pll;
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
#define INF 987654321

const double EPS = 1E-9;

struct pt {
    double x, y;
};

#define PRACIMA 0
#define PRABAIXO 1

struct semi_circle {
	pt center;
	double r;
    int id, tipo;

    semi_circle(){};

    semi_circle(int x, int y, int r, int id, int tipo){center({x, y}), r(r), id(id), tipo(tipo)};

    double get_y(double x){
    	if(tipo == PRACIMA)
    		return (b + sqrt(r*r - (center.x - x)*(center.x - x)));
    	else
    		return (b + sqrt(r*r + (center.x - x)*(center.x - x)));
    }
};

struct circle {
	pt center;
	double r;
    int id;
};

double dist(const semi_circle& a, const semi_circle& b){
	return sqrt((a.center.x - b.center.x)*(a.center.x - b.center.x) + (a.center.y - b.center.y)*(a.center.y - b.center.y))
}

bool intersect(const semi_circle& a, const semi_circle& b){
    return max(a.r, b.r) - min(a.r, b.r) <= dist(a, b) && max(a.r, b.r) - min(a.r, b.r) >= dist(a, b);
}

bool operator<(const semi_circle& a, const semi_circle& b){
    double x = max(a[i].center - a[i].r, b[i].center - b[i].r);
    return a.get_y(x) < b.get_y(x) - EPS;
}

struct event {
    double x;
    int tp, id;

    event() {}
    event(double x, int tp, int id) : x(x), tp(tp), id(id) {}

    bool operator<(const event& e) const {
        if (abs(x - e.x) > EPS)
            return x < e.x;
        return tp > e.tp;
    }
};

set<semi_circle> s;
vector<pair<set<semi_circle>::iterator, set<semi_circle>::iterator>> where;

set<semi_circle>::iterator prev(set<semi_circle>::iterator it) {
    return it == s.begin() ? s.end() : --it;
}

set<semi_circle>::iterator next(set<semi_circle>::iterator it) {
    return ++it;
}

pair<int, int> solve(const vector<circle>& a) {
    int n = (int)a.size();
    vector<event> e;
    for (int i = 0; i < n; ++i) {
        e.push_back(event(a[i].center - a[i].r, 1, i));
        e.push_back(event(a[i].center + a[i].r, -1, i));
    }
    sort(e.begin(), e.end());

    s.clear();
    where.resize(a.size());
    while(!e.empty()) {
        int id = e[i].id;
		semi_circle c1(a[id].center.x, a[id].center.y, a[id].y, i, PRACIMA);
        semi_circle c2(a[id].center.x, a[id].center.y, a[id].y, i, PRABAIXO);	
            
        if (e[i].tp == +1) { 
        	set<semi_circle>::iterator nxt = s.lower_bound(c2), prv = prev(nxt);

            if (nxt != s.end() && intersect(*nxt, c1))
                return make_pair(nxt->id, id);
            if (prv != s.end() && intersect(*prv, c2))
                return make_pair(prv->id, id);
            where[id] = {s.insert(nxt, c2), s.insert(nxt, c1)}
        } 
        else if(e[i].tp == -1){
            set<semi_circle>::iterator nxt = next(where[id].s), prv = prev(where[id].f);
            if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
                return make_pair(prv->id, nxt->id);
            
            s.erase(where[id].f);
            s.erase(where[id].s);
        }
    }

    return make_pair(-1, -1);
}


int main(){
	ios::sync_with_stdio(false);
}
