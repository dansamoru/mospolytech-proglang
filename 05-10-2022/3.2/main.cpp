#include <iostream>

using namespace std;

int k;
const float pi = 3.1415926;
const int *ku_k = &(k);

int main() {
    int *u_k = &(k);
    cout << "Адрес глобальной неинициализированной переменной (BSS): " << u_k << endl;
    cout << "-------------------------------" << endl;
    
    const float *u_pi = &(pi);
    cout << "Адрес глобальной константы (Data): " << u_pi << endl;
    cout << "-------------------------------" << endl;
    
    int a = 25;
    int *u_a = &(a);
    cout << "Адрес локальной переменной (Stack): " << u_a << endl;
    cout << "-------------------------------" << endl;
    
    const int **u_ku_k = &(ku_k);
    cout << "Адрес указателя-константы: " << u_ku_k << endl;
    cout << "-------------------------------" << endl;
    return 0;
}
