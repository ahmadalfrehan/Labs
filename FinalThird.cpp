#include <iostream>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
template <class R,
         class Container = vector<R>,
         class Compar = less<typename Container::value_type>
         >
class P_queue
{
    int back;
    int front;
    int length;
    R *arr;
    int MaXSize;

public:
    P_queue(int size)
    {
        if (size <= 0)
            MaXSize = 100;
        else
            MaXSize = size;

        front = 0;

        arr = new R[MaXSize];
        back = MaXSize - 1;
        length = 0;
    }
    int isEmpty()
    {
        return length == 0;
    }
    bool isFull()
    {
        return length == MaXSize;
    }
    void Push(R Element)
    {
        if (isFull())
        {
            cout << "Queue Full Can't push ...!";
        }
        else
        {

            back = (back + 1) % MaXSize;
            arr[back] = Element;
            length++;
        }
    }
    void Pop()
    {
        if (isEmpty())
        {
            cout << "Empty Queue Can't Pop ...!";
        }
        else
        {
            sort(arr, arr + MaXSize);
            front = (front + 1) % MaXSize;
            --length;
        }
    }
    int frontQueue()
    {
        assert(!isEmpty());
        return arr[front];
    }
    int backQueue()
    {
        assert(!isEmpty());
        return arr[back];
    }

    void printQueue()
    {
        if (!isEmpty())
        {
            sort(arr, arr + MaXSize);
            for (size_t i = front; i != back; i = (i + 1) % MaXSize)
            {
                cout << arr[i] << " ";
            }
            cout << arr[back];
        }
        else
            cout << "Empty Queue";
    }
};
class lesss
{
    bool Operation(int l, int rr)
    {
        return l > rr;
    }
};
int main()
{
    vector<pair<int, string> > v;
    vector<pair<int, string> > v2;
    P_queue<int, vector<int>, lesss> buys(8);
    P_queue<int, vector<int>, lesss> sell(8);
    int n, a;
    cout << "enter the  of Sales or Purchases " << endl;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cout << "enter the name of Buyer " << i+1 << endl;
        cin >> s;
        a=rand()%(30-15+1)+15;
        v.push_back(make_pair(a, s));
    }
    for (int i = 0; i < n; i++)
    {
        cout << "enter the name of seller " << i+1 << endl;
        cin >>s;
        a=rand()%(30-15+1)+15;
        v2.push_back(make_pair(a, s));
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < n; i++)
    {
        if (v2[i].first <= v[i].first)
        {
            cout << "Transaction Number " << i + 1 << " Successful" << endl;
            cout << "the details is : the name of Buyer is " << v[i].second << endl
                 << "the name of seller is " << v2[i].second << endl
                 << "the price is :" << v2[i].first << endl;
        }
        else
        {
            cout << "Transaction Number " << i + 1 << " did not work" << endl;
        }
    }
    return 0;
}
