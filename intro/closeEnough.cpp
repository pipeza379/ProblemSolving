#include <iostream>
#include <cstdlib> 

using namespace std;

int main()
{
    int n,house,count,c;
    int x[1000] ;
    cin >> n >> house;
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    count = 0;c=0;
    for(int j=0;j<n-1;j++){
        // cout << "j" << j;
        for(int k=j+1;k<n;k++){
            if(abs(x[j]-x[k]) <= house) count++;
            // cout <<"k" <<k;
        }
    }
    cout << count << endl;


}