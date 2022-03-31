#include "unity.h"
#include "dbFunctions.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

char *loc = "./test/test.dat";

void test_add_contact(void) {
    FILE* file = fopen(loc, "wb+");  
    entryFormat new_entry = {256000, 8318331989, 30000, 2021, "Animesh"};
    TEST_ASSERT_EQUAL(1, append(file, new_entry));
    fclose(file);
}

void test_delete_contact(void) {
    FILE* file = fopen(loc, "wb+"); 
    entryFormat new_entry = {256000, 8318331989, 30000, 2021, "Animesh"};
    TEST_ASSERT_EQUAL(1, append(file, new_entry));
    fclose(file);
    file = fopen(loc, "rb+");
    TEST_ASSERT_EQUAL(1, delete(file, new_entry.id));
    fclose(file);
    remove("temp.dat");
}

void test_modify_contact(void) {
    FILE* file = fopen(loc, "wb+"); 
    entryFormat new_entry1 = {256000, 8318331989, 30000, 2021, "Animesh"};
    entryFormat new_entry2 = {256001, 8318331988, 30001, 2021, "Ankur"};
    TEST_ASSERT_EQUAL(1, append(file, new_entry1));
    fclose(file);
    file = fopen(loc, "rb+");
    // TEST_ASSERT_EQUAL(1, modify(file, new_entry1.id));
    TEST_ASSERT_EQUAL(1, delete(file, new_entry1.id));
    fclose(file);
    file = NULL;
    remove("temp.dat");
}
void test_search_contact(void) {
    FILE* file = fopen(loc, "wb+"); 
    entryFormat new_entry = {256000, 8318331989, 30000, 2021, "Animesh"};
    TEST_ASSERT_EQUAL(1, append(file, new_entry));
    fclose(file);
    file = fopen(loc, "rb");
    TEST_ASSERT_EQUAL(1, search(file, new_entry.id));
    fclose(file);
    file = fopen(loc, "rb+");
    TEST_ASSERT_EQUAL(1, delete(file, new_entry.id));
    fclose(file);
}
void test_display_contact(void) 
{ 
    FILE* file;
    file = fopen(loc, "rb");
    TEST_ASSERT_EQUAL(1, displayAll(file));
    fclose(file);
}

int main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_add_contact);
  RUN_TEST(test_delete_contact);
  RUN_TEST(test_modify_contact);
  RUN_TEST(test_search_contact);
  RUN_TEST(test_display_contact);

  /* Close the Unity Test Framework */
  return UNITY_END();
}