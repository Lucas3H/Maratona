#include<bits/stdc++.h>

using namespace std;

int main(){
	tuple<int, string, double, int> t(0, "Oie", 1.5, 10);

	// Acessar um elemento da tupla:
	cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << " " << endl;

	// Acessar mais facilmente os elmentos de uma tupla:
	int a;
	string b;
	tie(a, b, ignore, ignore) = t; 

	cout << a << ' ' << b << endl;

	return 0;
}