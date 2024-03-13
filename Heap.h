//
// Created by Hassan Attar on 2024-03-07.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
#include <initializer_list>


template<typename T, bool isMaxHeap = true>
class Heap {
    using size_t = unsigned int;
protected:
    T *heap;
    size_t size;
    size_t capacity;
    void heapify();
    static void moveUp(T *heap, size_t size, size_t i);
    static void swap(T *x, T *y);
    void moveDown(size_t i);
    void moveUp(size_t i);
    inline constexpr bool isValidIndex(size_t i);
    bool shrinkHeap();
    bool expandHeap();
    static inline bool hasHigherPriority(const T &x, const T &y);     // Max/Min Heap only differ in the way they prioritize data
public:
    static inline constexpr size_t getParent(size_t i);
    static inline constexpr size_t getRightChild(size_t i);
    static inline constexpr size_t getLeftChild(size_t i);
    static void heapify(T *arr, size_t size);
    static void heapSort(T *arr, size_t size);
    static void push(T *heap, size_t size, const T &data);
    static void pop(T *heap, size_t size);
    static size_t isHeapUntil(const T *heap, size_t size);
    static inline bool isHeap(const T *heap, size_t size);
    static void moveDown(T *heap, size_t size, size_t i);


    static const size_t INITIAL_CAPACITY;
    Heap();
    Heap(const T *arr, size_t size);
    Heap(const std::initializer_list<T> &list);

    void push(const T &data);
    T pop();
    const T &top();
    inline constexpr bool empty();
    inline constexpr size_t getSize();
    const T *getHeapArray();
    void display();
};
// ####################################################
// ################# STATIC INTERFACE #################
// ####################################################
template<typename T, bool isMaxHeap>
void Heap<T, isMaxHeap>::moveUp(T *heap, Heap::size_t size, Heap::size_t i) {
    if(i > size) return;
    size_t parent = getParent(i);
    while(i != 0 && hasHigherPriority(heap[i], heap[parent])){
        swap(&heap[i], &heap[parent]);
        i = parent;
        parent = getParent(i);
    }
}

template<typename T, bool isMaxHeap>
void Heap<T, isMaxHeap>::moveDown(T *heap, Heap::size_t size, Heap::size_t i) {
    size_t highestPriorityChild = getLeftChild(i);
    while(highestPriorityChild < size){
        if(highestPriorityChild + 1 < size && hasHigherPriority(heap[highestPriorityChild + 1], heap[highestPriorityChild])) {
            highestPriorityChild++;
        }
        if(hasHigherPriority(heap[highestPriorityChild], heap[i])) {
            swap(&heap[highestPriorityChild], &heap[i]);
        }else{
            break;
        }
        i = highestPriorityChild;
        highestPriorityChild = getLeftChild(i);
    }
}

template<typename T, bool isMaxHeap>
void Heap<T, isMaxHeap>::push(T *heap, Heap::size_t size, const T &data) {
    heap[size++] = data;
    moveUp(heap, size, size - 1);
}

template<typename T, bool isMaxHeap>
void Heap<T, isMaxHeap>::pop(T *heap, Heap::size_t size) {
    if(size == 0){
        throw std::runtime_error("heap is empty");
    }
    swap(&heap[0], &heap[--size]);
    moveDown(heap, size, 0);
}

template<typename T, bool isMaxHeap>
void Heap<T, isMaxHeap>::heapify(T *arr, Heap::size_t size) {
    int j = getParent(size - 1);
    while(j >= 0){
        moveDown(arr, size, j);
        j--;
    }
}

template<typename T, bool isMaxHeap>
void Heap<T, isMaxHeap>::heapSort(T *arr, Heap::size_t size) {
    heapify(arr, size);
    while(size > 1){
        swap(&arr[--size], &arr[0]);
        moveDown(arr, size, 0);
    }
}

template<typename T, bool isMaxHeap>
typename Heap<T, isMaxHeap>::size_t Heap<T, isMaxHeap>::isHeapUntil(const T *heap, Heap::size_t size) {
    size_t i = 0;
    size_t highestPriorityChild = 1;
    while(highestPriorityChild < size){
        if(highestPriorityChild + 1 < size && hasHigherPriority(heap[highestPriorityChild + 1], heap[highestPriorityChild])) {
            highestPriorityChild++;
        }
        if(hasHigherPriority(heap[highestPriorityChild], heap[i])) {
            break;
        }
        i++;
        highestPriorityChild = getLeftChild(i);
    }
    return highestPriorityChild + 1;
}

template<typename T, bool isMaxHeap>
bool Heap<T, isMaxHeap>::isHeap(const T *heap, Heap::size_t size) {
    return isHeapUntil(heap, size) == size;
}

template<typename T, bool isMaxHeap>
void Heap<T, isMaxHeap>::swap(T *x, T *y) {
    T temp = std::move(*x);
    *x = std::move(*y);
    *y = std::move(temp);
}


template<typename T, bool isMaxHeap>
inline constexpr typename Heap<T, isMaxHeap>::size_t Heap<T, isMaxHeap>::getParent(Heap<T, isMaxHeap>::size_t i) {
    return (i - 1) / 2;
}

