//
// Created by Hassan Attar on 2024-03-07.
//

#ifndef HEAP_MINHEAP_H
#define HEAP_MINHEAP_H


#include "Heap.h"
template<typename T>
class MinHeap : public Heap<T, false> {
public:
    MinHeap();
    MinHeap(const T *arr, size_t size);
    MinHeap(const std::initializer_list<T> &list);
};

template<typename T>
MinHeap<T>::MinHeap(): Heap<T, false>(){}

template<typename T>
MinHeap<T>::MinHeap(const T *arr, size_t size) : Heap<T, false>(arr, size){}

template<typename T>
MinHeap<T>::MinHeap(const std::initializer_list<T> &list): Heap<T, false>(list){}


#endif //HEAP_MINHEAP_H
