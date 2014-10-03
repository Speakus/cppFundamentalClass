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

static void test_compilation_fails(void) {
    Primitive<int> tmp1 = 1;
    assert(1 == tmp1);
    Primitive<int, 1> tmp2 = 2;
    assert(2 == tmp2);
#if 0 // uncomment it for test compilation fails
    int i = tmp1 + tmp2;
    assert(3 == i);
#endif
}

#include <stdio.h> // for printf()

int main(void) {
    test_Primitive();
    test_compilation_fails();
    printf("test passed\n");
    return 0;
}
