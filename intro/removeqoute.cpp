#include <iostream>
using namespace std;

void remove_quotes(char *src, char *dest)
{
    int i = 0;
    int j = 0;
    *(dest + j) = *(src + i);
    while (*(src + i) != '\0')
    {
        if (*(src + i) != '\'' && *(src + i) != '\"')
            j++;
        i++;
        *(dest + j) = *(src + i);
    }
}

int main()
{
    char st[1000];
    char out[1000];
    int l;

    cin.getline(st, 1000);
    remove_quotes(st, out);

    cout << out << endl;
}