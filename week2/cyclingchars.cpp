#include<iostream>
#include<string>
using namespace std;

char convert(char x){
    int cv = int(x)+4;
    if(cv>122) cv=(cv%122)+96;
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