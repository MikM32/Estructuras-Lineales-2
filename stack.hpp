#pragma once

#ifndef STACK_HEADER
#define STACK_HEADER

#include "node.hpp"
#include "list.hpp"
#include <iostream>

using namespace std;

template <typename type>
class Stack : private List<type>{
    public:

        Stack()
        {
            this->size = 0;
            this->first = NULL;
            this->last = NULL;
        }

        Stack(const Stack<type>& stack)
        {
            this->size = 0;
            this->first = NULL;
            this->last = NULL;
            this->copy(stack);
        }

        void copy(const Stack<type>& stack)
        {
            this->clear();

            Node<type>* acum = stack.first;
            for(int i=0; i<stack.size; i++)
            {
                this->push(acum->getValue());
                acum = acum->getNext();
            }
        }

        void copyList(List<type> list)
        {
            this->clear();

            int lSize = list.getSize();
            for(int i=0; i<lSize; i++)
            {
                this->push(list.getValueAtIndex(i));
            }
        }

        void clear()
        {
            if(this->size)
            {
                while(this->size)
                {
                    this->pop();
                }
            }
        }

        bool isEmpty()
        {
            return this->size == 0;
        }

        // get size
        int getSize(){return List<type>::getSize();}

        // push pop
        void push(type value){List<type>::insertAtLast(value);}
        type pop(){return List<type>::removeAtLast();}

        // getters
        void getTop(){return List<type>::getValueAtLast();}
        void getBottom(){return List<type>::getValueAtFirst();}
};
#endif // STACK_HEADER
