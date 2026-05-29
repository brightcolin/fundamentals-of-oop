#ifndef CP_DYNARRAY_H
#define CP_DYNARRAY_H

#include <iostream>
#include <utility>
using namespace std;

template<typename T>
class CP_DynArray
{
private:
    T* m_data;

public:
    CP_DynArray() noexcept : m_data(nullptr)
    {
        cout << "  CP_DynArray default ctor, m_data=" << m_data << endl;
    }

    explicit CP_DynArray(T* ptr) noexcept : m_data(ptr)
    {
        cout << "  CP_DynArray pointer ctor, m_data=" << m_data << endl;
    }
    
    CP_DynArray(CP_DynArray&& other) noexcept : m_data(other.m_data)
    {
        other.m_data = nullptr;
        cout << "  CP_DynArray move ctor, m_data=" << m_data << endl;
    }

    ~CP_DynArray() noexcept
    {
        cout << "  CP_DynArray destructor, deleting m_data=" << m_data << endl;
        if (m_data != nullptr)
        {
            delete m_data;
            m_data = nullptr;
        }
    }

    CP_DynArray& operator=(CP_DynArray&& other) noexcept
    {
        cout << "  CP_DynArray move assignment" << endl;
        if (this != &other)
        {
            if (m_data != nullptr)
            {
                cout << "    releasing old m_data=" << m_data << endl;
                delete m_data;
            }
            m_data = other.m_data;
            other.m_data = nullptr;
        }
        return *this;
    }

    CP_DynArray(const CP_DynArray&) = delete;
    CP_DynArray& operator=(const CP_DynArray&) = delete;

    T* mb_get() const noexcept
    {
        return m_data;
    }

    void mb_swap(CP_DynArray& other) noexcept
    {
        T* tmp = m_data;
        m_data = other.m_data;
        other.m_data = tmp;
        cout << "  CP_DynArray swap" << endl;
    }

    T& operator*() const noexcept { return *m_data; }
    T* operator->() const noexcept { return m_data; }

    explicit operator bool() const noexcept { return m_data != nullptr; }
};

#endif
