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

    int k;
    cin >> k;

    while(k--){
        int n;
        cin >> n;

        char s[60], t[60];
        cin >> s >> t;

        int fr[30];
        mem(fr, 0);

        fr(i, n){
            fr[s[i]-'a']++;
            fr[t[i]-'a']++;
        }

        int da = 1;
        fr(i, 26){
            if((fr[i])%2 == 1){
                da = 0;
                break;
            }
        }

        if(da==0){
            cout << "No" << endl;
            continue;
        }

        vector<pii> ans;
        int a = 0;

        fr(i, n-1){
            if(s[i] == t[i]) continue;

            int deu = 0;
            for(int j = i + 1; j < n; j++){
                if(s[j] == s[i]){
                    a++;

                    ans.pb(mp(j, i));
                    swap(s[j], t[i]);
                    deu = 1;

                    break;
                }
            }

            if(deu == 0){
                for(int j = i+1; j < n; j++){
                    if(s[i] == t[j]){
                        a+=2;

                        ans.pb(mp(i+1, j));
                        swap(s[i+1], t[j]);

                        ans.pb(mp(i+1, i));
                        swap(s[i+1], t[i]);

                        break;
                    }
                }
            }
        }

        cout << "Yes" << endl;
        cout << a << endl;

        fr(i, a){
            cout << ans[i].first+1 <<" " << ans[i].second + 1<<endl;
        }
    }
}
