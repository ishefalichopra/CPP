#include <bits/stdc++.h>
using namespace std;

class NestedInteger
{
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};


class NestedIterator
{
private:
    stack<NestedInteger> s;

public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (int i = nestedList.size() - 1; i >= 0; i--)
        {
            s.push(nestedList[i]);
        }
    }

    int next()
    {
        if (hasNext())
        {
            int result = s.top().getInteger();
            s.pop();
            return result;
        }
        return -1;
    }

    bool hasNext()
    {

        while (!s.empty())
        {
            NestedInteger curr = s.top();
            if (curr.isInteger())
            {
                return true;
            }
            s.pop();
            const vector<NestedInteger> &nestedList = curr.getList();
            for (int i = nestedList.size() - 1; i >= 0; i--)
            {
                s.push(nestedList[i]);
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}