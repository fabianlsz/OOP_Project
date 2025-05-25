//
// Created by ion on 5/25/25.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <vector>

template<typename T>
class Repository {
private:
    std::vector<T> data;

public:
    const std::vector<T> &getData() const {
        return data;
    }

    void add(const T &value) {
        data.push_back(value);
    }
};

#endif //REPOSITORY_H
