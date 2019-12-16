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

int n;
string s;
int a, b, dif;

int main(){
	ios::sync_with_stdio(false);

    cin >> n >> s;
    fr(i, n/2){
        if(s[i] == '?') a++;
        else dif-=(s[i]-'0');
    }

    for(int i = n/2; i < n; i++){
        if(s[i] == '?') b++;
        else dif+=(s[i]-'0');
    }
    
    if(dif != 9*(a-b)/2){
        cout << "Monocarp" << endl;
    }
    else cout << "Bicarp" << endl;
}
