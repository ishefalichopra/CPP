#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double a = 9.76553;
    cout << "hey" << setw(6) << "XYZ" << endl;     //setw
    cout<<setprecision(4)<<a<<endl;                //setprecision
    cout<<"hey"<<setw(4)<<setfill('*')<<"XYZ"<<endl;//setfill


    return 0;
}