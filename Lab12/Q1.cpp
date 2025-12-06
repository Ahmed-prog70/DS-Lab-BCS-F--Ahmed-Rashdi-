#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> bruteForceSearch(string text, string pattern) {
vector<int> index;
int n = text.length();
int m = pattern.length();

	for (int i = 0; i <= n - m; i++) {
	int j = 0;
		while (j < m && text[i + j] == pattern[j]) {
		
		j++;
		}
		if (j == m) { 
	
		index.push_back(i);
		
		}
	}
	return index;
}

int main() {
string text = "the quick brown fox jumps over the lazy dog";
string pattern = "the";
vector<int> res = bruteForceSearch(text, pattern);
for (int i=0; i<res.size(); i++){
	cout<<res[i]<<endl;
}
}
