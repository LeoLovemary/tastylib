#ifndef TASTYLIB_SHAREDPTR_H_
#define TASTYLIB_SHAREDPTR_H_

#include "tastylib/internal/base.h"
#include <cstddef>
#include <functional>
#include <utility>

TASTYLIB_NS_BEGIN

template<typename>
class SharedPtr;

template<typename T>
void swap(SharedPtr<T>& lhs, SharedPtr<T>& rhs) {
    lhs.swap(rhs);
}

template<typename T>
void defaultDeleter(T* p) {
    delete p;
}

// Simplified version of std::shared_ptr.
template<typename T>
class SharedPtr {
    friend void swap<T>(SharedPtr<T>& lhs, SharedPtr<T>& rhs);

public:
    // Default ctor
    SharedPtr() : ptr(nullptr), refCnt(nullptr), deleter(defaultDeleter<T>) {}

    // Contruct from raw pointer (optional custom deleter)
    explicit SharedPtr(T* p, const std::function<void(T*)>& d = defaultDeleter<T>)
        : ptr(p), refCnt(new std::size_t(1)), deleter(d) {}

    // Copy ctor
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), refCnt(other.refCnt),
                                        deleter(other.deleter) {
        ++*refCnt;
    }

    // Move ctor
    SharedPtr(SharedPtr&& other) : ptr(other.ptr), refCnt(other.refCnt),
                                   deleter(std::move(other.deleter)) {
        other.ptr = nullptr;
        other.refCnt = nullptr;
    }

    // Move- and copy-assignment operator
    SharedPtr& operator=(SharedPtr rhs) {
        swap(rhs);
        return *this;
    }

    // Dtor
    ~SharedPtr() {
        decreaseAndDestory();
    }

    // Swap members with another SharedPtr
    void swap(SharedPtr& rhs) {
        using std::swap;
        swap(ptr, rhs.ptr);
        swap(refCnt, rhs.refCnt);
        swap(deleter, rhs.deleter);
    }

    // Safe bool conversion
    explicit operator bool() const {
        return ptr != nullptr;
    }

    // Dereference operator
    T& operator*() const {
        return *ptr;
    }

    // Member access operator
    T* operator->() const {
        return ptr;
    }

    // Return underlying pointer
    T* get() const {
        return ptr;
    }

    // Whether reference count is one
    bool unique() const {
        return 1 == useCount();
    }

    // Return reference count
    std::size_t useCount() const {
        return refCnt ? *refCnt : 0;
    }

    // Reset pointer
    void reset(T* p = nullptr) {
        decreaseAndDestory();
        if (p) {
            ptr = p;
            refCnt = new std::size_t(1);
        }
    }

    // Reset pointer with custom deleter
    void reset(T* p, const std::function<void(T*)>& d) {
        reset(p);
        deleter = d;
    }

private:
    void decreaseAndDestory() {
        if (refCnt && --*refCnt == 0) {
            delete refCnt;
            deleter(ptr);
        }
        refCnt = nullptr;
        ptr = nullptr;
    }

private:
    T *ptr;
    std::size_t *refCnt;
    std::function<void(T*)> deleter;
};

TASTYLIB_NS_END

#endif
