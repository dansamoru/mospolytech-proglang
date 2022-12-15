#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fIn("../in.txt");
    ofstream fOut("../out.txt");
    
    int *arr = (int *) malloc(0), arr_size = 0;
    
    if (fIn) {
        while (!fIn.eof()) {
            arr = (int *) realloc(arr, (arr_size + 1) * sizeof(int));
            fIn >> arr[arr_size++];
        }
    }
    fIn.close();
    
    if (fOut) {
        for (int i = 0; i < arr_size; ++i) {
            fOut << arr[i] * 2 << " ";
        }
    }
    fOut.close();
    return 0;
}
