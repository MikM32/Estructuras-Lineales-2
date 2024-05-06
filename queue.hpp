#pragma once

#include "node.hpp"
#include "list.hpp"
#include <iostream>

using namespace std;

template <typename type>
class Queue : private List<type>{
    public:

        void copy()
        {

        }

        // get size
        int getSize(){return List<type>::getSize();}

        // push pop
        void enqueue(type value){List<type>::insertAtLast(value);}
        type dequeue(){return List<type>::removeAtFirst();}

        // getters
        void getFirst(){return List<type>::getValueAtFrist();}
        void getLast(){return List<type>::getValueAtLast();}
};
