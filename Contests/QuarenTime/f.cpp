#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0; i<n; i++)
#define sz(v) (int)(v).size()
#define prin(a) cout << #a << " = " << a << endl
#define all(v) (v).begin(),(v).end()
#define eb emplace_back

#define prinp(p) cout << p.x << "," << p.y << endl;

typedef long long ll;
typedef pair<int,int> pll;

struct pt{
    int x, y;
    int id;
    pt(){}
    pt(int xx, int yy, int ii = -1){
        x = xx, y = yy, id = ii;
    }
    
    pt operator -(pt p2){
        return pt(x-p2.x,y-p2.y);
    }
    
    ll operator ^(pt p2){
        return (ll)x*p2.y-(ll)y*p2.x;   
    }
};

bool operator <(const pt &p1, const pt &p2){
    return pll(p1.x,p1.y)<pll(p2.x,p2.y);
}

bool operator ==(const pt &p1, const pt &p2){
    return pll(p1.x,p1.y)==pll(p2.x,p2.y);
}

vector<pt> mch(vector<pt> v){
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    
    vector<pt> ans;
    
    fr(cor,2){
        vector<pt> h;
        fr(i,v.size()){
            while(h.size()>=2){
                pt v1 = h.back()-h[h.size()-2];
                pt v2 = v[i]-h.back();
                if( (v1^v2) > 0 ) break;
                h.pop_back();
            }
            h.eb(v[i]);
        }
        fr(i,(int)h.size()-1){
            ans.eb(h[i]);
        }
        reverse(all(v));
    }
    
    return ans;
}

ll getarea(vector<pt> &v){
	vector<pt> ch = mch(v);
	
	set<int> s;
	for(auto &p : ch){
		//prinp(p);
		s.insert(p.id);
	}
	ll area = 0;
	for(int i = 1; i<sz(ch)-1; i++){
        pt v1 = ch[i]-ch[0];
        pt v2 = ch[(i+1)%sz(ch)]-ch[0];
        area += abs(v1^v2);
    }
    //prin(area);
    ch.clear();
	
	int i = 0;
	while(!s.count(v[i].id)) i++;
	int io = i;
	int n = sz(v);
	bool ja_vi = 0;
	while(i<sz(v)){
		vector<pt> a;
		if(i==io and ja_vi){
			goto fim;
		} else ja_vi = 1;
		while(s.count(v[(i+1)%n].id)){
			i = (i+1)%n;
			if(i==io) goto fim;
		}
		a.eb(v[i]);
		i = (i+1)%n;
		while(!s.count(v[i].id)){
			a.eb(v[i]);
			i = (i+1)%n;
		}
		a.eb(v[i]);
		area -= getarea(a);
		a.clear();
	}
	fim:
	return area;
}

int main(){
	ll t;
	cin >> t;
	ll area = 0;
	
	fr(tt,t){
		vector<pt> v;
		ll x, y;
		ll n;
		scanf("%lld", &n);
		
		fr(i,n){
			scanf("%lld%lld", &x, &y);
			v.emplace_back(x,y,i);
		}
		area+=getarea(v);
	}
	cout << area/2 << endl;
}