#include <iostream>
#include <string>
using namespace std;

void serch(string* necklace,string sel,int* src){
  int found=-1,i=0,pos;
  while (found==-1){
    pos = i;
    found = necklace[i].find(sel);
    // cout << found <<i<< endl;
    i++;
  }
  src[0]=pos;
  src[1]=found+sel.size();
}

void joinNecklace(string* nl,string x,string y,int* nn){
  int xx;//,yy,found;
  int src[2]; //yy=src[0],found=src[1]
  xx = stoi(x)-1;
  // nl[stoi(y)-1]=y;
  if (nl[xx]=="\0") nl[xx] = x;
  serch(nl,y,src);
  // yy = serch(nl,y);
  // found = nl[yy].find(y)+y.size();
  // cout << "found: "<< found << endl;
  // cout << "x: " << xx << "y: " <<yy<<endl;
  nl[src[0]] = nl[src[0]].insert(src[1]," "+nl[xx]);
  nl[xx] = "-";
  *nn= src[0];
}

// int check(string* necklace,string* new_n,int size){
//   int count = 0;
  // for(int i=0;i<size;i++){
  //   cout << "check: " << necklace[i] << endl;
//     if (necklace[i]=="-") count +=1;
//     else *new_n = necklace[i]; 
//   }
//   return count;
// }

void print(string* necklace,int size){
  for(int i=0;i<size;i++){
    cout << "check: " << necklace[i] << endl;
  }
}

int main() {
  int size;
  cin >> size;
  string necklace[size];
  for(int i=0;i<size;i++){
    necklace[i]= to_string(i+1);
  }
  // for(int i=0;i<size;i++){
  //   cout << necklace[i] << endl;
  // }
  string nn,x,y;
  int f;
  for(int i=0;i<size-1;i++){
    cin >> x >> y;
    joinNecklace(necklace,x,y,&f);
    print(necklace,size);
    // int c = check(necklace,&nn,size);
    // if (c==size-1) break;
  }
    cout << "check: " << necklace[size-1] << endl;
  cout << necklace[f] << endl;
}