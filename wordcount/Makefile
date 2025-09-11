.PHONY: all clean

CC := flex
LD := -lfl

SRC := lex.yy.c
TARGET := bin/wordcount

# $@ target 
# $< first prerequisite
# $^ all prerequisites (duplicate removed)
# $? prerequisites newer than target
all: $(TARGET)

# .PHONY:  mark non-file targets
# @ hide command echo
# - ignore errors

$(TARGET): count.fl
	mkdir -p $(dir $@)
	$(CC) $<
	gcc $(LD) -o $@ lex.yy.c


clean:
	rm -rf bin lex.yy.c wordcount



