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
    // getline(cin,signal);
    for(int i=0;i<signal.size();i++){
        // cout << signal[i] <<" ";
        if(signal[i]==word[pointing]){
            if(pointing == word.size()-1){
                // cout << " plus"<<endl;
                pointing=0;
                count++;
                continue;
            }
            pointing++;
            // cout << " plus";
        }
        // cout << endl;
    }
    cout << count << endl;
}