FLEX:=flex
YACC:=bison
CC:=gcc
LD:=-lfl -lm

TARGET:=calc
OBJS = calc.tab.o lex.yy.o functions.o

.PHONY: all clean

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} ${OBJS} -o ${TARGET} ${LD}

calc.tab.c: calc.y
	${YACC} -d -v $<

lex.yy.c: calc.fl
	${FLEX} $<

%.o: %.c
	gcc -c $< -o $@


clean:
	rm -rf calc.tab.*  calc  lex.yy.c calc.output *.o




