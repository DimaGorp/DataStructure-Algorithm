#pragma once
#include <ostream>
#include <initializer_list>

namespace Custom {

    //Forward Declaration
    template<typename T, size_t n>
    class array;
    template<typename T, size_t n>
    std::ostream& operator<<(std::ostream& os, const array<T, n>& arr);
    
    //array definition
    template<typename T, size_t n =1>
    class array
    {
        protected:
            T m_arr[n];
            size_t m_size = n;
            const T* m_start_iter = m_arr;
            const T* m_end_iter = (m_arr + n -1);
        public:
            friend std::ostream& operator<< <>(std::ostream& os, const array<T, n>& arr);
            array<T,n>& operator=(const array<T,n>& arr);
            array<T,n>& operator=(const std::initializer_list<T>& elements);
            array() = default;
        
    };
}

//Array Implementation
namespace Custom {



    template<typename T, size_t n>
    std::ostream& operator<< (std::ostream& os, const array<T, n>& arr)
    {
        for (unsigned int i = 0; i < arr.m_size; i++)
        {
            os << arr.m_arr[i] << " ";
        }
        return os;
    }
    

    template<typename T, size_t n>
    array<T,n>& array<T, n>::operator=(const std::initializer_list<T>& elements){
        for(int i =0;i<m_size;i++){
            //arr[i] =;
        }
        return *this;
    }
    
    template<typename T, size_t n>
    array<T,n>& array<T, n>::operator=(const array<T,n>& arr){
        if(m_arr == *this) return *this;
        m_size = arr.m_size;
        for(int i =0;i<m_size;i++){
            arr[i] = arr.m_arr[i];
        }
        return *this;
    }
    
}
