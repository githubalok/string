#include <bits/stdc++.h>

using namespace std;

void reverse(string &s, int i, int j) {
	while(i <= j) {
		swap(s[i++], s[j--]);
	}
}

string minPalin(string s) {
	int j = 0;
	
	int i = 1;
	string rev_s = s;
	reverse(rev_s.begin(), rev_s.end());
	string ss = s + '#' + rev_s;

	vector<int> p(ss.size());
	p[0] = 0;

	while(i < ss.size()) {
		if(ss[i] == ss[j]) {
			j++; p[i] = j; i++;
		}
		else {
			if(j != 0) j = p[j - 1];
			else p[i] = 0; i++;
		}
	}
	return rev_s.substr(0, rev_s.size() - p[ss.size() - 1]) + s;
}

int main() {
	freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  string s;
  cin >> s;
  cout << minPalin(s);
  cout << endl;
}