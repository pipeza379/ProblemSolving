#include <iostream>

using namespace std;

int main()
{
    int n,count;
    int j = 0;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    count = 0;
    while (j < n)
    {
        int sum=0;
        for(int k=j;k<n;k++){
            sum += x[k];
            // cout << "k,x[k]: " << k << " "<< x[k] << endl;
            // cout << "sum: " << sum << endl;
            if (sum >1000){
                count++;
                // cout << "count: " << count << endl;
                j=k-1;
                break;
            }    
        }
        if(j+1==n) {
            count++;
            break;
            }
        j++;
    }
    cout << count << endl;
}