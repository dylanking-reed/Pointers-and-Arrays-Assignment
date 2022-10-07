FLAGS= -Wall -Wextra -Werror -pedantic -g
OBJS=binary-tree.o
BINS=tests

tests: tests.c  $(OBJS)
	cc -Wall -Wextra -pedantic -g -o tests tests.c $(OBJS)

binary-tree.o:
	cc $(FLAGS) -c binary-tree.c

clean:
	rm $(OBJS) $(BINS)
