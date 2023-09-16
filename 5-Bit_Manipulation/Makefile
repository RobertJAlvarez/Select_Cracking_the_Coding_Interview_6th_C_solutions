CC = cc

CFLAGS = -O3 -g3 -Wall -Wextra -Werror=format-security -Werror=implicit-function-declaration \
         -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings

all: flip_bit_to_win

%.o: %.c
	${CC} $(CFLAGS) -c -o $@ $<

flip_bit_to_win: flip_bit_to_win.o
	${CC} -o $@ $^
	./flip_bit_to_win

clean:
	rm -f *.o flip_bit_to_win

