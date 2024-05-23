# Heap Data Structure

This repository contains an implementation of a generic heap data structure in C++. The heap is implemented as a template class with a superclass `Heap` that provides all the necessary functionalities for both max-heaps and min-heaps. The `MaxHeap` and `MinHeap` classes are derived from the `Heap` class to provide a clearer interface for the user.

## Features

- **Generic Implementation**: The heap is implemented as a template, allowing it to store elements of any type.
- **Max-Heap and Min-Heap Support**: The `Heap` class can be configured to act as either a max-heap or a min-heap using a template parameter.
- **Dynamic Resizing**: The heap automatically expands and contracts as elements are added or removed.
- **Standard Heap Operations**: The heap supports standard operations such as `push`, `pop`, `top`, and `heapify`.
- **Sorting**: Includes a static method for heap sort.

## Classes

### Heap

The `Heap` class is the base class that implements the core heap functionality. It uses a boolean template parameter to determine whether it is a max-heap or a min-heap.

#### Public Methods

- `Heap()`: Default constructor.
- `Heap(const T *arr, size_t size)`: Constructs a heap from an array.
- `Heap(const std::initializer_list<T> &list)`: Constructs a heap from an initializer list.
- `void push(const T &data)`: Adds an element to the heap.
- `T pop()`: Removes and returns the highest priority element from the heap.
- `const T &top()`: Returns the highest priority element without removing it.
- `bool empty()`: Checks if the heap is empty.
- `size_t getSize()`: Returns the number of elements in the heap.
- `const T *getHeapArray()`: Returns a pointer to the internal array representing the heap.
- `void display()`: Prints the elements of the heap to the standard output.

### MaxHeap

The `MaxHeap` class is derived from `Heap` and configures it to function as a max-heap.

#### Public Methods

- `MaxHeap()`: Default constructor.
- `MaxHeap(const T *arr, size_t size)`: Constructs a max-heap from an array.
- `MaxHeap(const std::initializer_list<T> &list)`: Constructs a max-heap from an initializer list.

### MinHeap

The `MinHeap` class is derived from `Heap` and configures it to function as a min-heap.

#### Public Methods

- `MinHeap()`: Default constructor.
- `MinHeap(const T *arr, size_t size)`: Constructs a min-heap from an array.
- `MinHeap(const std::initializer_list<T> &list)`: Constructs a min-heap from an initializer list.

## Usage

To use the heap data structure, include the appropriate header files in your project and create instances of `MaxHeap` or `MinHeap`.

```cpp
#include "MaxHeap.h"
#include "MinHeap.h"

int main() {
    MaxHeap<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);
    maxHeap.display(); // Output: 20 5 10

    MinHeap<int> minHeap = {10, 5, 20};
    minHeap.display(); // Output: 5 10 20

    return 0;
}
```
