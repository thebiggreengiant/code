#include <iostream>

using namespace std;

int main()
{
    int *dynamic_arr, *temp_arr, n=1, num;
    cout << "Enter the size of the array:" << endl;
    cin >> num;
    dynamic_arr = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < num; i++){
        if(n >= i){
            dynamic_arr[i] = i;
        } else {
            temp_arr = (int*)malloc(n*sizeof(int));
            n = n*2;
            for(int j = 0; j < i; j++){
                temp_arr[j] = dynamic_arr[j];
            }
            dynamic_arr = (int*)malloc(n*sizeof(int));
            for(int j = 0; j < i; j++){
                dynamic_arr[j] = temp_arr[j];
            }
            dynamic_arr[i] = i;
        }
    }
    
    cout << "The dynamic table is:" << endl;
    for(int i = 0; i < num; i++){
        cout << dynamic_arr[i] << " ";
    }

    return 0;
}
