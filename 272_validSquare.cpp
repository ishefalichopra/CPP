#include <bits/stdc++.h>
using namespace std;

double length(vector<int> &p1, vector<int> &p2)
{
    return sqrt(pow(p2[0] - p1[0], 2) + pow(p2[1] - p1[1], 2));
}

bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                 vector<int> &p4)
{
    vector<double> lengths = {length(p1, p2), length(p1, p3),
                              length(p1, p4), length(p2, p3),
                              length(p2, p4), length(p3, p4)};

    // Sort the lengths to easily compare the sides and diagonals
    sort(lengths.begin(), lengths.end());

    // A valid square has 4 equal smaller lengths (sides) and 2 equal larger
    // lengths (diagonals)
    return lengths[0] > 0 && // sides should be positive
           lengths[0] == lengths[1] && lengths[1] == lengths[2] &&
           lengths[2] == lengths[3] && lengths[4] == lengths[5];
}

int main()
{
    vector<int> p1 = {0, 0};
    vector<int> p2 = {1, 1};
    vector<int> p3 = {1, 0};
    vector<int> p4 = {0, 1};
    cout << validSquare(p1, p2, p3, p4) << endl;

    return 0;
}