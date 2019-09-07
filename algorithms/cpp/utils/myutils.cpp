//
// Created by tianm on 2019-09-07.
//

#include <iostream>
#include <vector>
#include "myutils.h"
#include <string>

using namespace std;


void print(bool v) {
    cout << v << endl;
}

void print(char v) {
    cout << v << endl;
}

void print(int v) {
    cout << v << endl;
}

void print(string &v) {
    cout << v << endl;
}

void print(char v[]) {
    while (*v != '\0') {
        cout << *v << endl;
        v++;
    }
}

void print_1d_vector(vector<int> &vect) {
    for (int &x:vect)
        cout << x << " ";
    cout << endl;
}

void print_2d_vector(vector<vector<int>> &vect) {
    for (auto &level:vect) {
        for (int &ele:level)
            cout << ele << " ";
        cout << endl;
    }
}