template<typename T, bool isMaxHeap>
inline constexpr typename Heap<T, isMaxHeap>::size_t Heap<T, isMaxHeap>::getLeftChild(Heap<T, isMaxHeap>::size_t i) {
    return i * 2 + 1;
}

template<typename T, bool isMaxHeap>
inline constexpr typename Heap<T, isMaxHeap>::size_t Heap<T, isMaxHeap>::getRightChild(Heap<T, isMaxHeap>::size_t i) {
    return i * 2 + 2;
}

template<typename T, bool isMaxHeap>
inline constexpr bool Heap<T, isMaxHeap>::isValidIndex(Heap<T, isMaxHeap>::size_t i) {
    return i < size; // i cannot be negative (unsigned type)
}

template<typename T, bool isMaxHeap>
bool Heap<T, isMaxHeap>::hasHigherPriority(const T &x, const T &y) {
    if constexpr (isMaxHeap){
        return x > y;
    }else {
        return x < y;
    }
}

template<typename T, bool isMaxHeap>
const typename Heap<T, isMaxHeap>::size_t Heap<T, isMaxHeap>::INITIAL_CAPACITY = 16;


// ####################################################
// ############### Non-Static INTERFACE ###############
// ####################################################

// ######## Constructors ########
template<typename T, bool isMaxHeap>
Heap<T, isMaxHeap>::Heap(): heap{new T[Heap<T, isMaxHeap>::INITIAL_CAPACITY]}, size{0}, capacity{Heap<T, isMaxHeap>::INITIAL_CAPACITY} {}

template<typename T, bool isMaxHeap>
Heap<T, isMaxHeap>::Heap(const T *arr, size_t _size): size{_size}, capacity{1} {
    while(capacity < size){
        capacity <<= 1;
    }
    heap = new T[capacity];
    for(int i = 0; i < size; i++){
        heap[i] = arr[i];
    }
    heapify();
}

template<typename T, bool isMaxHeap>
Heap<T, isMaxHeap>::Heap(const std::initializer_list<T> &list): size{static_cast<Heap<T, isMaxHeap>::size_t>(list.size())}, capacity{1} {
    while(capacity < size){
        capacity <<= 1;
    }
    heap = new T[capacity];
    int i = 0;
    for(const T &x : list){
        heap[i++] = x;
    }
    heapify();
}

// ######## Helper Methods ########
template<typename T, bool isMaxHeap>
bool Heap<T, isMaxHeap>::shrinkHeap() {
    if(2 * size <= capacity && capacity > Heap<T, isMaxHeap>::INITIAL_CAPACITY){
        return false;
    }
    T *oldHeap = heap;
    capacity >>= 1;
    heap = new T[capacity];
    for(int i = 0; i < size; i++){
        heap[i] = oldHeap[i];
    }
    delete oldHeap;
    return true;
}

template<typename T, bool isMaxHeap>
bool Heap<T, isMaxHeap>::expandHeap() {
    if(capacity >= size * 2){
        return false;
    }
    T *oldHeap = heap;
    capacity <<= 1;
    heap = new T[capacity];
    for(int i = 0; i < size; i++){
        heap[i] = oldHeap[i];
    }
    delete oldHeap;
    return true;
}

// ######## Public Non-Static Interface ########
template<typename T, bool isMaxHeap>
inline constexpr bool Heap<T, isMaxHeap>::empty() {
    return size == 0;
}

template<typename T, bool isMaxHeap>
inline constexpr typename Heap<T, isMaxHeap>::size_t Heap<T, isMaxHeap>::getSize() {
    return size;
}

template<typename T, bool isMaxHeap>
const T *Heap<T, isMaxHeap>::getHeapArray() {
    return heap;
}

template<typename T, bool isMaxHeap>
void Heap<T, isMaxHeap>::push(const T &data) {
    if(size == capacity){
        expandHeap();
    }
    heap[size++] = data;
    moveUp(size - 1);
}

template<typename T, bool isMaxHeap>
T Heap<T, isMaxHeap>::pop() {
    if(size == 0){
        throw std::runtime_error("heap is empty");
    }
    T x = heap[0];
    heap[0] = heap[--size];
    moveDown(0);
    return x;
}

template<typename T, bool isMaxHeap>
const T &Heap<T, isMaxHeap>::top() {
    if(size == 0){
        throw std::runtime_error("heap is empty");
    }
    return heap[0];
}


template<typename T, bool isMaxHeap>
void Heap<T, isMaxHeap>::moveUp(Heap<T, isMaxHeap>::size_t i) {
    if(!isValidIndex(i)) return;
    moveUp(heap, size, i);
}

template<typename T, bool isMaxHeap>
void Heap<T, isMaxHeap>::moveDown(Heap<T, isMaxHeap>::size_t i) {
    if(!isValidIndex(i)) return;
    moveDown(heap, size, i);
}

template<typename T, bool isMaxHeap>
void Heap<T, isMaxHeap>::heapify() {
    heapify(heap, size);
}


// Simple Display Method
template<typename T, bool isMaxHeap>
void Heap<T, isMaxHeap>::display() {
    for(int i = 0; i < size; i++){
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}



#endif //HEAP_HEAP_H
