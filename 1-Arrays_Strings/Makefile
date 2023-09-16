CC = cc

CFLAGS = -O3 -g3 -Wall -Wextra -Werror=format-security -Werror=implicit-function-declaration \
         -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings

%.o: %.c
	${CC} $(CFLAGS) -c -o $@ $<

is_unique: 1_is_unique.o
	${CC} -o $@ $^
	./is_unique

pal_perm: 4_palindrome_permutation.o
	${CC} -o $@ $^
	./pal_perm

str_comp: 6_str_compression.o
	${CC} -o $@ $^
	./str_comp

clean:
	rm -f *.o str_comp is_unique pal_perm

