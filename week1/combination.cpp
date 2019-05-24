#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int fact(int n){
    if (n == 0)
       return 1;
    return n * fact(n - 1);
}
int path(char p){
    int x=0,y=0;
    if(p=='N') x+=1;
    else if(p=='E') y+=1;
    else if(p=='S') x-=1;
        else if(p=='W') y-=1;
    return x,y;
}

int *combination(int n, int r,string p) {
    int distance[(fact(n)/(fact(r)*fact(n-r)))];
    int count = 0;
    vector<bool> v(n);
    fill(v.end() - r, v.end(), true);
    do {
        int row[3]={};
        int x=0,y=0;
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                // cout << (i +1) << " ";
                // pool[count][i] = i+1;                
                x,y +=p[i];
            }
        }
        distance[count]=x+y;
        count++;
        // cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
    return distance;
}

int main(){
    string p;
    cin >> p;
}
