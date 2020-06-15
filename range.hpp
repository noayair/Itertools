#pragma once

namespace itertools{
    class range
    {
        int begin;
        int end;
    public:
        range(int s, int e): begin(s), end(e){}

        class iterator
        {
            int i;
        public:
            iterator(int start = 0): i(start){}

            bool operator==(const iterator &it) const 
            {
                return i == it.i;
            }

            bool operator!=(const iterator &it) const 
            {
                return i != it.i;
            }

            iterator &operator++()
            {
                i++;
                return *this;
            }

            iterator operator++(int)
            {
                iterator temp = *this;
                i++;
                return temp;
            }

            int operator*()
            {
                return i;
            }
        };
    
        iterator begin()
        {
            return iterator(begin);
        }

        iterator end()
        {
            return iterator(end);
        }

    };
};