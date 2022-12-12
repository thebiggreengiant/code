#include <iostream>

using namespace std;

# define Size 32

int bin_num[Size];

int increment(int i){
    
    //The counter is for special cases for binary numbers with all 1s
    
    int counter=0;
    
    for(int j = 0; j < i; j++){
        if(bin_num[j] == 1){
            bin_num[j] = 0;
            counter++;
        } else {
            bin_num[j] = 1;
            return i;
        }
    }
    
    if(counter == i){
        for (int j = 0; j < i; j++){
            bin_num[j] = 0;
        }
        bin_num[i] = 1;
        i++;
    }
    return i;
 
}

int main()
{
    int num, k;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter the number of increments: ";
    cin >> k;
    int i = 0;
    while (num > 0) {
        bin_num[i] = num % 2;
        num = num / 2;
        i++;
    }
    
    cout << "The binary equivalent is: ";
    for (int j = i - 1; j >= 0; j--){
        cout << bin_num[j];
    }
    
    for(int j = 0; j < k; j++){
        i = increment(i);
    }
    
    cout << "\nThe value after increment is ";
    for (int j = i - 1; j >= 0; j--){
        cout << bin_num[j];
    }

    return 0;
}
