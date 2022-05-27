#pragma once

namespace myptr {

template <class T>
class exclusive_ptr {

    T* mData;

public:

    exclusive_ptr(const exclusive_ptr& ptr) = delete;
    exclusive_ptr& operator=(const exclusive_ptr& ptr) = delete;

    exclusive_ptr() : mData(nullptr) {
    }

    explicit exclusive_ptr(T* data) : mData{data} {
    }

    exclusive_ptr(exclusive_ptr&& ptr) : mData(ptr.mData) {
        ptr.mData = nullptr;
    }

    exclusive_ptr& operator=(exclusive_ptr&& ptr) {
        if(mData == ptr.mData) return ptr;
        mData = ptr.mData;
        ptr.mData = nullptr;
        return *this;
    }

    operator bool() {
        return mData != nullptr;
    }

    T operator*() {
        return *mData;
    }

    void reset() {
        delete mData;
        mData = nullptr;
    }

    ~exclusive_ptr() {
        delete mData;
        mData = nullptr;
    }
};

} // namespace myptr
