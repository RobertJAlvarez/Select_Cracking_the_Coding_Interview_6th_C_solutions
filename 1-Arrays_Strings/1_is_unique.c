#include <stdio.h>
#include <stdlib.h>

/* Return 1 if all the values in s are unique, 0 otherwise.
 * Time complexity: O(n), Space complexity: O(1)
 */
int is_unique(const char *s)
{
  int32_t checker[] = {0,0,0,0,0,0,0,0};
  int i, val;

  for (const char *c = s; *c; ++c) {
    i = *c/32;
    val = *c - 32*i;
    if ((checker[i] & (1 << val)) > 0) return 0;
    checker[i] |= (1 << val);
  }

  return 1;
}

int main(void)
{
  const char *strings[] = {"asdfghjkl", "abcdd"};

  for (const char **str = strings; *str; ++str) {
    printf("\"%s\" ", *str);
    if (is_unique(*str) == 0) printf("DOES NOT ");
    printf("contains unique characters.\n");
  }

  return 0;
}

