#include "test.h"

TEST(example_pass) {
    PASS();
}

TEST(example_fail) {
    FAIL();
}

TEST(example_assert) {
    ASSERT_EQUALS_INT(1, 1);
    ASSERT_EQUALS_INT(1, 2);
    PASS();
}

