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

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        vector<int> odd;
        vector<int> even;

        fr(i, s.size()){
            if((s[i] - '0')%2 == 0) even.pb(s[i]-'0');
            else odd.pb(s[i]-'0');
        }

        int i = 0, j = 0;

        vector<int> ans;

        fr(i, even.size()){
            while(j < odd.size() && odd[j] < even[i]){
                ans.pb(odd[j]);
                j++;
            }

            ans.pb(even[i]);
        }

        while(j < odd.size()){
            ans.pb(odd[j]);
            j++;
        }

        fr(i, s.size()) cout << ans[i];
        cout << endl;
    }
}
