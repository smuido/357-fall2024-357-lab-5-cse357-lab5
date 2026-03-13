#include "checkit.h"
#include "task1.h"
#include "task1.c"

void test1() {
   char input[] = "Hello THERE";
   char result[15];
   char *expected = "hello there";

   str_lower(input, result);

   checkit_string(result, expected);
}

void test2() {
   char input[] = "Hello THERE";
   char result[20];
   char *expected = "hello there";

   str_lower(input, result);

   checkit_string(result, expected);
}

void test3() {
   char input[] = "CS357 LAB";
   char result[20];
   char *expected = "cs357 lab";

   str_lower(input, result);

   checkit_string(result, expected);
}

void test4() {
   char input[] = "GOODBYE WORLD";
   char *expected = "goodbye world";

   str_lower_mutate(input);

   checkit_string(input, expected);
}

void test5() {
   char input[] = "MiXeD CaSe123";
   char *expected = "mixed case123";

   str_lower_mutate(input);

   checkit_string(input, expected);
}

int main(void) {
   test1();
   test2();
   test3();
   test4();
   test5();
   return 0;
}