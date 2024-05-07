#pragma once

#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include "node.hpp"
#include "list.hpp"
#include <iostream>

using namespace std;

template <typename type>
class Queue : private List<type>{
    public:

        Queue()
        {
            this->size = 0;
            this->first = NULL;
            this->last = NULL;
        }

        Queue(const Queue<type>& queue)
        {
            this->size = 0;
            this->first = NULL;
            this->last = NULL;
            this->copy(queue);
        }

        void copy(const Queue<type>& queue)
        {
            this->clear();

            Node<type>* acum = queue.first;
            for(int i=0; i<queue.size; i++)
            {
                this->enqueue(acum->getValue());
                acum = acum->getNext();
            }
        }

        void copyList(List<type> list)
        {
            this->clear();

            int lSize = list.getSize();
            for(int i=0; i<lSize; i++)
            {
                this->enqueue(list.getValueAtIndex(i));
            }
        }

        void clear()
        {
            if(this->size)
            {
                while(this->size)
                {
                    this->dequeue();
                }
            }
        }

        // get size
        int getSize(){return List<type>::getSize();}

        // push pop
        void enqueue(type value){List<type>::insertAtLast(value);}
        type dequeue(){return List<type>::removeAtFirst();}

        // getters
        type getFirst(){return List<type>::getValueAtFrist();}
        type getLast(){return List<type>::getValueAtLast();}
};
#endif // QUEUE_HEADER
