#include "bit_array.h"
#include "test.h"

int test_bit_array() {
    Array* a = new Array(10);
    assert(a->getSize() == 1);
    a->set(1);
    assert(a->test(1));
    a->clr(1);
    assert(a->test(1) == 0);
    a->setNum(32);
    assert(a->getSize() == 1);
    assert(a->test(1) == 0);
    a->set(1);
    assert(a->test(1));
    a->clr(1);
    for(int k=0; k<32; k++) {
        assert(a->test(k) == 0);
    }
    a->setNum(100);
    a->set(99);
    assert(a->getSize() == 4);
    a->setNum(10000);
    assert(a->getSize() == 313);
    assert(a->test(99));
    delete a;
    printf("Pass \n");
    return 0;
}

