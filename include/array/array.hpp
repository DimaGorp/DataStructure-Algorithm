#pragma once
#include <ostream>
#include <initializer_list>

namespace Custom {
    
    
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
            array() = default;
        
    };
}

//Array Implementation
namespace Custom {



    
    
    
}
