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

int main(){
	ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int a[MAXN];

    set<int> left;
    set<int> app;

    int days = 0, len = 0, deu = 1;
    vector<int> ans;
    fr(i, n){
        cin >> a[i];
        len++;

        if(a[i] < 0){
            if(app.find(-a[i]) == app.end()) deu = 0;
            else{
                app.erase(-a[i]);
                left.insert(-a[i]);
            }
        }
        else{
            if(app.find(a[i]) != app.end() || left.find(a[i])!=left.end()){
                deu = 0;
            }
            else{
                app.insert(a[i]);
            }
        }

        if(app.empty()){
            days++;
            ans.pb(len);
            len = 0;

            app.clear();
            left.clear();
        }
    }

    if(!app.empty()){
        deu = 0;
    }

    if(deu){
        cout << days << endl;

        fr(i, days){
            cout << ans[i] << " ";
        }
    }
    else{
        cout << -1 << endl;
    }
}
