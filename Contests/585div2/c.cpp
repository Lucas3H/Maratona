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

string s, t;
int n;

stack<int> sa;
stack<int> sb;

int main(){
	ios::sync_with_stdio(false);

    cin >> n;
    cin >> s >> t;

    fr(i, n){
        if(s[i] != t[i]){
            if(s[i] == 'a') sa.push(i + 1);
            else sb.push(i + 1);
        }
    }

    if((sa.size() + sb.size())%2 == 1){
        cout << -1 << endl;
        return 0;
    }

    //if(sa.size() > sb.size()) swap(sa, sb);

    if(sa.size()%2 == 1) cout << sa.size()/2 + sb.size()/2 + 2 << endl;
    else cout << sa.size()/2 + sb.size()/2 << endl;

    while(sa.size() > 1){
        cout << sa.top() << " ";
        sa.pop();
        cout << sa.top() << endl;
        sa.pop();
    }


    while(sb.size() > 1){
        cout << sb.top() << " ";
        sb.pop();
        cout << sb.top() << endl;
        sb.pop();
    }

    if(sa.size() > 0){
        cout << sa.top() << " " << sa.top() << endl;
        cout << sa.top() << " " << sb.top() << endl;
    }

}
