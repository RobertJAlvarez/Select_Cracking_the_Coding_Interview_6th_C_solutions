CC = cc

CFLAGS = -O3 -g3 -Wall -Wextra -Werror=format-security -Werror=implicit-function-declaration \
         -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings

all: str_comp

%.o: %.c
	${CC} $(CFLAGS) -c -o $@ $<

str_comp: str_compression.o
	${CC} -o $@ $^
	./str_comp

clean:
	rm -f *.o str_comp

