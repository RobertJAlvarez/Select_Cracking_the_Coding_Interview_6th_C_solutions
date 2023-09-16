#include <stdio.h>
#include <stdlib.h>

/* Use a 32 bit variable where the first 'z' - 'a' bits are
 * set to 1 if the character at that possible had been seen
 * an odd number of times or to 0 for even.
 *
 * Time complexity: O(n), Space complexity: O(1)
 */
int permutation_is_palindrome(const char *s)
{
  int32_t letters = 0;
  uint32_t val;
  size_t n_odds = 0;

  for (const char *c = s; *c; ++c) {
    // Set val and letters base on c: lower, upper or other.
    val = 31;
    if ( ('a' <= *c) && (*c <= 'z') ) {
      val = *c - 'a';
    } else if ( ('A' <= *c) && (*c <= 'Z') ) {
      val = *c - 'A';
    } else {
      continue;
    }

    if ((letters & (1 << val)) == 0) {
      ++n_odds;
      letters |= (1 << val);
    } else {
      --n_odds;
      letters &= ~(1 << val);
    }
  }

  return n_odds <= ((size_t) 1);
}

int main(void)
{
  const char *strings[] = {"Tact Coa", "Abdo dB"};

  for (const char **str = strings; *str; ++str) {
    if (permutation_is_palindrome(*str) == 0) {
      printf("NO ");
    } else {
      printf("A ");
    }
    printf("permutation of \"%s\" ", *str);
    printf("is a palindrome.\n");
  }

  return 0;
}

