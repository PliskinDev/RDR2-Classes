#pragma once

#include <cstddef>

namespace rage {

template <typename T>
class atArray {
public:
    atArray() : m_size(0), m_data(nullptr) {}

    explicit atArray(std::size_t size) : m_size(size), m_data(new T[size]) {}

    atArray(const atArray& arr) : m_size(arr.m_size), m_data(new T[arr.m_size]) {
        for (std::size_t i = 0; i < m_size; ++i) {
            m_data[i] = arr.m_data[i];
        }
    }

    atArray(atArray&& ) noexcept : m_size(arr.m_size), m_data(arr.m_data) {
        arr.m_size = 0;
        arr.m_data = nullptr;
    }

    atArray& operator=(const atArray& arr) {
        if (this != &arr) {
            delete[] m_data;
            m_size = arr.m_size;
            m_data = new T[m_size];
            for (std::size_t i = 0; i < m_size; ++i) {
                m_data[i] = arr.m_data[i];
            }
        }
        return *this;
    }

    atArray& operator=(atArray&& arr) noexcept {
        if (this != &arr) {
            delete[] m_data;
            m_size = arr.m_size;
            m_data = arr.m_data;
            arr.m_size = 0;
            arr.m_data = nullptr;
        }
        return *this;
    }

    ~atArray() {
        delete[] m_data;
    }

    T& operator[](std::size_t index) {
        return m_data[index];
    }

    const T& operator[](std::size_t index) const {
        return m_data[index];
    }

    std::size_t size() const {
        return m_size;
    }

private:
    std::size_t m_size;
    T* m_data;
};

}