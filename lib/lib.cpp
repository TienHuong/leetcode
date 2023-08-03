//
// Created by Nguyen Tien Huong on 03/08/2023.
//
#include <iostream>
#include <vector>

template <typename T> void printVector(std::vector<T> &v) {
    for(auto& i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

template <typename T> void printMatrix(std::vector<std::vector<T>> &m) {
    for(auto& r: m) {
        for(auto& v: r) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}