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
void defaultDeleter(T* p) noexcept {
    delete p;
}

template<typename T, typename... Args>
SharedPtr<T> makeShared(Args&&... args) {
    return SharedPtr<T>(new T(std::forward<Args>(args)...));
}

// Simplified version of std::shared_ptr.
template<typename T>
class SharedPtr {
    friend void swap<T>(SharedPtr<T>& lhs, SharedPtr<T>& rhs);

public:
    // Default ctor
    SharedPtr() noexcept : ptr(nullptr), refCnt(nullptr), deleter(defaultDeleter<T>) {}

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
    ~SharedPtr() noexcept {
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
    explicit operator bool() const noexcept {
        return ptr != nullptr;
    }

    // Dereference operator
    T& operator*() const noexcept {
        return *ptr;
    }

    // Member access operator
    T* operator->() const noexcept {
        return ptr;
    }

    // Return underlying pointer
    T* get() const noexcept {
        return ptr;
    }

    // Whether reference count is one
    bool unique() const noexcept {
        return 1 == useCount();
    }

    // Return reference count
    std::size_t useCount() const noexcept {
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
    void decreaseAndDestory() noexcept {
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
    std::function<void(T*) noexcept> deleter;
};

TASTYLIB_NS_END

#endif
