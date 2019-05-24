#include <iostream>
#include <string>
using namespace std;

void serch(string *necklace, string sel, int *src, int size)
{
  int found = -1, i = 0, pos;
  while (found == -1)
  {
    pos = i;
    found = necklace[i].find(sel);
    // cout << found <<i<< endl;
    i++;
    if (i >= size)
      break;
  }
  src[0] = pos;
  src[1] = found + sel.size();
}

void joinNecklace(string *nl, string x, string y, int *nn, int size)
{
  cout << "ok";
  int xx, yy; //,yy,found;
  int src[2]; //yy=src[0],found=src[1]
  xx = stoi(x) - 1;
  yy = stoi(y) - 1;
  if (nl[yy] == "\0")
    nl[yy] = y;
  if (nl[xx] == "\0")
    nl[xx] = x;
  serch(nl, y, src, size);
  // cout << "found: "<< found << endl;
  // cout << "x: " << xx << "y: " <<yy<<endl;
  nl[src[0]] = nl[src[0]].insert(src[1], " " + nl[xx]);
  nl[xx] = "-";
  *nn = src[0];
}

void print(string *necklace, int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << "check: " << necklace[i] << endl;
  }
}

int main()
{
  int s;
  // string necklace[300000];
  cin >> s;
  string necklace[s];
  // cout << size << endl;
  string nn, x, y;
  int f;
  for (int i = 0; i < s - 1; i++)
  {
    cin >> x >> y;
    joinNecklace(necklace, x, y, &f, s);
    // print(necklace,size);
  }
  cout << necklace[f] << endl;
}