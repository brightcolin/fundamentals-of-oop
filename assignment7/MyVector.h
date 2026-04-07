#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <stdexcept>

template <class T>
class MyVector
{
public:
    MyVector();
    MyVector(int n, const T& val = T());
    MyVector(const MyVector<T>& other);
    ~MyVector();

    MyVector<T>& operator=(const MyVector<T>& other);

    int  size()     const;
    int  capacity() const;
    bool empty()    const;
    void reserve(int n);
    void resize(int n, const T& val = T());
    
    T&       operator[](int i);
    const T& operator[](int i) const;
    T&       at(int i);
    const T& at(int i) const;

    
    void push_back(const T& val);
    void pop_back();
    void clear();

    T* begin();
    T* end();
    const T* begin() const;
    const T* end()   const;

private:
    T*  m_data;
    int m_size;
    int m_capacity;
};


#include "MyVector.tpp"

#endif
