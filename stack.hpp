#pragma once

#include "node.hpp"
#include "list.hpp"
#include <iostream>

using namespace std;

template <typename type>
class Stack : private List<type>{
    public:
        // get size
        void copy()
        {

        }

        int getSize(){return List<type>::getSize();}

        // push pop
        void push(type value){List<type>::insertAtLast(value);}
        type pop(){return List<type>::removeAtLast();}

        // getters
        void getTop(){return List<type>::getValueAtLast();}
        void getBottom(){return List<type>::getValueAtFirst();}
};
