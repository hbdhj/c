CC=gcc
AR=ar

PROJROOT    =..
SRC_DIR     = $(PROJROOT)/src
LIB_DIR     = $(PROJROOT)/lib/
INC_DIR     = $(PROJROOT)/inc
DERIVED     = $(LIB_DIR)/DERIVED/

INCS        = $(INC_DIR)/hello.h

CFLAGS=-fPIC -I$(INC_DIR)

LIB_OBJS = $(addprefix $(DERIVED), hello.o )
LIB_SRCS = $(addprefix $(LIB_DIR), hello.c )

libhello.a = $(LIB_DIR)/DERIVED/libhello.a

libhello.so = $(LIB_DIR)/DERIVED/libhello.so

all: $(libhello.so) $(libhello.a)

$(libhello.a): $(LIB_OBJS) $(DERIVED)
	@echo "building static library"
	@$(AR) cqs $(libhello.a) $(LIB_OBJS)

$(libhello.so): $(LIB_SRCS) $(DERIVED)
	@echo "building shared library"
	@$(CC) -shared -o $(libhello.so) $(LIB_SRCS) $(CFLAGS)

$(LIB_OBJS): $(LIB_SRCS) $(INCS) $(DERIVED)
	@echo "building objects"
	@$(CC) -c -o $@ $< $(CFLAGS)

$(DERIVED):
	@mkdir $(DERIVED)

.PHONY : clean
clean: 
	@rm -rf $(DERIVED)