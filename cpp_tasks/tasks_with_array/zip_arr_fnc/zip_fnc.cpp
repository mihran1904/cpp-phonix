#include <iostream>

struct IntPair {
    int first;
    int second;
    IntPair() : first{0},second{0} {};
};

IntPair* zip (const int* arr1,const int* arr2,const int size) {
    IntPair* out_arr = new IntPair[size];
    for (int i = 0; i < size; ++i) {
        out_arr[i].first = arr1[i];
        out_arr[i].second = arr2[i];
    }
    return out_arr;
}
void print_IntPair(const IntPair* arr,const int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << '(' << arr[i].first << " " << arr[i].second << ")\n"; 
    }
    std::cout << std::endl;
}
int main () {
    const int arr_size = 4;
    int arr1[arr_size] = {1,2,3,4};
    int arr2[arr_size] = {5,6,7,8};
    IntPair* zipped = zip(arr1,arr2,arr_size);
    print_IntPair(zipped,arr_size);
    delete[] zipped;
    return 0;
}