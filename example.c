#include "test.h"

TEST(example_pass) {
    PASS();
}

TEST(example_fail) {
    FAIL();
}

TEST(example_assert) {
    ASSERT_EQUALS_UNSIGNED_INT(1, 1);
    ASSERT_EQUALS_INT(1, 2);
    PASS();
}

TEST(example_str) {
    const char* str1 = "This is a string";
    const char* str2 = "This is a string";
    ASSERT_EQUALS_STR(str1, str2);
    PASS();
}

TEST(example_str2) {
    const char* str1 = "This is a string";
    const char* str2 = "This is another string";
    ASSERT_EQUALS_STR(str1, str2);
    PASS();
}

TEST(example_mem) {
    int i1[5] = {1, 2, 3, 4, 5};
    const int i2[5] = {1, 2, 3, 4, 5};
    const int i3[5] = {1, 2, 3, 4, 6};
    ASSERT_EQUALS_MEM(i1, i2, 5 * sizeof (int));
    ASSERT_EQUALS_MEM(i1, i3, 5 * sizeof (int));
    PASS();
}

TEST(example_file) {
    ASSERT_EQUALS_FILE("file1.txt", "file2.txt", 100);
    ASSERT_EQUALS_FILE("file1.txt", "file3.txt", 100);
    PASS();
}

TEST(example_file2) {
    ASSERT_EQUALS_FILE("file1.txt", "file4.txt", 100);
    PASS();
}

TEST(example_file_mem) {
    ASSERT_EQUALS_FILE_MEM("file1.txt", "file1", 100);
    ASSERT_EQUALS_FILE_MEM("file1.txt", "file3.txt", 100);
    PASS();
}

TEST(example_file_mem2) {
    ASSERT_EQUALS_FILE_MEM("file1.txt", "file4", 100);
    PASS();
}
