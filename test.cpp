#include "my_functions.h"

#define INT_MAX_AS_STR  "2147483647"
#define INT_MIN_AS_STR  "-2147483648"

bool test_verdict;

#define ASSERT_EQ(x, y) { if (x != y) { std::cout << "[-] " <<  __FUNCTION__ << "() on line " << __LINE__ << ": ASSERT_EQ failed(" << x << " == " << y << ")." << std::endl; test_verdict = false;}}
#define RUN_TEST(s, x) { test_verdict = true; std::cout << "[*] Running test: " << s << std::endl; x(); if(test_verdict){std::cout << "[+] Test " << s << " passed." <<std::endl;} else {std::cout << "[-] Test " << s << " failed." <<std::endl;}}

void test_my_to_string()
{
  std::string str;
  str = my_to_string(1337);
  ASSERT_EQ(str, "1337");
  str = my_to_string(-1337);
  ASSERT_EQ(str, "-1337");
  str = my_to_string(INT_MAX);
  ASSERT_EQ(str, INT_MAX_AS_STR);
  str = my_to_string(INT_MIN);
  ASSERT_EQ(str, INT_MIN_AS_STR);
}

void test_my_stoi()
{
  int i;
  i = my_stoi("0");
  ASSERT_EQ(i, 0);
  i = my_stoi("-1337");
  ASSERT_EQ(i, -1337);
  i = my_stoi("1337");
  ASSERT_EQ(i, 1337);
  i = my_stoi(INT_MAX_AS_STR);
  ASSERT_EQ(i, INT_MAX);
  i = my_stoi(INT_MIN_AS_STR);
  ASSERT_EQ(i, INT_MIN);
}

int main(void)
{
  RUN_TEST("test_my_to_string", test_my_to_string);
  RUN_TEST("test_my_stoi", test_my_stoi);
  return 0;
}
