#pragma once
#include <iostream>
using namespace std;

namespace itertools{
    template <typename container1, typename container2>
    class compress{
        container1 cont1;
        container2 cont2;
    public:
        compress(container1 co1, container2 co2): cont1(co1), cont2(co2){}

        class iterator{
            typename container1::iterator it_begin1;
            typename container2::iterator it_begin2;
            typename container1::iterator it_end;
        public:
            iterator(typename container1::iterator begin1,typename container2::iterator begin2, typename container1::iterator end)
            : it_begin1(begin1), it_begin2(begin2), it_end(end){}

            bool operator==(const iterator &it) const 
            {
                return it_begin1 == it.it_begin1;
            }

            bool operator!=(const iterator &it) const 
            {
                return it_begin1 != it.it_begin1;
            }

            iterator &operator++(){
            it_begin1 = it_begin1 + 1;
            it_begin2 = it_begin2 + 1;
            while (it_begin1 != it_end && !(*it_begin2))
            {
            it_begin1++;
            it_begin2++;
            }
            return *this;
            }

            const iterator operator++(int){
            iterator temp = *this;
            ++(*this);
            return temp;
            }

            decltype(*(begin1.begin())) operator*(){
            if(!(*it_begin2)) ++*this;
            return *it_begin1;
            }
        };

        iterator begin(){
        return iterator(begin1.begin(),begin2.begin(),begin1.end());
        }

        iterator end(){
        return iterator(begin1.end(),begin2.begin(),begin1.end());
        }
    };
}