#include "my_functions.h"

#define ASSERT_EQ(x, y) { if (x != y) { std::cout << "[-] " <<  __FUNCTION__ << " failed on line " << __LINE__ << std::endl;}}
#define RUN_TEST(s, x) { std::cout << "[*] Running test: " << s << std::endl; x(); std::cout << "[+] Test " << s << " passed." <<std::endl;}

void test_my_to_string()
{
  std::string str;
  str = my_to_string(1337);
  ASSERT_EQ(str, "1337");
  str = my_to_string(-1337);
  ASSERT_EQ(str, "-1337");
  str = my_to_string(INT_MAX);
  ASSERT_EQ(str, "2147483647");
  str = my_to_string(INT_MIN);
  ASSERT_EQ(str, "-2147483647");

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
}

int main(void)
{
  RUN_TEST("test_my_to_string", test_my_to_string);
  RUN_TEST("test_my_stoi", test_my_stoi);
  return 0;
}
