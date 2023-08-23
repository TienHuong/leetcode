//
// Created by Nguyen Tien Huong on 03/08/2023.
//
#include "vector"
#include "iostream"

#ifndef LC_LIB_H
#define LC_LIB_H

template<typename T>
void printVector(std::vector<T> &v);

template<typename T>
void printMatrix(std::vector<std::vector<T>> &m);

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include "lib.cpp"

#endif //LC_LIB_H
