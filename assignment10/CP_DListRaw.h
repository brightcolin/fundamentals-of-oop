#ifndef CP_DLIST_RAW_H
#define CP_DLIST_RAW_H

#include <iostream>
using namespace std;

template<typename T>
class CP_DListRaw
{
private:
    struct Node
    {
        T m_data;
        Node* m_prev;
        Node* m_next;
        Node(const T& data) : m_data(data), m_prev(nullptr), m_next(nullptr) {}
    };

    Node* m_head;
    Node* m_tail;
    int m_size;

public:
    CP_DListRaw() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

    ~CP_DListRaw()
    {
        mb_clear();
    }

    CP_DListRaw(const CP_DListRaw& other) : m_head(nullptr), m_tail(nullptr), m_size(0)
    {
        Node* cur = other.m_head;
        while (cur)
        {
            mb_pushBack(cur->m_data);
            cur = cur->m_next;
        }
    }

    CP_DListRaw& operator=(const CP_DListRaw& other)
    {
        if (this != &other)
        {
            mb_clear();
            Node* cur = other.m_head;
            while (cur)
            {
                mb_pushBack(cur->m_data);
                cur = cur->m_next;
            }
        }
        return *this;
    }

    void mb_pushFront(const T& data)
    {
        Node* node = new Node(data);
        if (!m_head)
        {
            m_head = m_tail = node;
        }
        else
        {
            node->m_next = m_head;
            m_head->m_prev = node;
            m_head = node;
        }
        m_size++;
    }

    void mb_pushBack(const T& data)
    {
        Node* node = new Node(data);
        if (!m_tail)
        {
            m_head = m_tail = node;
        }
        else
        {
            node->m_prev = m_tail;
            m_tail->m_next = node;
            m_tail = node;
        }
        m_size++;
    }

    bool mb_popFront()
    {
        if (!m_head) return false;
        Node* old = m_head;
        m_head = m_head->m_next;
        if (m_head)
            m_head->m_prev = nullptr;
        else
            m_tail = nullptr;
        delete old;
        m_size--;
        return true;
    }

    bool mb_popBack()
    {
        if (!m_tail) return false;
        Node* old = m_tail;
        m_tail = m_tail->m_prev;
        if (m_tail)
            m_tail->m_next = nullptr;
        else
            m_head = nullptr;
        delete old;
        m_size--;
        return true;
    }

    void mb_clear()
    {
        while (m_head)
        {
            Node* tmp = m_head;
            m_head = m_head->m_next;
            delete tmp;
        }
        m_head = m_tail = nullptr;
        m_size = 0;
    }

    int mb_size() const { return m_size; }
    bool mb_empty() const { return m_size == 0; }
    T mb_front() const { return m_head->m_data; }
    T mb_back() const { return m_tail->m_data; }

    void mb_show() const
    {
        cout << "[";
        Node* cur = m_head;
        while (cur)
        {
            cout << cur->m_data;
            if (cur->m_next) cout << " <-> ";
            cur = cur->m_next;
        }
        cout << "]" << endl;
    }

    void mb_showReverse() const
    {
        cout << "[";
        Node* cur = m_tail;
        while (cur)
        {
            cout << cur->m_data;
            if (cur->m_prev) cout << " <-> ";
            cur = cur->m_prev;
        }
        cout << "]" << endl;
    }
};

#endif
