#include <bits/stdc++.h>
using namespace std;
void Sort(int A[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n ; j++)
        {
            if (A[j - 1] > A[j])
            {
                temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
            }
        }
    }
}

void Get(int A[], int n, int k)
{

    for (int i = n-1; i >= (n - k ); i--)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    int n, k;
    cout << "Enter the input size" << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "Enter the value of k:" << endl;
    cin >> k;

    Sort(A, n);
    Get(A, n, k);

    return 0;
}