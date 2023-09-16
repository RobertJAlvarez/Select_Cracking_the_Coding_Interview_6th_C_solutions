#include <stdio.h>  //printf()
#include <stdlib.h> //malloc() free()
#include <string.h> //strlen()

/* Time Complexity: O(n), Space Complexity: O(n) */
char *str_comp(const char *s)
{
  char *new_s;
  char last_c = *s;
  size_t n_c = 0;
  size_t i = 0;

  if (!s) return NULL;

  new_s = (char *) malloc((2*strlen(s)+1)*sizeof(char));
  if (new_s == NULL) return NULL;

  for (const char *c = s; *c; ++c) {
    if (*c != last_c) { // New character found
      // Append character with count to new_s
      new_s[i++] = last_c;
      new_s[i++] = '0' + n_c;
      // Update variables
      last_c = *c;
      n_c = 1;
    } else { ++n_c; }
  }

  // Append last character and count
  new_s[i++] = last_c;
  new_s[i++] = '0' + n_c;
  new_s[i] = '\0';

  return new_s;
}

int main(void)
{
  const char *str[] = { "aabcccccaaa", ""};
  char *new_str;

  printf("-- Start testing --\n");

  for (const char **s = str; *s; ++s) {
    printf("    str = %s\n", *s);
    new_str = str_comp(*s);
    printf("new_str = %s\n", new_str);
    free(new_str);
  }

  printf("-- End testing --\n");

  return 0;
}

