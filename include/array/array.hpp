#pragma once
#include <ostream>


namespace Custom {
    template<typename T, unsigned int n =1>
    class array
    {
    protected:
        T arr[n];
        unsigned int size = n;
    public:
        template<typename T,unsigned int n>
        friend std::ostream& operator<<(std::ostream& os, const array<T, n>& arr);
        array();
          
    };
    template<typename T, unsigned int n>
    array<T,n>::array()
    {
        std::cout << "array constructor" << std::endl;
        std::printf("Array size: %d\n",size);
    }
    template<typename T, unsigned int n>
    std::ostream& operator<<(std::ostream& os, const array<T, n>& arr)
    {
        for (unsigned int i = 0; i < arr.size; i++)
        {
            os << arr.arr[i] << " ";
        }
        return os;
    }
}
