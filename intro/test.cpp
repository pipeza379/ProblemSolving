#include<iostream>
#include<string>
using namespace std;

int main(){
    string s = "def ";
    s.append("abc ab");
    cout << s << endl;
    int found = s.rfind("g");
    cout << found << endl;
}