#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<double> pq1; // max-heap for smaller half
    priority_queue<double, vector<double>, greater<double>> pq2; // min-heap for larger half

    void balanceHeaps(){
        if (pq1.size() > pq2.size() + 1) {
            pq2.push(pq1.top());
            pq1.pop();
        } else if (pq2.size() > pq1.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (pq1.empty() || num <= pq1.top()) {
            pq1.push(num);
        } else {
            pq2.push(num);
        }
        balanceHeaps();
    }
    
    double findMedian() {
        if (pq1.size() == pq2.size()) {
            return (pq1.top() + pq2.top()) / 2.0;
        }else{
            return pq1.top();
        }
        
    }
};


int main()
{
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2.0

return 0;
}