//
// Created by tianm on 2019-09-07.
//

#ifndef LEETCODE_ALGORITHMS_MYUTILS_H
#define LEETCODE_ALGORITHMS_MYUTILS_H

#include <iostream>
#include <vector>


using namespace std;

class myutils {

};

void print();

void print(bool v);

void print(char v);

void print(int v);

void print(uint32_t v);

void print(double v);

void print(std::string &v);

void print(char *v);

void print_1d_vector(int v[], int n);

void print_1d_vector(vector<int> &vect);

void print_1d_vector(vector<string> &vect);

void print_2d_vector(vector<vector<int>> &vect);

void print_2d_vector(vector<vector<string>> &vect);

#endif //LEETCODE_ALGORITHMS_MYUTILS_H
