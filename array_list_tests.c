#include "checkit.h"
#include "array_list.c"
#include "array_list.h"

void test1() {
   array_list *list = array_list_new();

   int expected = 0;

   checkit_int(list->size, expected);
}

void test2() {
   array_list *list = array_list_new();

   array_list_add_to_end(list, "hello");

   int expected_size = 1;
   char *expected_value = "hello";

   checkit_int(list->size, expected_size);
   checkit_string(list->data[0], expected_value);
}

void test3() {
   array_list *list = array_list_new();

   array_list_add_to_end(list, "one");
   array_list_add_to_end(list, "two");
   array_list_add_to_end(list, "three");

   checkit_int(list->size, 3);
   checkit_string(list->data[0], "one");
   checkit_string(list->data[1], "two");
   checkit_string(list->data[2], "three");
}

void test4() {
   array_list *list = array_list_new();

   array_list_add_to_end(list, "a");
   array_list_add_to_end(list, "b");
   array_list_add_to_end(list, "c");
   array_list_add_to_end(list, "d");
   array_list_add_to_end(list, "e");  // forces resize if capacity was 4

   checkit_int(list->size, 5);
   checkit_string(list->data[4], "e");
}

int main(void) {
   test1();
   test2();
   test3();
   test4();
   return 0;
}