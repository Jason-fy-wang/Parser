FLEX:=flex
YACC:=bison
CC:=gcc
LD:=-lfl

TARGET:=calc

.PHONY: all clean

all: ${TARGET}

${TARGET}: calc.y calc.fl
	${YACC} -d -v $<
	${FLEX} calc.fl
	${CC} ${LD} -o ${TARGET} calc.tab.c lex.yy.c


clean:
	rm -rf calc.tab.*  calc  lex.yy.c calc.output




