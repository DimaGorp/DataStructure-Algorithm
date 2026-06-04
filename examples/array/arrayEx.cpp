#include <functional>
#include <optional>
#include <iostream>
#include "array.hpp"
#include "array"

std::ostream& operator<<(std::ostream& os,const std::array<int, 10>& arr){
    for(const int& element:arr)
        os<<element<<" ";
    return os;
}

//Sorting

//buble sort
template<typename T>
using condition_func = std::function<bool(const T&first,const T&second)>;
template<typename T, size_t n>
void bubleSort(std::array<T, n>& array, const condition_func<T>& condition){
    for (int i =0; i<array.size();i++) {
        for (int j =0; j<array.size()-1; j++) {
            if(condition(array[j],array[j+1])) std::swap(array[j],array[j+1]);
        }
    }
}
//TODO: merge sort


//Searching

//linear search
template<typename T, size_t n>
std::optional<T> linSearch(std::array<T,n>& arr, const T& value){
    for (int i = 0; i<arr.size(); i++) {
        if(arr[i] == value) return arr[i];
    }
    return {};
}
//binary search
template<typename T, size_t n>
std::optional<T> binSearch(std::array<T,n>& arr, const T& value){
    int left = 0;
    int right = (int)arr.size()-1;
    int middle = (left+right)/2;
    while (left<=right) {
        if(arr[middle] == value) return arr[middle];
        (arr[middle] < value)? left = middle +1 : right = middle - 1;
        middle = (left+right)/2;
    }
    return {};
}

int main()
{
    
    std::cout << "=========std::array============\n";
    {
        std::array<int, 10> array = {1,2,3,4,5,6,7,8,9,11};
        std::printf("First element: %d, Last element:  %d\n",array.front(),array.back());
        std::cout << "Array: "<< array <<std::endl;
        std::printf("Size: %ld, Max Size: %ld\n",array.size(),array.max_size());
        std::printf("Is Empty: %d\n",array.empty());
        //take index of
        std::printf("Element under index %d is %d\n",8,array.at(8));
        //std::printf("Element under index %d is %d\n",-1,array.at(-1));
        //Get Raw Array
        int * arr = array.data();
        std::cout << "Raw array: ";
        for (int i =0; i<10; i++)
            std::printf("%d ",arr[i]);
        std::cout << std::endl;
        //Fill array;
        array.fill(25);
        std::cout << "Array after fill(): "<< array <<std::endl;
    
        //operator [];
        array[8] = 10;
        std::cout << "Array after set 10 to index 8: "<< array <<std::endl;
    
        //swaping arrays
        std::array<int, 10> array2 = {1,2,3,4,5,6,7,8,9,10};
        array.swap(array2);
        std::cout << "Swapping arrays:\nArray1: "<<array<<"\nArray2: "<<array2 <<"\n";
        //operator=
        array = array2;
        std::cout << "Array: "<<array<<std::endl;
        //logical operators
        std::printf("Array1 == Array2: %d\n"
                    "Array1 != Array2: %d\n"
                    "Array1 > Array2: %d\n"
                    "Array1 < Array2: %d\n"
                    "Array1 >= Array2: %d\n"
                    "Array1 <= Array2: %d\n"
                    ,array == array2,
                     array != array2,
                     array > array2,
                     array < array2,
                     array >= array2,
                     array <= array2);
        
        std::array<int,10> emptyArr;
        std::cout << "Empty Arr:" << emptyArr<<std::endl;
        array = {1,2,3,4,5,6,7,8,9,10};
        std::cout << "Array: "<<array<<std::endl;
        std::cout << linSearch(array, 5).value_or(INT64_MAX) <<" "<< linSearch(array, 11).value_or(INT64_MAX)<< std::endl;
        //std::sort(array.begin(), array.end());
        bubleSort<int, 10>(array, [](const int& a, const int& b) {
                return a > b;
        });
        std::cout << "Sorted array: "<<array<<std::endl;
        std::cout << binSearch(array, 5).value_or(INT64_MAX) <<" "<< binSearch(array, 11).value_or(INT64_MAX)<< std::endl;
    }
    std::cout << "=========My Array============\n";
    Custom::array<int,10> MyArray;
    //MyArray = {1};
    std::cout << "Array: "<< MyArray <<std::endl;
    return 0;
}
