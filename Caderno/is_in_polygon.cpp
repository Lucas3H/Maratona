
#define ll long long
typedef pair<double, double> ponto;

//	crossProd < 0 -> left
//	crossProd > 0 -> right

struct is_in_pol{

    ll n, m, k;
    ponto pol[MAXN], pt[MAXN]; 

    ll crossProd(ponto a, ponto b, ponto c){
	    ll x1 = a.f - b.f, x2 = c.f - b.f;
	    ll y1 = a.s - b.s, y2 = c.s - b.s;

	    return x1*y2 - x2*y1; 
    }



    bool bb(int l, int r, ponto p){
	    if(l == r - 1){
		    if(crossProd(p, pol[l], pol[r]) <= 0) return 1;
		    else return 0;
	    }

	    int mid = (l+r)/2;

	    if(crossProd(pol[0], pol[mid], p) < 0) return bb(mid, r, p);
	    else return bb(l, mid, p);
    }

    void read(){
	    cin >> n >> m >> k;

	    fr(i, n) cin >> pol[i].f >> pol[i].s;
	    fr(i, m) cin >> pt[i].f >> pt[i].s;
    }

    bool is_in_polygon(ponto a){
	    if(crossProd(pol[0], pol[1], a) <= 0 && crossProd(pol[n-1], pol[0], a) <= 0){
		    return bb(1, n-1, a);
	    }
	    else return 0;
    }

};