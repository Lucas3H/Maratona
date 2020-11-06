#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
		ios::sync_with_stdio(false);
    int l;
    string k;
    cin >> l >> k;

    int mid = l/2;

    char s[MAXN];
    fr(i, l) s[l-i-1] = k[i];

    int n1[MAXN], n2[MAXN];
    mem(n1, 0);
    mem(n2, 0);

    int vai_um = 0;

    fr(i, l/2){
        int a = int(s[i]) - '0', b = int(s[i+l/2]) - '0';

				cout << int(s[i]) << a <<" " << b << endl;


        if(vai_um + a + b >= 10) vai_um = 1;
        else vai_um = 0;

        n1[i] = (vai_um + a + b)%10;
    }
    if(vai_um) n1[l/2] = 1;

    vai_um = 0;
    fr(i,  l/2+1){
        int a = s[i] - '0', b = s[i+l/2+1] - '0';

        if(vai_um + a + b >= 10) vai_um = 1;
        else vai_um = 0;

        n2[i] = (vai_um + a + b)%10;
    }
    if(vai_um) n2[l/2+1] = 1;

    frm(i, MAXN){
        if(n1[i] > n2[i]){
            fr(i, l/2) cout << n1[i];
            if(n1[l/2]) cout << n1[l/2];

            return 0;
        }
        else if(n1[i] < n2[i]){
            fr(i, l/2+1) cout << n2[i];
            if(n2[l/2+1]) cout << n2[l/2+1];

            return 0;
        }
    }

    fr(i, l/2) cout << n1[i];
    if(n1[l/2]) cout << n1[l/2];

    return 0;
}
