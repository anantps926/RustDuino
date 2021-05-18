#include<iostream>
#include<string>

using namespace std;

int main(){

	int age , ans;
	string name;

	cout << "What is your name? " << "\n" ;
	getline(cin , name) ;
	cout << "Hello, " << name << "!" << "\n" ;
	cout << "What year were you born? " << "\n" ;
	cin >> age;
	ans = 2021 - age;
	cout << "Congratulations, you are " << ans << " old!" << endl;

	return 0;
}