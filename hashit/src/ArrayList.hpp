// ArrayList.hpp

/**
*   Author: Byung Ho Lee
*   Student ID# 60626811
*
*   Header file of ArrayList Class
*
**
*/

#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <string>

template <class T> 
class ArrayList
{

public:
    ArrayList();
    ArrayList(unsigned int initCapacity);
    ArrayList(const ArrayList<T>& a);
    ~ArrayList();

    ArrayList<T>& operator=(const ArrayList<T>& a);

    T* at(unsigned int index) const;

    void add(T* t, unsigned int index);

    void updateBucket(T* t, unsigned int index);

    // size() returns the size of the ArrayList.
    unsigned int size() const;

    // capacity() returns the capacity of the ArrayList.
    unsigned int capacity() const;

    unsigned int getNumberOfAccount() const;

    void setCapacity(unsigned int capacity);
    
    // increaseSize() increases size of the ArrayList
    void increaseSize();

    // decreaseSIze() decreases size of the ArrayList
    void decreaseSize();

    void setItems(T** newItems, unsigned int newCap);

    T** getItems();
 
private:

    T** items;
    unsigned int sz;
    unsigned int numberOfAccount;
    unsigned int cap;
};

#include "ArrayList.cpp"


#endif // ARRAYLIST_HPP