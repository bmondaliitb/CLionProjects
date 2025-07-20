#pragma once
#include <memory>

template<typename T>
class Transform {
public:
    virtual T operator()(T value) const = 0;
    virtual std::unique_ptr<Transform<T>> clone() const = 0;
    virtual ~Transform() = default;
};

