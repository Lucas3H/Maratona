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
    #define INF 987654321
     
    ll getAns(ll X, ll Y, ll Z){
    	return (X - Y)*(X - Y) + (Y - Z)*(Y - Z) + (X - Z)*(X - Z);
    }
     
    ll nx, ny, nz;
    ll x[MAXN], y[MAXN], z[MAXN];
     
    void solve(){
    	ll ix = 0, iy = 0, iz = 0;
     
    	ll ans = getAns(x[0], y[0], z[0]);
     
    	while(true){
    		ans = min(ans, getAns(x[ix], y[iy], z[iz]));
     
    		if(iy == ny - 1 && ix == nx -1  && iz == nz - 1){
    			break;
    		}
     	
     		if(ix < nx - 1 && iy < ny - 1 && iz < nz - 1){
     			if(x[ix+1] < y[iy+1] && x[ix+1] < z[iz+1]){
     				ix++;
     			}
     			else if(x[ix+1] > y[iy+1] && z[iz+1] > y[iy+1]){
     				iy++;
     			}
     			else iz++;
     		}
     		else if(iy < ny - 1 && iz < nz - 1){
     			if(z[iz+1] < y[iy+1]){
     				iz++;
     			}
     			else iy++;
     		}
     		else if(iy < ny - 1 && ix < nx - 1){
     			if(x[ix+1] < y[iy+1]){
     				ix++;
     			}
     			else iy++;
     		}
     		else if(ix < nx - 1 && iz < nz - 1){
     			if(z[iz+1] < x[ix+1]){
     				iz++;
     			}
     			else ix++;
     		}
     		else if(ix < nx - 1){
     			ix++;
     		}
     		else if(iy < ny - 1){
     			iy++;
     		}
     		else iz++;

     	}
     
    	cout << ans << endl;
    }
     
    int main(){
    	ios::sync_with_stdio(false);
    	ll t;
    	cin >> t;
     
    	while(t--){
    		cin >> nx >> ny >> nz;
     
    		x[nx] = MOD;
    		y[ny] = MOD;
    		z[nz] = MOD;
     
    		fr(i, nx) cin >> x[i];
    		fr(i, ny) cin >> y[i];
    		fr(i, nz) cin >> z[i];
     
    		sort(x, x + nx);
    		sort(y, y + ny);
    		sort(z, z + nz);
     
    		solve();
    	}
    }