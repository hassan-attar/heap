//
// Created by Hassan Attar on 2024-03-07.
//

#ifndef HEAP_MAXHEAP_H
#define HEAP_MAXHEAP_H

#include <iostream>
#include "Heap.h"

template<typename T>
class MaxHeap : public Heap<T, true>{
public:
public:
    MaxHeap();
    MaxHeap(const T *arr, size_t size);
    MaxHeap(const std::initializer_list<T> &list);
};

template<typename T>
MaxHeap<T>::MaxHeap():Heap<T, true>() {}

template<typename T>
MaxHeap<T>::MaxHeap(const T *arr, size_t size) : Heap<T, true>(arr, size){}

template<typename T>
MaxHeap<T>::MaxHeap(const std::initializer_list<T> &list): Heap<T, true>(list){}


#endif //HEAP_MAXHEAP_H
