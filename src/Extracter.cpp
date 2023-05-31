#include <bits/stdc++.h>
#include <fstream>
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
bool completedFormatting = false;

string res = "";

void ReadFile(string &str) {
	std::ifstream t("input.txt");
	std::stringstream buffer;
	buffer << t.rdbuf();
	str = buffer.str();
}		

void Process(string &str) {
	
	
	string::iterator it;
	string::iterator s;
	string::iterator e;
	
	bool foundStartIterator = false;
	bool foundEndIterator = false;
	
	for (it = str.begin(); it != str.end(); it++) {
		
		char c = *it;
		if(c == '<') {
			foundStartIterator = true;
			s = it;
		}
		else if(c == '>') {
			e = it;
			foundEndIterator = true;
			break;
		}
    }	
    if(foundStartIterator && foundEndIterator) {
	    str.erase(s, e+1);
	    // cerr << "Excess Data Erased" << "\n";
    }
    if(!foundStartIterator && !foundEndIterator) {
    	completedFormatting = true;
    }	
}


void FindAndReplace(std::string& subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}

void PostProcess(string &str) {
	
	// Replace Unneccessary things
	
	FindAndReplace(str, "&amp;", "&");
	FindAndReplace(str, "&lt;", "<");
	FindAndReplace(str, "&gt;", ">");
	
	
	//Insert New Line After #include 
	FindAndReplace(str, "<stdio.h>", "<stdio.h>\n");
	
	
	// Convert void main() into int main()
	FindAndReplace(str, "void main()", "int main()");
	
	// Format Into Lines
	FindAndReplace(str, ";", ";\n");	
}


void FormatString(string &str) {
	
	//Format The File
	while(!completedFormatting) {
		Process(str);
	}
	
	// Post Processing
	PostProcess(str);
	
}

void Solution(){
	
	string str;
	ReadFile(str);
	
	FormatString(str);
	
	// cout << str;
	ofstream outFile("input.txt");
	outFile << str;
	outFile.close();
}


signed int main(){
	
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("extractedcode.txt", "w", stdout);
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


// Commented Code


// This Removes The &amp and Inserts New Line After Every Semi Colon
// void FinalPass(string &str) {
	
// 	string::iterator it;
// 	for(it = str.begin(); it != str.end(); it++) {
		
// 		// Deleting the amp After & i.e ---> &amp;
// 		if(*it == '&' && *(it+1) == 'a') {
// 			auto ref = str.erase(it, (it+5));
// 			it = ref;
// 		}
		
		
// 		if(*it == ';') {
// 			auto ref = str.insert(it+1, '\n');
// 			it = ref+1;
// 		}
// 	}
	
// 	// Add #include <stdio.h> and main Function
// 	str.insert(0, "#include<stdio.h>\n\nint main() {\n");
// 	str.insert(sz(str)-1, "\nreturn 0;\n}");
	
// }
