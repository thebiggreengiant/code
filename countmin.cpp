#include <iostream>

using namespace std;

int arr1[6], arr2[6];

int h1(char a){
    int hash = 5;
    hash = (hash*82)+a;
    hash = hash % 6;
    return hash;
}

int h2(char b){
    int hash = 5;
    hash = (hash*50)+b;
    hash = hash % 6;
    return hash;
}

void insert(char x){
    int a = h1(x);
    int b = h2(x);
    
    if(!arr1[a]){
        arr1[a] = 1;
    } else {
        arr1[a]++;
    }
    
    if(!arr2[b]){
        arr2[b] = 1;
    } else {
        arr2[b]++;
    }
}

int main()
{
    insert('a');
    insert('c');
    insert('a');
    insert('b');
    insert('c');
    
    for(int i = 0; i < 6; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    for(int i = 0; i < 6; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
