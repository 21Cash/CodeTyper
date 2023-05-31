#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define PI 3.141592653589793238462
#define rep(i,a,b) for (int i = a; i < b; i++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define db(x) cout<<#x<<" : "<<x<<endl;
#define debug(x) cerr<<#x<<" : "<<x<<endl;
#define pvec(v) cout<<"[";rep(x, 0, v.size()){cout<<v[x];if(x<v.size()-1)cout<<" ";}cout<<"]"<<endl;
#else
#define pvec(v) ;rep(x, 0, v.size()){cout<<v[x];if(x<v.size()-1)cout<<" ";}cout<<endl;
#define db(x)
#define debug(x)
#endif
#define getVal(c) (c-'a'+1)

const int N = 0;

void ReadFile(string &str) {
	std::ifstream t("input.txt");
	std::stringstream buffer;
	buffer << t.rdbuf();
	str = buffer.str();
}


void FindAndReplace(std::string& subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}

void RemoveIndentation(string &str) {
	
	FindAndReplace(str, "    ", "");
	FindAndReplace(str, "		", "");
	FindAndReplace(str, "			", "");
	FindAndReplace(str, "				", "");
	FindAndReplace(str, "					", "");
	FindAndReplace(str, "						", "");
	
}

void WriteToFile(string &str) {
	// cout << str;
	// cerr << "File Formatted" << '\n';
	ofstream outFile("input.txt");
	outFile << str;
	outFile.close();
}

void Solution(){
		
	string str;
	
	ReadFile(str);
	
	RemoveIndentation(str);
	
	WriteToFile(str);
}


signed int main(){
	
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("code.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    #endif
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while(t--){
		Solution();
	}
	return 0;
}