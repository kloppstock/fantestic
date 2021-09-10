#ifndef TEST_H
#define TEST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
 * \brief Returns true if the actual value and the expected integer value match.
 * Returns false otherwise and prints an error string.
 * \param expected The expected value.
 * \param actual The actual value.
 * \param filename The name of the testfile.
 * \param line The line of the assert statement.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
int fantestic_assert_equals_int(const int64_t expected, const int64_t actual,
                                const char *filename, int line);

/*!
 * \brief Returns true if the actual value and the expected unsigned integer
 * value match. Returns false otherwise and prints an error string.
 * \param expected The expected value.
 * \param actual The actual value.
 * \param filename The name of the testfile.
 * \param line The line of the assert statement.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
int fantestic_assert_equals_unsigned_int(const uint64_t expected,
                                         const uint64_t actual,
                                         const char *filename, int line);

/*!
 * \brief Returns true if the actual value and the expected floating point
 * value match. Returns false otherwise and prints an error string.
 * \param expected The expected value.
 * \param actual The actual value.
 * \param filename The name of the testfile.
 * \param line The line of the assert statement.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
int fantestic_assert_equals_float(const long double expected,
                                  const long double actual,
                                  const char *filename, int line);

/*!
 * \brief Returns true if the actual value and the expected strings match.
 * Returns false otherwise and prints an error string.
 * \param expected The expected value.
 * \param actual The actual value.
 * \param filename The name of the testfile.
 * \param line The line of the assert statement.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
int fantestic_assert_equals_str(const char *expected, const char *actual,
                                const char *filename, int line);

/*!
 * \brief Returns true if the actual value and the expected memory regions match
 * in content. Returns false otherwise and prints an error string.
 * \param expected The expected value.
 * \param actual The actual value.
 * \param len The length of the memory region to compare.
 * \param filename The name of the testfile.
 * \param line The line of the assert statement.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
int fantestic_assert_equals_mem(const void *expected, const void *actual,
                                size_t len, const char *filename, int line);

/*!
 * \brief Returns true if the actual value and the expected files match. Returns
 * false otherwise and prints an error string.
 * \param expected The expected value.
 * \param actual The actual value.
 * \param max_size The maximum file size to read.
 * \param filename The name of the testfile.
 * \param line The line of the assert statement.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
int fantestic_assert_equals_file(const char *expected_path,
                                 const char *actual_path, size_t max_size,
                                 const char *filename, int line);

/*!
 * \brief Returns true if the actual memory region and the expected file match
 * in content. Returns false otherwise and prints an error string.
 * \param expected The expected value.
 * \param actual The actual value.
 * \param len The maximum file size to read; also the size of the actual memory
 * region.
 * \param filename The name of the testfile.
 * \param line The line of the assert statement.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
int fantestic_assert_equals_file_mem(const char *expected_path,
                                     const void *actual, size_t max_size,
                                     const char *filename, int line);

/*!
 * \brief Returns true if the actual value and the expected integer value match.
 * Returns false otherwise and prints an error string.
 * \param E The expected value.
 * \param A The actual value.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
#define ASSERT_EQUALS_INT(E, A)                                                \
  {                                                                            \
    if (!fantestic_assert_equals_int(E, A, __FILE__, __LINE__))                \
      return 0;                                                                \
  }

/*!
 * \brief Returns true if the actual value and the expected unsigned integer
 * value match. Returns false otherwise and prints an error string.
 * \param E The expected value.
 * \param A The actual value.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
#define ASSERT_EQUALS_UNSIGNED_INT(E, A)                                       \
  {                                                                            \
    if (!fantestic_assert_equals_unsigned_int(E, A, __FILE__, __LINE__))       \
      return 0;                                                                \
  }

/*!
 * \brief Returns true if the actual value and the expected floating point
 * value match. Returns false otherwise and prints an error string.
 * \param E The expected value.
 * \param A The actual value.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
#define ASSERT_EQUALS_FLOAT(E, A)                                              \
  {                                                                            \
    if (!fantestic_assert_equals_float(E, A, __FILE__, __LINE__))              \
      return 0;                                                                \
  }

/*!
 * \brief Returns true if the actual and the expected string. Returns false
 * otherwise and prints an error string.
 * \param E The expected string.
 * \param A The actual string.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
#define ASSERT_EQUALS_STR(E, A)                                                \
  {                                                                            \
    if (!fantestic_assert_equals_str(E, A, __FILE__, __LINE__))                \
      return 0;                                                                \
  }

/*!
 * \brief Returns true if the actual value and the expected memory regions match
 * in content. Returns false otherwise and prints an error string.
 * \param E The expected value.
 * \param A The actual value.
 * \param L The length of the memory region to compare.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
#define ASSERT_EQUALS_MEM(E, A, L)                                             \
  {                                                                            \
    if (!fantestic_assert_equals_mem(E, A, L, __FILE__, __LINE__))             \
      return 0;                                                                \
  }

/*!
 * \brief Returns true if the actual value and the expected files match. Returns
 * false otherwise and prints an error string.
 * \param E The expected value.
 * \param A The actual value.
 * \param L The maximum file size to read.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
#define ASSERT_EQUALS_FILE(E, A, L)                                            \
  {                                                                            \
    if (!fantestic_assert_equals_file(E, A, L, __FILE__, __LINE__))            \
      return 0;                                                                \
  }

/*!
 * \brief Returns true if the actual memory region and the expected file match
 * in content. Returns false otherwise and prints an error string.
 * \param E The expected value.
 * \param A The actual value.
 * \param L The maximum file size to read; also the size of the actual memory
 * region.
 * \return True (1) if the expected matches the actual, false (0) otherwise.
 */
#define ASSERT_EQUALS_FILE_MEM(E, A, L)                                        \
  {                                                                            \
    if (!fantestic_assert_equals_file_mem(E, A, L, __FILE__, __LINE__))        \
      return 0;                                                                \
  }

/*!
 * \brief Fails the test.
 */
#define FAIL()                                                                 \
  {                                                                            \
    fprintf(stdout, "ERROR (%s@%d): FAIL() called!\n", __FILE__, __LINE__);    \
    return 0;                                                                  \
  }

/*!
 * \brief Passes the test.
 */
#define PASS()                                                                 \
  { return 1; }

/*!
 * \brief The FantesticTestFunction struct.
 */
struct FantesticTestFunction {
  /*!
   * \brief test The pointer to the test function.
   */
  int (*test)(void);

  /*!
   * \brief name The test name.
   */
  const char *name;
};

/*!
 * \brief MAX_TEST_COUNT The maximum number of tests allowed.
 */
#define MAX_TEST_COUNT 65536

/*!
 * \brief test_array Holds all tests.
 */
extern struct FantesticTestFunction fantestic_test_array[MAX_TEST_COUNT];

/*!
 * \brief current_test_count Counts how many tests currently exist.
 */
extern size_t fantestic_current_test_count;

/*!
 * \brief Register a new test.
 * \param test The test function pointer.
 * \param name The name of the test.
 */
void fantestic_register_test(int (*test)(void), const char *name);

/*!
 * \brief Creates the test function and registers it.
 * \param NAME The name if the test function.
 */
#define TEST(NAME)                                                             \
  int NAME();                                                                  \
  __attribute__((constructor)) static void fantestic_register_##NAME() {       \
    fantestic_register_test(NAME, #NAME);                                      \
  }                                                                            \
  int NAME()

#ifdef __cplusplus
}
#endif
#endif /* TEST_H */
