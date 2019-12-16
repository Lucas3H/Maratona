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
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}


int main(){
	ios::sync_with_stdio(false);

    int q;
    cin >> q;

    while(q--){
        ll n, k;
        cin >> n;

        pq<ll> A, B, nao_usado, mmc;

        ll p;
        frr(i, n) {
            cin >> p;
            nao_usado.push(p);
        }
        ll a, x, b, y;
        cin >> x  >> a >> y >> b;

        cin >> k;

        if(x < y){
            swap(x, y);
            swap(a, b);
        }

        ll ans = 0;
        ll tick = 0;

        frr(i, n){
            if(i%a == 0 && i%b != 0){
                if(B.empty()){
                    ans += nao_usado.top()*x/100;
                    A.push(nao_usado.top());
                    nao_usado.pop();
                    tick = i;
                }
                else{
                    ans -= B.top()*y/100;
                    ans += B.top()*x/100;

                    ans += nao_usado.top()*y/100;

                    A.push(B.top());
                    B.pop();

                    B.push(nao_usado.top());
                    nao_usado.pop();

                    tick = i;
                }
            }
            if(i%b == 0 && i%a != 0){
                ans += nao_usado.top()*y/100;
                B.push(nao_usado.top());
                nao_usado.pop();

                tick = i;
            }
            if(i%b == 0 && i%a == 0){
                if(A.empty()){
                    if(B.empty()){
                        ans += nao_usado.top()*(x+y)/100;
                        mmc.push(nao_usado.top());
                        nao_usado.pop();
                    }
                    else{
                        ans += B.top()*x/100;
                        mmc.push(B.top());
                        B.pop();

                        ans+= nao_usado.top()*y/100;
                        B.push(nao_usado.top());
                        nao_usado.pop();
                    }
                }
                else{
                    ans += A.top()*y/100;
                    mmc.push(A.top());
                    A.pop();

                    if(B.empty()){
                        ans += nao_usado.top()*x/100;
                        A.push(nao_usado.top());
                        nao_usado.pop();
                    }
                    else{
                        ans -= B.top()*y/100;
                        ans += B.top()*x/100;

                        ans += nao_usado.top()*y/100;

                        A.push(B.top());
                        B.pop();

                        B.push(nao_usado.top());
                        nao_usado.pop();
                    }
                }

                tick = i;
            }

            //cout << ans << endl;

            if(ans >= k) break;
        }

        if(ans >= k) cout << tick << endl;
        else cout << -1 << endl;
    }
}
