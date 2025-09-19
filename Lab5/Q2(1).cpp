#include <iostream>
using namespace std;
void printnum(int n) {
	if (n==1) {
		cout<<1<<endl;
		return ;
	}
	else {
		cout<<n<<endl;
		printnum(n-1);
	}
}
int main() {
	int n;
	cout << "Enter number: ";
	cin>>n;
	printnum(n);
}
