#include<iostream>
#include<string>
#include<vector>
#include<cstdio>

using namespace std;

int main(){
    // string word;
    // string signal;
    vector<char> signal;
    vector<char> word;
    char tmp='0';
    int count =0;
    int pointing =0;
    cin >> noskipws;
    // cin >> word;
    // scanf("%s",signal);
    while(cin>>tmp && tmp!='\n'){
        word.push_back(tmp);
    }

    while(cin>>tmp && tmp!='\n'){
        ;
            // cout << "0";
        signal.push_back(tmp);
        if(tmp=='\n')
            cout <<1;
    }

    if(word.size()>=19)
        return 0;
    // getline(cin,signal);
    for(int i=0;i<signal.size();i++){
        if(pointing == word.size()-1){
            pointing=0;
            count++;
            
        }
        else if(signal[i]==word[pointing])
            pointing++;   
    }
    cout << count << endl;
}