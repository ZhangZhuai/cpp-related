#ifndef __RINGBUFFER_HPP__
#define __RINGBUFFER_HPP__
#include <memory>
#include <mutex>
#include <optional>
#include <iostream>

template <typename T>
class Ring_buffer
{
public:
    explicit Ring_buffer(size_t capacity) : m_buff(std::unique_ptr<T[]>(new T[capacity])),
                                            m_capacity(capacity) {}

    void enqueue(T item)
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        m_buff[m_tail] = item;
        if (m_full)
        {
            m_head = (m_head + 1) % m_capacity;
        }

        m_tail = (m_tail + 1) % m_capacity;
        m_full = (m_head == m_tail);
    }

    std::optional<T> dequeue()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (empty())
        {
            return std::nullopt;
        }

        auto val = m_buff[m_head];
        m_full = false;
        m_head = (m_head + 1) % m_capacity;
        return val;
    }

    void reset()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_head = m_tail;
        m_full = false;
    }

    bool empty() const { return !m_full && (m_head == m_tail); }

    bool full() const { return m_full; }

    size_t getCapacity() const { return m_capacity; }

    size_t getSize() const
    {
        size_t cur_size = m_capacity;

        if (!m_full)
        {
            if (m_head <= m_tail)
                cur_size = m_tail - m_head;
            else
                cur_size += m_tail - m_head;
        }
        return cur_size;
    }

private:
    std::mutex m_mutex;
    std::unique_ptr<T[]> m_buff;
    size_t m_head = 0;
    size_t m_tail = 0;
    size_t m_capacity;
    bool m_full = false;
};

#endif