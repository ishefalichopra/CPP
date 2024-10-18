#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    // Your code here
    int totalPetrol = 0;
    int currPetrol = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        int petrolGain = p[i].petrol - p[i].distance;
        totalPetrol += petrolGain;
        currPetrol += petrolGain;

        if (currPetrol < 0)
        {
            start = i + 1;
            currPetrol = 0;
        }
    }
    return (totalPetrol >= 0) ? start : -1;
}

int main()
{
    int n = 4;
    petrolPump p[n] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    cout << tour(p, n) << endl; // Output: 1

    return 0;
}