CC=g++

PROJROOT    = .

CFLAGS=-Wall

HACKERRANK_SRCS = $(wildcard *.cpp)
HACKERRANK_TARGETS = $(shell echo *.cpp)
HACKERRANK_TARGETS := $(foreach n,$(HACKERRANK_SRCS),$(n).o)

all: $(HACKERRANK_TARGETS)

$(HACKERRANK_TARGETS): $(HACKERRANK_SRCS)
    @echo "building exec with shared lib"
    $(CC) -o $@ $(HACKERRANK_SRCS) $(CFLAGS)

.PHONY : clean
clean: 
    @rm -rf $(HACKERRANK_TARGETS)