#include <iostream>

using namespace std;

int k;
const float pi = 3.1415926;
const int *ku_k = &k;

int main() {
    int *u_k = &k;
    cout << "Адрес глобальной неинициализированной переменной (BSS): " << u_k << endl;
    cout << "-------------------------------" << endl;
    
    const float *u_pi = &pi;
    cout << "Адрес глобальной константы (Data): " << u_pi << endl;
    cout << "-------------------------------" << endl;
    
    int a = 25;
    int *u_a = &a;
    cout << "Адрес локальной переменной (Stack): " << u_a << endl;
    cout << "-------------------------------" << endl;
    
    float arr_s[1000];
    cout << "Адрес локального статического массива (Stack): " << arr_s << endl;
    cout << "-------------------------------" << endl;
    
    auto *arr_d = new float[1000];
    cout << "Адрес в памяти массива (Heap): " << arr_d << endl;
    cout << "-------------------------------" << endl;
    delete[] arr_d;
    
    int (*u_main)();
    u_main = main;
    cout << "Адрес в памяти кода функции main (Text): " << u_main << endl;
    cout << "-------------------------------" << endl;
    
    const int **u_ku_k = &ku_k;
    cout << "Адрес указателя-константы: " << u_ku_k << endl;
    cout << "-------------------------------" << endl;
    return 0;
}
