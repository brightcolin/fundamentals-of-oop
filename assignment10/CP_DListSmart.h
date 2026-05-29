#ifndef CP_DLIST_SMART_H
#define CP_DLIST_SMART_H

#include <iostream>
#include <memory>
using namespace std;

template<typename T>
class CP_DListSmart
{
private:
    struct Node
    {
        T m_data;
        weak_ptr<Node> m_prev;    
        shared_ptr<Node> m_next;  
        Node(const T& data) : m_data(data), m_next(nullptr) {}
        ~Node() {}
    };

    shared_ptr<Node> m_head;
    weak_ptr<Node> m_tail;         
    int m_size;

public:
    CP_DListSmart() : m_head(nullptr), m_size(0) {}
    ~CP_DListSmart()
    {
        mb_clear();
    }

    CP_DListSmart(const CP_DListSmart& other) : m_head(nullptr), m_size(0)
    {
        shared_ptr<Node> cur = other.m_head;
        while (cur)
        {
            mb_pushBack(cur->m_data);
            cur = cur->m_next;
        }
    }

    CP_DListSmart& operator=(const CP_DListSmart& other)
    {
        if (this != &other)
        {
            mb_clear();
            shared_ptr<Node> cur = other.m_head;
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
        shared_ptr<Node> node = make_shared<Node>(data);
        if (!m_head)
        {
            m_head = node;
            m_tail = node;
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
        shared_ptr<Node> node = make_shared<Node>(data);
        shared_ptr<Node> tail = m_tail.lock();
        if (!tail)
        {
            m_head = node;
            m_tail = node;
        }
        else
        {
            node->m_prev = tail;
            tail->m_next = node;
            m_tail = node;
        }
        m_size++;
    }

    bool mb_popFront()
    {
        if (!m_head) return false;
        if (m_head->m_next)
        {
            m_head = m_head->m_next;
            m_head->m_prev.reset();
        }
        else
        {
            m_head.reset();
            m_tail.reset();
        }
        m_size--;
        return true;
    }

    bool mb_popBack()
    {
        shared_ptr<Node> tail = m_tail.lock();
        if (!tail) return false;
        shared_ptr<Node> prev = tail->m_prev.lock();
        if (prev)
        {
            prev->m_next.reset();
            m_tail = prev;
        }
        else
        {
            m_head.reset();
            m_tail.reset();
        }
        m_size--;
        return true;
    }

    void mb_clear()
    {
        
        while (m_head)
        {
            shared_ptr<Node> next = m_head->m_next;
            m_head->m_next.reset();
            m_head = next;
        }
        m_tail.reset();
        m_size = 0;
    }

    int mb_size() const { return m_size; }
    bool mb_empty() const { return m_size == 0; }
    T mb_front() const { return m_head->m_data; }
    T mb_back() const { return m_tail.lock()->m_data; }

    void mb_show() const
    {
        cout << "[";
        shared_ptr<Node> cur = m_head;
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
        shared_ptr<Node> cur = m_tail.lock();
        while (cur)
        {
            cout << cur->m_data;
            shared_ptr<Node> prev = cur->m_prev.lock();
            if (prev) cout << " <-> ";
            cur = prev;
        }
        cout << "]" << endl;
    }
};

#endif
