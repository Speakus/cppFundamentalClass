// New BSD License

#include "Primitive.hpp"
#include <assert.h> // for assert()
#include <string.h> // for memcmp()

static void test_Primitive(void) {
    assert(sizeof(Primitive<int>) == sizeof(int));
    Primitive<unsigned long long> val = 1;
    assert(1U == val);
    val <<= 1;
    assert(2U == val);
    val = val + 2;
    assert(4U == val);
    val = val + 6;
    assert(10U == val);
    val = 1 | val;
    val = val || val;
    assert(1U == val);
    const unsigned long long tmp = val;
    assert(1U == tmp);
    const bool binarySame = (0 == memcmp(&tmp, &val, sizeof(tmp)));
    assert(binarySame);

    Primitive<float> valf = 1.0f;
    assert(1.0f == valf);
}

#include <stdio.h> // for printf()

int main(void) {
    test_Primitive();
    printf("test passed\n");
    return 0;
}
