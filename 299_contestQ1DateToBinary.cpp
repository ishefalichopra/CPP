#include <bits/stdc++.h>
using namespace std;
string convertDateToBinary(string date)
{

    // splitting the string and converting to interger format

    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    // converting splitted int number to binary using bitset
    // 2^12-1=4095(limit for year), 2^4-1= 15(12 limit for month),
    // 2^5-1=31(31 limit         //for days)

    string year_binary = bitset<12>(year).to_string();
    string month_binary = bitset<4>(month).to_string();
    string day_binary = bitset<5>(day).to_string();

    // removing the leading zeroes

    year_binary = year_binary.substr(year_binary.find('1'));
    month_binary = month_binary.substr(month_binary.find('1'));
    day_binary = day_binary.substr(day_binary.find('1'));

    return year_binary + "-" + month_binary + "-" + day_binary;
}
int main()
{
    string date = "2021-09-15";
    cout << convertDateToBinary(date);

    return 0;
}