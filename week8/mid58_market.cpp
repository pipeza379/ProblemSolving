#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef pair<int, int> pairs;
vector<pairs> customer; //price,amount //P,A
vector<pairs> seller;   //price,amount //Q,B

int action, amount, price;
int priceOfEvent = 0;

void event()
{
    if (action == 1 && !seller.empty()) //customer
    {
        cout << "BUYING\n";
        for (int i = seller.size() - 1; i >= 0; i--)
        {
            cout << "round: " << i << endl;
            if (price >= seller[i].first && amount != 0)
            {
                cout << "customer: " << price << " ," << amount << endl;
                cout << "seller: " << seller[i].first << " ," << seller[i].second << endl;

                int p = seller[i].second - amount;
                if (p < 0) //seller don't have product;
                {
                    priceOfEvent += seller[i].second * (seller[i].first);
                    seller.pop_back();
                    amount -= seller[i].second;
                }
                else //seller have product
                {
                    priceOfEvent += amount * (seller[i].first);
                    seller[i].second -= amount;
                    amount = 0;
                }
                cout << "price: " << priceOfEvent << endl;
            }
        }
    }
    else if (action == 2 && !customer.empty()) //seller
    {
        cout << "SELLING\n";
        for (int i = customer.size() - 1; i >= 0; i--)
        {
            cout << "round: " << i << endl;
            if (price <= customer[i].first && amount != 0)
            {
                cout << "seller: " << price << " ," << amount << endl;
                cout << "customer: " << customer[i].first << " ," << customer[i].second << endl;

                int p = customer[i].second - amount;
                if (p < 0) //customer buy finishing;
                {
                    priceOfEvent += customer[i].second * (customer[i].first);
                    customer.pop_back();
                    amount -= customer[i].second;
                }
                else //seller don't have product
                {
                    priceOfEvent += amount * (customer[i].first);
                    customer[i].second -= amount;
                    amount = 0;
                }
                cout << "price: " << priceOfEvent << endl;
            }
        }
    }
}

vector<pairs>::iterator find_pos_min(int L, int R, int value, vector<pairs> add)
{
    int n = (L + R) / 2;
    if (R == -1 || add[0].first > value)
        return add.begin();
    else if (add[add.size() - 1].first < value)
        return add.end();
    else if (add[n].first < value && add[n + 1].first > value || add[n].first == value)
        return add.begin() + n + 1; //**fix for count
    else if (add[n].first > value)
        return find_pos_min(L, n, value, add);
    else if (add[n].first < value)
        return find_pos_min(n + 1, R, value, add);
}

// vector<pairs>::iterator find_pos_max(int L, int R, int value, vector<pairs> add)
// {
//     int n = (L + R) / 2;
//     cout << L << " " << R << " " << add.size() << endl;
//     if (R == -1 || add[0].first < value)
//         return add.begin();
//     else if (add[add.size() - 1].first >= value)
//     {
//         cout << "ok\n";
//         return add.end();
//     }
//     else if (add[n].first > value && add[n + 1].first < value || add[n].first == value)
//         return add.begin() + n + 1; //**fix for count
//     else if (add[n].first > value)
//         return find_pos_min(L, n, value, add);
//     else if (add[n].first < value)
//         return find_pos_min(n + 1, R, value, add);
// }

vector<pairs>::iterator find_pos_max(int L, int R, int value)
{
    int n = (L + R) / 2;
    if (R == 0 || seller[0].first < value)
        return seller.begin();
    else if (seller[seller.size() - 1].first > value)
        return seller.end();
    else if (seller[n - 1].first > value && seller[n].first <= value)
    {
        cout << "test\n";
        return seller.begin() + n; //**fix for count
    }
    else if (seller[n].first > value)
        return find_pos_max(n + 1, R, value);
    else if (seller[n].first < value)
        return find_pos_max(L, n - 1, value);
}

void pushQ()
{
    if (action == 1)
    {
        auto itr = find_pos_min(0, customer.size() - 1, price, customer);
        customer.insert(itr, make_pair(price, amount));
    }
    else if (action == 2)
    {
        auto itr = find_pos_max(0, seller.size(), price);
        seller.insert(itr, make_pair(price, amount));
    }
}

void print()
{
    cout << "\ncustomer\n";
    for (int i = customer.size() - 1; i >= 0; i--)
        cout << customer[i].first << " , " << customer[i].second << endl;
    cout << "seller\n";
    for (int i = seller.size() - 1; i >= 0; i--)
        cout << seller[i].first << " , " << seller[i].second << endl;
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> action >> price >> amount;
        event();
        cout << "check\n";
        cout << price << " ," << amount << endl;
        if (amount > 0)
            pushQ();
        print();
    }
}