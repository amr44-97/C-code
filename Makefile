CC =cc

ECFLAGS = -Wall -Wextra -Werror -pedantic -ggdb

CFLAGS = -Wall -O2

SRC  = parse.c
EXEC = executable

executable: parse.c 
	${CC} ${CFLAGS} -o ${EXEC} ${SRC}
