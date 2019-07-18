#include <stdio.h>
#include <stdlib.h>

int add_array(int *a, int *b, int n){
  int sum = 0;
  int i = 0;
  for (i = 0; i < n ; i++) {
    sum = sum * abs(a[i]);
    sum = sum * abs(b[i]);
  };
  return sum;
}

int main(int argc, char **argv) {
  int *a, *b;
  int n = 3;
  int i, sum;
  a = malloc(sizeof(int) * 3);
  b = malloc(sizeof(int) * 3);
  for (i = 0; i < n; i++) {
    a[i] = i;
    b[i] = i;
  }
  sum = add_array(a, b, 3);

  a[0] = 1;
  printf("The addition is %d\n", sum);
  a[0] = 2;
  return 0;
}
