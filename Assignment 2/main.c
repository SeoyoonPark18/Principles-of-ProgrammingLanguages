#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tuple {
    char* str;
    int num;
};

int compare_double(const void* a, const void* b) {
    double x = *(double*)a;
    double y = *(double*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int compare_string(const void* a, const void* b) {
    struct tuple* x = (struct tuple*) a;
    struct tuple* y = (struct tuple*) b;
    return strcmp(x->str, y->str);
}

int compare_int_string(const void* a, const void* b) {
    struct tuple* t1 = (struct tuple*) a;
    struct tuple* t2 = (struct tuple*) b;
    int cmp = strcmp(t1->str, t2->str);
    if (t1->num == t2->num) {
        return cmp;
    }
    return t2->num - t1->num;
}

int main(void) {

  //array of doubles
  double numbers[] = {645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25};

  // sorting numbers in ascending order
  int arrsize = sizeof(numbers) / sizeof(double);
  qsort(numbers, arrsize, sizeof(double), compare_double);

  // Display
  printf("Sorted doubles:\n");
  for (int i = 0; i < arrsize; i++){
    printf("%g ", numbers[i]);
  }
  printf("\n");

  //array of people
  struct tuple name[] = {
    {"Hal", 20}, 
    {"Susann", 31}, 
    {"Dwight", 19}, 
    {"Kassandra", 21}, 
    {"Lawrence", 25}, 
    {"Cindy", 22}, 
    {"Cory", 27}, 
    {"Mac", 19}, 
    {"Romana", 27}, 
    {"Doretha", 32}, 
    {"Danna", 20}, 
    {"Zara", 23}, 
    {"Rosalyn", 26}, 
    {"Risa", 24}, 
    {"Benny", 28}, 
    {"Juan", 33}, 
    {"Natalie", 25}
  };

  // sorting people by name ascending
  int n = sizeof(name) / sizeof(name[0]);
  qsort(name, n, sizeof(struct tuple), compare_string);
  printf("Sorted tuples by string:\n");
  for (int i = 0; i < n; i++) {
      printf("(%s, %d) ", name[i].str, name[i].num);
  }
  printf("\n");

  //sorting people by age descending then name ascending
  qsort(name, n, sizeof(struct tuple), compare_int_string);
  printf("Sorted tuples by int descending, then string ascending:\n");
  for (int i = 0; i < n; i++) {
      printf("(%s, %d) ", name[i].str, name[i].num);
  }
  printf("\n");
  
  return 0;
}