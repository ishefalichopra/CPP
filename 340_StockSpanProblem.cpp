#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
    stack<pair<int, int>> stockStack;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;

        while (!stockStack.empty() && stockStack.top().first <= price)
        {
            span += stockStack.top().second;
            stockStack.pop();
        }
        stockStack.push({price, span});
        return span;
    }
};

int main()
{
    StockSpanner *obj = new StockSpanner();
    cout << obj->next(100) << endl;
    cout << obj->next(80) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(70) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(75) << endl;
    cout << obj->next(85) << endl;

    return 0;
}