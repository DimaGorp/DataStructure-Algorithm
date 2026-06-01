#include <iostream>
#include "array.hpp"
#include "array"

std::ostream& operator<<(std::ostream& os,const std::array<int, 10>& arr){
    for(const int& element:arr)
        os<<element<<" ";
    return os;
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
    }
    std::cout << "=========My Array============\n";
    Custom::array<int> MyArray;
    std::cout << "Array: "<< MyArray <<std::endl;
    return 0;
}
