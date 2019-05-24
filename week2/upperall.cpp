#include<iostream>
#include<string>
using namespace std;

char convert(char x){
    int cv = int(x);
    if (cv>=97 && cv<=122) cv-=32;
    return char(cv);
}

int main(){
    string text;
    cin >> text;
    for(int i=0;i<text.length();i++){
        cout << convert(text[i]);
    }
    cout << endl;
}