void decimalToBinary(int n, int number[]){
//     for(int i = 31;i>=0;i--){
//          number[i] = n%2;
//          n /= 2;
//     }
// }

// int binaryToDecimal(int number[]){
//     int decimal = 0;
//     for(int i=0;i<32;i++){
//         decimal = decimal * 2 + number[i];
//     }
//     return decimal;
// }

// void bitManipulation(int num, int i){
//     int number[32];
//     decimalToBinary(num, number);
//     int index = 32-i;
//     if(number[index] == 1){
//         number[index] = 0;
//         int x = binaryToDecimal(number);
//         cout<<1<<" "<<num<<" "<<x;
//     }else{
//         number[index] = 1;
//         int x = binaryToDecimal(number);
//         cout<<0<<" "<<x<<" "<<num;
//     }
// }