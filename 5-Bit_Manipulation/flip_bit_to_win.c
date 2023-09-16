#include <stdio.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

/* Given a triple ordered as {1s, 0s, 1s},
 * find max sequence that can be formed.
 */
static int get_max_seq(const int seqs[3])
{
  // A single 0 -> merge sequences
  if (seqs[1] == 1) return seqs[0] + seqs[2] + 1;
  // No 0s -> take one side
  else if (seqs[1] == 0) return MAX(seqs[0], seqs[2]);
  // Many 0s -> take size, add 1 (flip a bit)
  else return MAX(seqs[0], seqs[2]) + 1;
}

/* "pop" the oldest sequence and set new one to zero */
static void shift(int sequences[3])
{
  sequences[2] = sequences[1];
  sequences[1] = sequences[0];
  sequences[0] = 0;
}

int longest_sequence(int n)
{
  int searching_for = 0;        // Either a 0 or 1
  int sequences[3] = {0, 0, 0}; // Count of last 3 sequences
  int max_sequence = 1;

  while (n > 0) {
    if ((n & 1) != searching_for) {
      if (searching_for == 1)
        max_sequence = MAX(max_sequence, get_max_seq(sequences));

      searching_for = n & 1;
      shift(sequences);
    }
    ++sequences[0];
    n >>= 1;
  }

  // Check final set of sequences
  if (searching_for == 0) shift(sequences);

  return MAX(max_sequence, get_max_seq(sequences));
}

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

int main(void)
{
  int arr_nums[] = {1775, 0}; // {0b11011101111, 0}
  size_t size = sizeof(arr_nums)/sizeof(arr_nums[0]);
  int ans;

  printf("-- Start testing --\n");

  for (size_t i = ((size_t) 0); i < size; ++i) {
    printf("Input: ");
    print_binary(((unsigned int) arr_nums[i]));
    printf("\n");

    ans = longest_sequence(arr_nums[i]);

    printf("Output: %d\n", ans);
  }

  printf("-- End testing --\n");

  return 0;
}

