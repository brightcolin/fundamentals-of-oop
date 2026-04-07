// MyVector.tpp
// Do not compile this file separately; it is included by MyVector.h

template <class T>
MyVector<T>::MyVector()
    : m_data(NULL), m_size(0), m_capacity(0)
{}

template <class T>
MyVector<T>::MyVector(int n, const T& val)
    : m_data(NULL), m_size(0), m_capacity(0)
{
    reserve(n);
    for(int i = 0; i < n; i++)
        m_data[i] = val;
    m_size = n;
}

// copy constructor: deep copy
template <class T>
MyVector<T>::MyVector(const MyVector<T>& other)
    : m_data(NULL), m_size(0), m_capacity(0)
{
    reserve(other.m_size);
    for(int i = 0; i < other.m_size; i++)
        m_data[i] = other.m_data[i];
    m_size = other.m_size;
}

template <class T>
MyVector<T>::~MyVector()
{
    delete[] m_data;
    m_data = NULL;
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
    if(this == &other) return *this;
    delete[] m_data;
    m_data = NULL;
    m_size = 0;
    m_capacity = 0;
    reserve(other.m_size);
    for(int i = 0; i < other.m_size; i++)
        m_data[i] = other.m_data[i];
    m_size = other.m_size;
    return *this;
}

template <class T>
int MyVector<T>::size() const { return m_size; }

template <class T>
int MyVector<T>::capacity() const { return m_capacity; }

template <class T>
bool MyVector<T>::empty() const { return m_size == 0; }

// if n > current capacity, allocate new memory and copy data
template <class T>
void MyVector<T>::reserve(int n)
{
    if(n <= m_capacity) return;
    T* newData = new T[n];
    for(int i = 0; i < m_size; i++)
        newData[i] = m_data[i];
    delete[] m_data;
    m_data = newData;
    m_capacity = n;
}

template <class T>
void MyVector<T>::resize(int n, const T& val)
{
    if(n > m_capacity) reserve(n);
    for(int i = m_size; i < n; i++)
        m_data[i] = val;
    m_size = n;
}

template <class T>
T& MyVector<T>::operator[](int i) { return m_data[i]; }

template <class T>
const T& MyVector<T>::operator[](int i) const { return m_data[i]; }

template <class T>
T& MyVector<T>::at(int i)
{
    if(i < 0 || i >= m_size)
        throw std::out_of_range("MyVector::at: index out of range");
    return m_data[i];
}

template <class T>
const T& MyVector<T>::at(int i) const
{
    if(i < 0 || i >= m_size)
        throw std::out_of_range("MyVector::at: index out of range");
    return m_data[i];
}

// when capacity is full, double it (same strategy as std::vector)
template <class T>
void MyVector<T>::push_back(const T& val)
{
    if(m_size == m_capacity){
        int newCap = (m_capacity == 0) ? 1 : m_capacity * 2;
        reserve(newCap);
    }
    m_data[m_size] = val;
    m_size++;
}

template <class T>
void MyVector<T>::pop_back()
{
    if(m_size > 0) m_size--;
}

template <class T>
void MyVector<T>::clear()
{
    m_size = 0;
}

template <class T>
T* MyVector<T>::begin() { return m_data; }

template <class T>
T* MyVector<T>::end() { return m_data + m_size; }

template <class T>
const T* MyVector<T>::begin() const { return m_data; }

template <class T>
const T* MyVector<T>::end() const { return m_data + m_size; }
