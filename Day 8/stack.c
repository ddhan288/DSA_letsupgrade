#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int minEle;

void min()
{
    if (s.empty())
        return;
    else
        cout << "Min element: " << minEle << endl;
}

void peek()
{
    if (s.empty())
        return;
    int t = s.top();
    (t < minEle) ? cout << "Top: " << minEle << endl : cout << "Top: " << t << endl;
}

void pop()
{
    if (s.empty())
        return;
    int t = s.top();
    s.pop();
    if (t < minEle)
        minEle = 2 * minEle - t;
}

void push(int x)
{
    if (s.empty())
    {
        minEle = x;
        s.push(x);
        return;
    }
    if (x < minEle)
    {
        s.push(2 * x - minEle);
        minEle = x;
    }
    else
        s.push(x);
}

int main()
{
    int c;
    do
    {
        cout << "0. Exit\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Get min\n";
        cin >> c;
        switch (c)
        {
        case 1:
            int x;
            cout << "Element: ";
            cin >> x;
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            min();
            break;
        }
    } while (c);
    return 0;
}