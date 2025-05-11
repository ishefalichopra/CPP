#include<bits/stdc++.h>
using namespace std;

int findCelebrity(int n){
    int j = 0;

    for(int i=1;i<n;i++){
        if(knows(j, i)){
            j = i;
        }
    }

    for(int i=0;i<n;i++){
        if(j == i) continue;
        if(knows(j, i) || !knows(i, j))return -1;
    }
    return j;
}

bool knows(int a, int b){
    // This function is a placeholder for the actual implementation
    // In a real scenario, this would check if person 'a' knows person 'b'
    return true; // or false based on the actual logic
}



int main()
{
    int n;
    cin >> n;

    int result = findCelebrity(n);

    if(result == -1){
        cout << "No celebrity found" << endl;
    } else {
        cout << "Celebrity is: " << result << endl;
    }

return 0;
}