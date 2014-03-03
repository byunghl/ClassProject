// ArrayList.cpp

/**
*   Author: Byung Ho Lee
*   Student ID# 60626811
*
*   ArrayList Class
*
*   Note: This is generalized arraylist. Its possible to reuse for all data types.
**
*/

#ifndef ARRAYLIST_CPP
#define ARRAYLIST_CPP

#include "ArrayList.hpp"
#include <iostream>

namespace
{
    const unsigned int initialCapacity = 10;

    template<class T>
    void arrayCopy(T* target, T* source, unsigned int capacity)
    {
        for (unsigned int i = 0; i < capacity; i++)
        {
            target[i] = source[i];
        }
    }
}

// default constructor
template<class T>
ArrayList<T>::ArrayList()
{
    items = new T*[initialCapacity];
    for(int i=0;i<initialCapacity;i++) {
        items[i]=nullptr;
    }
    sz = 0;
    numberOfAccount = 0;
    cap = initialCapacity;
}

// Constructor with one parameter. 
template<class T>
ArrayList<T>::ArrayList(unsigned int initCapacity)
{
    items = new T*[initCapacity];
    for(int i=0;i<initCapacity;i++) {
        items[i]=nullptr;
    }
    sz = 0;
    numberOfAccount = 0;
    cap = initCapacity;
}

// Copty constructor
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& a)
{

    items = new T*[a.cap]; 
    for(unsigned int i = 0; i < a.cap; i++) {
         items[i] = nullptr;
    }

    arrayCopy(items, a.items, a.cap);

    sz = a.sz;
    numberOfAccount = a.numberOfAccount;;
    cap = a.cap;

}

// Destructor 
template<class T>
ArrayList<T>::~ArrayList()
{
    delete[] items;
}

// assign operator overload for ArrayList instance
template<class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& a)
{
    if (this != &a)
    {
        T** newItems = new T*[a.cap];
        arrayCopy(newItems, a.items, a.cap);

        sz = a.sz;
        cap = a.cap;

        delete[] items;
        items = newItems;
    }

    return *this;
}

// function that returns element at specific index 
template<class T>
T* ArrayList<T>::at(unsigned int index) const
{
    return items[index];
}

// function that adss element in to specific index with increasing size of an arraylist
template <class T>
void ArrayList<T>::add(T* t,unsigned int index )
{
    items[index] = t;
    increaseSize();
    
}

// function that adds element into specific index of arraylist without increase size of array. Basically, this function allows to modify an element in array list. 
template <class T>
void ArrayList<T>::updateBucket(T* t, unsigned int index){
    items[index] = t;
}

// function that returns size of arraylist.
template <class T>
unsigned int ArrayList<T>::size() const
{
    return sz;
}

// function that returns capacity of arraylist. 
template <class T>
unsigned int ArrayList<T>::capacity() const
{
    return cap;
}

// function that returns number of elements in arrayList.
template <class T>
unsigned int ArrayList<T>::getNumberOfAccount() const
{
    return numberOfAccount;
}

// function that increases size of an arraylist
template <class T>
void ArrayList<T>::increaseSize() {
    sz++;
    numberOfAccount++;
}

// function that decreases size of an arraylist.
template <class T>
void ArrayList<T>::decreaseSize() {
    sz--;
}
// setter function which sets an arraylist
template <class T>
void ArrayList<T>::setItems(T** newItems, unsigned int newCap) {
    
    for(unsigned int i = 0; i < newCap; i++) {
        newItems[i] = nullptr;
    }    

    this->items = newItems;
    cap = newCap;
    sz = 0;
    numberOfAccount = 0;
}
// getter function which returns an arraylist.
template <class T>
T** ArrayList<T>::getItems() {
    return items;
}

#endif