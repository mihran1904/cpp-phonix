#include <iostream>
int add_with_2(int value) {
    return value + 2;
}

int(*f_ptr)(int) = add_with_2;

int* map(const int* arr,const int size,int(*f_ptr)(int)) {
    int* result = new int[size];
    for (int i = 0; i < size; ++i) {
        result[i] = f_ptr(arr[i]);
    }
    return result;
}

int main () {
    const int arr_size = 4;
    int arr[arr_size] = {1,3,6,7};
    int* mapped = map(arr,arr_size,f_ptr);
    for (int i = 0; i < arr_size; ++i) {
        std::cout << mapped[i] << ' ';
    }
    std::cout << std::endl;
    delete[] mapped;
    return 0;
}