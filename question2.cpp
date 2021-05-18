#include<iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
 int count = 0;
 string str,course;
 cout << "Enter a search string: " ;
 getline(cin,str);
 ifstream courses ("courses.txt");
 
 while(getline(courses,course)){
 	if (course.find(str) != std::string::npos) {
    std::cout << course << '\n';
    count++;
	}
 }
 courses.close();
 
 cout<<"Number of matches: " << count << endl;
 return 0;
}