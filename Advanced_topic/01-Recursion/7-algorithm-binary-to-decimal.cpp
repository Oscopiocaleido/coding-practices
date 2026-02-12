#include <iostream>

using namespace std;

void toBinary(unsigned int n){
    if(n < 2){
        cout << n;
        return;
    }
    toBinary(n / 2);
    cout << n % 2;
}

void toHex(unsigned int n){
    if(n >= 16) toHex(n / 16);

    int dig = n % 16;

    if(dig < 10){
        cout << dig;
    }else {
        switch (dig) {
            case 10: cout<< "A"; break;
            case 11: cout<< "B"; break;
            case 12: cout<< "C"; break;
            case 13: cout<< "D"; break;
            case 14: cout<< "E"; break;
            case 15: cout<< "F"; break;
        }
    }
}

int main(){
    int n = 0;
    cin >> n;

    cout << "0x";
    toHex(n);
    cout<<" = ";
    toBinary(n);
    cout<<endl;

    return 0;
}
