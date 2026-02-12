#include <iostream>

using namespace std;

int m_c_d(int a, int b){
    if(a == b) return a;
    if(a > b) return m_c_d(a - b, b);
    return m_c_d(a, b - a);
}

int main(){
    int a = 0, b = 0;

    cin>> a >> b;
    cout<< m_c_d(a, b) <<endl;

    return 0;
}
