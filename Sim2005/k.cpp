#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue
	
#define ll long long

#define MAXN 100010

struct submission{
	int time, problem, student, correct;
};

bool ordenacao(submission a, submission b){
	return a.time < b.time;
}

int main(){
	//cout << int('0') << endl;

	int tests;
	cin >> tests;

	while(tests--){
		int prob, stu, k;
		cin >> prob >> stu >> k;

		int first_to_solve[31];
		int incorrect[31][31];
		int first_attempt[31];

		mem(first_to_solve, -1);
		mem(incorrect, 0);
		mem(first_attempt, 0);

		int first_correct = -1;
		int last_correct = -1;
		int st_most_first_attempt = 1;
		int most_first_attempt = 0;
		int most_incorrect = 1;

		submission s[10010];

		fr(i, k){
			int pro, stu, cor;
			cin >> pro >> stu >> cor;

			string str;
			cin >> str;

			int ti = (str[0] - 48)*10000 + (str[1] - 48)*1000 + (str[2] - 48)*100 + (str[4] - 48)*10 + (str[5] - 48);

			s[i].time = ti;
			s[i].problem = pro;
			s[i].student = stu;
			s[i].correct = cor;
		}

		sort(s, s + k, ordenacao);

		int inc = -1;

		fr(i, k){
			int p = s[i].problem, st = s[i].student;

			if(s[i].correct){
				
				if(first_correct == -1) first_correct = st;

				if(first_to_solve[p] == -1) first_to_solve[p] = st; 

				if(inc < incorrect[st][p]){
					inc = incorrect[st][p];
					most_incorrect = st;
				}
				else if(inc == incorrect[st][p] && st < most_incorrect) most_incorrect = st;

				if(incorrect[st][p] == 0){
					first_attempt[st]++;
//					cout << "first attempt: " << st << endl; 

					if(first_attempt[st] > most_first_attempt){
						st_most_first_attempt = st;
						most_first_attempt = first_attempt[st]; 
//						cout << st_most_first_attempt << endl;
					}
					else if(first_attempt[st] == most_first_attempt && st < st_most_first_attempt) st_most_first_attempt = st; 
				}

				last_correct = st;
			}
			else incorrect[st][p]++;

			//cout << s[i]. problem << " " << s[i].student << " " << s[i].correct << " " << s[i].time << endl;
		}

		frr(i, prob) cout << first_to_solve[i] << " ";
		cout << endl;

		cout << first_correct << " " << last_correct << " " << st_most_first_attempt << " " << most_incorrect << endl;
	}
}