#pragma once
#include <iostream>
using namespace std;

namespace itertools{

    class add{
    public:
        template <typename T>
        T operator()(T x, T y) const
        {
            return x + y;
        }
    };

    template <typename container, typename lambda = add>
    class accumulate{
        container cont;
        lambda func;
    public:
        accumulate(container c, lambda f = add): cont(c), func(f){}

        class iterator{
            decltype(*(cont.begin())) sum;
            typename container::iterator it_begin;
            typename container::iteratoiterator begin(){r it_end;
            lambda func;
        public:
            iterator(typename container::iterator begin,typename container::iterator end,lambda f)
            : sum(*begin), it_begin(begin), it_end(end), func(f){}

            bool operator==(const iterator &it) const 
            {
                return it_begin == it.it_begin;
            }

            bool operator!=(const iterator &it) const 
            {
                return it_begin != it.it_begin;
            }

            iterator &operator++(){
            it_begin = it_begin + 1;
            if (it_begin != it_end)
            sum = f(sum,*it_begin);
            return *this;
            }

            const iterator operator++(int){
            iterator temp = *this;
            ++(*this);
            return temp;
            }

            decltype(*(cont.begin()) operator*(){
            return sum;
            }
        };

        iterator begin(){
        return iterator(cont.begin(),cont.end(),this->f);
        }

        iterator end(){
        return iterator(cont.end(),cont.end(),this->f);
        }
    };
    };
}