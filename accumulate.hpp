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
    public:
        container cont;
        lambda func;
    public:
        accumulate(container c, lambda f = add()): cont(c), func(f){}

        class iterator{
            decltype(*(cont.begin())) sum;
            typename container::iterator it_begin;
            typename container::iterator it_end;
            lambda func;
        public:
            iterator(typename container::iterator b,typename container::iterator e,lambda f)
            : sum(*b), it_begin(b), it_end(e), func(f){}

            bool operator==(const iterator &it) const 
            {
                return it_begin == it.it_begin;
            }

            bool operator!=(const iterator &it) const 
            {
                return it_begin != it.it_begin;
            }

            iterator &operator++(){
            ++it_begin;
            if (it_begin != it_end)
            sum = func(sum,*it_begin);
            return *this;
            }

            const iterator operator++(int){
            iterator temp = *this;
            ++(*this);
            return temp;
            }

            decltype(*(cont.begin())) operator*(){
            return sum;
            }
        };

        iterator begin(){
        return iterator(cont.begin(),cont.end(),this->func);
        }

        iterator end(){
        return iterator(cont.end(),cont.end(),this->func);
        }
    };
    
}



// #include <iostream>
// using namespace std;
// namespace itertools{
// class add {
// public:
//     template <typename T>
//     T operator()(T x, T y) const {
//         return x + y;
//     }
// };     
// template <typename container,typename lambda = add>
// class accumulate {
//     public:
//     container cont;
//     lambda func;

// public:
//      accumulate (container c,lambda l=add())
//     :cont(c),f(l){}

//     class iterator{
//         decltype(*(cont.begin())) sum;
//         typename container::iterator it_start;
//         typename container::iterator it_end;
//         lambda f;

//     public:
//          iterator(typename container::iterator start,typename container::iterator end,lambda _f) 
//         :it_start(start),it_end(end),f(_f),sum(*start){};

//         iterator &operator++() {
//             ++it_start;
//             if (it_start != it_end)
//             sum = f(sum,*it_start);
//             return *this;
//         }

//         const iterator operator++(int) {
//             iterator temp = *this;
//             ++(*this);
//             return temp;
//         }

//         bool operator==(const iterator &other) const {
//             return it_start == other.it_start;
//         }

//         bool operator!=(const iterator &other) const {
//             return it_start != other.it_start;
//         }

//         decltype(*(cont.begin())) operator*() {
//             return sum;
//         }

//     };

//     iterator begin() {
//         return iterator(cont.begin(),cont.end(),this->f);
//     }

//     iterator end() {
//         return iterator(cont.end(),cont.end(),this->f);
//     }
// };
// }