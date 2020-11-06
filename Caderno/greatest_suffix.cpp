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
typedef pair<ll, ll> pll;
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

class Solution {
public:
    string lastSubstring(string s){
        int n=s.size(),i=0,j=1,k=0;
        while(j + k < n){
            if(s[i+k] == s[j+k]) k++; 
            else if(s[i+k]<s[j+k]) {
            	i = k + 1, 
            	k = 0; 
            	if(i >= j) i++;
           	}
            else {
            	j = j + k + 1;
            	k = 0;
            }
        }
        return s.substr(i);
    }
};


int main(){
	ios::sync_with_stdio(false);
}