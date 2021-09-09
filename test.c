#include "test.h"

struct TestFunction test_array[MAX_TEST_COUNT] = {};
size_t current_test_count = 0;

int assert_equals_int(const int32_t expected, const int32_t actual,
                      const char *filename, int line) {
  if (expected == actual)
    return 1;

  fprintf(stdout, "ERROR (%s@%d): %d != %d\n", filename, line,
          expected, actual);

  return 0;
}

int assert_equals_unsigned_int(const uint32_t expected, const uint32_t actual,
                               const char *filename, int line) {
  if (expected == actual)
    return 1;

  fprintf(stdout, "ERROR (%s@%d): %u != %u\n", filename, line, expected,
          actual);

  return 0;
}

int assert_equals_str(const char *expected, const char *actual,
                      const char *filename, int line) {
  if (expected == actual)
    return 1;

  if (expected == NULL || actual == NULL) {
    fprintf(stdout, "ERROR (%s@%d): One string was empty!\n", filename, line);
    return 0;
  }

  if (strcmp(expected, actual) == 0)
    return 1;

  fprintf(stdout, "ERROR (%s@%d): \"%s\" != \"%s\"\n", filename, line, expected,
          actual);

  return 0;
}

int assert_equals_mem(const void *expected, const void *actual, size_t len,
                      const char *filename, int line) {
  if (expected == actual)
    return 1;

  if (expected == NULL || actual == NULL) {
    fprintf(stdout, "ERROR (%s@%d): One string was empty!\n", filename, line);
    return 0;
  }

  if (memcmp(expected, actual, len) == 0)
    return 1;

  fprintf(stdout, "ERROR (%s@%d): The memory content is not equal!\n", filename,
          line);

  return 0;
}

int assert_equals_file(const char *expected_path, const char *actual_path,
                       size_t max_size, const char *filename, int line) {
  if (expected_path == actual_path)
    return 1;

  if (expected_path == NULL || actual_path == NULL) {
    fprintf(stdout, "ERROR (%s@%d): One path is empty!\n", filename, line);
    return 0;
  }

  char *buffer_expected = (char *)malloc(sizeof(char) * max_size);
  if (buffer_expected == NULL) {
    fprintf(stderr,
            "FATAL ERROR (%s@%d): Couldn't allocate enough memory! Please "
            "rerun the tests with more memory!\n",
            filename, line);
    return 0;
  }

  char *buffer_actual = (char *)malloc(sizeof(char) * max_size);
  if (buffer_actual == NULL) {
    fprintf(stderr,
            "FATAL ERROR (%s@%d): Couldn't allocate enough memory! Please "
            "rerun the tests with more memory!\n",
            filename, line);
    free(buffer_expected);
    return 0;
  }

  FILE *f_expected = fopen(expected_path, "r");
  if (f_expected == NULL) {
    fprintf(stderr, "FATAL ERROR (%s@%d): Couldn't open file '%s'!\n", filename,
            line, expected_path);
    free(buffer_expected);
    free(buffer_actual);
    return 0;
  }

  FILE *f_actual = fopen(actual_path, "r");
  if (f_actual == NULL) {
    fprintf(stderr, "FATAL ERROR (%s@%d): Couldn't open file '%s'!\n", filename,
            line, actual_path);
    free(buffer_expected);
    free(buffer_actual);
    fclose(f_expected);
    return 0;
  }

  size_t size_expected =
      fread(buffer_expected, sizeof(char), max_size, f_expected);
  size_t size_actual = fread(buffer_actual, sizeof(char), max_size, f_actual);

  if (size_expected != size_actual) {
    fprintf(stdout, "ERROR (%s@%d): '%s' != '%s'\n", filename, line,
            expected_path, actual_path);
    free(buffer_expected);
    free(buffer_actual);
    fclose(f_expected);
    fclose(f_actual);
    return 0;
  }

  if (memcmp(buffer_expected, buffer_actual, size_expected) == 0) {
    free(buffer_expected);
    free(buffer_actual);
    fclose(f_expected);
    fclose(f_actual);
    return 1;
  }

  fprintf(stdout, "ERROR (%s@%d): '%s' != '%s'\n", filename, line,
          expected_path, actual_path);
  free(buffer_expected);
  free(buffer_actual);
  fclose(f_expected);
  fclose(f_actual);
  return 0;
}

int assert_equals_file_mem(const char *expected_path, const void *actual,
                           size_t len, const char *filename, int line) {
  if (expected_path == NULL || actual == NULL) {
    fprintf(stdout, "ERROR (%s@%d): One path is empty!\n", filename, line);
    return 0;
  }

  char *buffer_expected = (char *)malloc(sizeof(char) * len);
  if (buffer_expected == NULL) {
    fprintf(stderr,
            "FATAL ERROR (%s@%d): Couldn't allocate enough memory! Please "
            "rerun the tests with more memory!\n",
            filename, line);
    return 0;
  }

  char *buffer_actual = (char *)malloc(sizeof(char) * len);
  if (buffer_actual == NULL) {
    fprintf(stderr,
            "FATAL ERROR (%s@%d): Couldn't allocate enough memory! Please "
            "rerun the tests with more memory!\n",
            filename, line);
    free(buffer_expected);
    return 0;
  }

  FILE *f_expected = fopen(expected_path, "r");
  if (f_expected == NULL) {
    fprintf(stderr, "FATAL ERROR (%s@%d): Couldn't open file '%s'!\n", filename,
            line, expected_path);
    free(buffer_expected);
    free(buffer_actual);
    return 0;
  }

  size_t size_expected = fread(buffer_expected, sizeof(char), len, f_expected);
  size_t size_actual = len;

  if (size_expected != size_actual) {
    fprintf(stdout,
            "ERROR (%s@%d): File size doesn't match memory region size!\n",
            filename, line);
    free(buffer_expected);
    free(buffer_actual);
    fclose(f_expected);
    return 0;
  }

  if (memcmp(buffer_expected, actual, size_expected) == 0) {
    free(buffer_expected);
    free(buffer_actual);
    fclose(f_expected);
    return 1;
  }

  fprintf(stdout, "ERROR (%s@%d): File content doesn't match memory content!\n",
          filename, line);
  free(buffer_expected);
  free(buffer_actual);
  fclose(f_expected);
  return 0;
}

void register_test(int (*test)(), const char *name) {
    if(current_test_count >= MAX_TEST_COUNT) {
        fprintf(stderr, "FATAL ERROR: Maximum number of tests reached! Consider increasing the MAX_TEST_COUNT variable. \n");
        return;
    }

    struct TestFunction t = {test, name};
    test_array[current_test_count++] = t;
}

int main(int argc, const char* argv[]) {
    (void)argc;
    (void)argv;

    unsigned int passed = 0;

    /* execute all tests */
    for(unsigned int i = 0; i < current_test_count; ++i) {
        fprintf(stdout, "Executing %s\n", test_array[i].name);
        if(test_array[i].test())
            ++passed;
    }

    fprintf(stdout, "Total: %lu\tPassed: %d\tFailed: %lu\n", current_test_count, passed, current_test_count - passed);

    return 0;
}
