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
 
#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321
 
int sum[4*MAXN], left_sum_min[4*MAXN], right_sum_min[4*MAXN], sum_min[4*MAXN];
 
void update(int i, int l, int r, int pos, int val){
	if(l >= r){
		sum[i] = val;
		left_sum_min[i] = val;
		right_sum_min[i] = val;
		sum_min[i] = val;
	}
	else{
		int mid = (l + r)/2;
 
		if(pos <= mid)
			update(2*i, l, mid, pos, val);
		else 
			update(2*i+1, mid+1, r, pos, val);
 
		sum[i] = sum[2*i] + sum[2*i+1];
		
		if(sum[2*i] + left_sum_min[2*i + 1] < left_sum_min[2*i])
			left_sum_min[i] = sum[2*i] + left_sum_min[2*i + 1];
		else
			left_sum_min[i] = left_sum_min[2*i];
		
		if(sum[2*i + 1] + right_sum_min[2*i] < right_sum_min[2*i + 1])
			right_sum_min[i] = sum[2*i + 1] + right_sum_min[2*i];
		else
			right_sum_min[i] = right_sum_min[2*i + 1];
		
		sum_min[i] = min(sum_min[2*i], sum_min[2*i+1]);
		sum_min[i] = min(sum_min[i], right_sum_min[2*i] + left_sum_min[2*i + 1]);
	}
}
 
 
char v[MAXN];
 
int main(){
	int n;
	string s;
 
	cin >> n >> s;
	int ind = 1;
 
	fr(i, n){
 
		if(s[i] == 'R') ind++;
		else if(s[i] == 'L') ind--;
		else if(s[i] == '('){
			update(1, 1, (n+1)/2, ind, 1);
		}
		else if(s[i] == ')'){
			update(1, 1, (n+1)/2, ind, -1);
		}
		else{
			update(1, 1, (n+1)/2, ind, 0);
		}
 
		//cout << sum[1] << " " << left_sum_min[1] << endl;
 
		//cout << sum[1] << endl;

		if(sum[1] == 0 && left_sum_min[1] >= 0){
			cout << abs(sum_min[1]) << " ";
		}
		else cout << -1 << ' ';
	}
 
}