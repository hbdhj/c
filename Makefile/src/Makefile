CC=gcc
AR=ar

PROJROOT    =..
SRC_DIR     = $(PROJROOT)/src
LIB_DIR     = $(PROJROOT)/lib
INC_DIR     = $(PROJROOT)/inc
DERIVED     = $(SRC_DIR)/DERIVED/
LIB_PATH    = $(LIB_DIR)/DERIVED/
LIB         = hello
INCS        = $(INC_DIR)/hello.h

CFLAGS=-fPIC -I$(INC_DIR)

MAIN_OBJS = $(addprefix $(DERIVED), main.o )
MAIN_SRCS = $(addprefix $(SRC_DIR)/, main.c )

hello-s = $(DERIVED)/hello-s

hello-d = $(DERIVED)/hello-d

all: $(hello-s) $(hello-d)

$(hello-d): $(MAIN_SRCS) $(DERIVED)
	@echo "building exec with shared lib"
	$(CC) -o $@ $(MAIN_SRCS) $(CFLAGS) -L$(LIB_PATH) -l$(LIB)

$(hello-s): $(MAIN_SRCS) $(DERIVED)
	@echo "building exec with static lib"
	$(CC) -o $@ $(MAIN_SRCS) $(CFLAGS) -static -L$(LIB_PATH) -l$(LIB)

$(DERIVED):
	@mkdir $(DERIVED)

.PHONY : clean
clean: 
	@rm -rf $(DERIVED)