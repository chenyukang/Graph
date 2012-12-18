#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;


#define WIDTH (sizeof(int)*8)
#define SIZE(n)  ( ((n)/(WIDTH)) + ((((n)%(WIDTH))) ? 1 : 0 ))

class Array{
public:
    Array() :num(0), vec_size(0), vec(0) { }
    Array(int num) :num(num) {
        vec_size = SIZE(num);
        vec = (int*)malloc(sizeof(int) * vec_size);
        memset(vec, 0, sizeof(int)*vec_size);
    }

    ~Array() {
        free(vec);
    }
    int getNum() const  { return num; }
    int getSize() const { return vec_size; }
    int setNum(int n) {
        int prev_sz = vec_size;
        num = n;
        vec_size = SIZE(n);
        int* new_vec = (int*)malloc(sizeof(int) * vec_size);
        memset(new_vec, 0, sizeof(int)*vec_size);
        for(int i=0; i<prev_sz; ++i) {
            new_vec[i] = vec[i];
        }
        free(vec);
        vec = new_vec;
    }

    int set(int idx) {
        assert(idx < num);
        int i = idx / WIDTH;
        vec[i] |= (1 << (idx%WIDTH));
    }

    int clr(int idx) {
        assert(idx < num);
        int i = idx / WIDTH;
        vec[i] &= ( ~ ( 1 << (idx % WIDTH)));
    }

    int test(int idx) {
        assert(idx < num);
        return ( vec[idx/WIDTH] & ( 1 << (idx % WIDTH)));
    }

    const int& getElem(int index) const {
        assert(index < vec_size);
        return vec[index];
    }
    
    void addSon(const Array& son)  {
        for(int i=0; i<vec_size; i++) {
            vec[i] |= son.getElem(i);
        }
    }

    void addFather(int father) {
        assert(father < num);
        set(father);
    }

    vector<int> getNonZeroBits() const {
        vector<int> res;
        return res;
    }
    
private:
    int* vec;
    int  num;
    int  vec_size;
};

#endif
