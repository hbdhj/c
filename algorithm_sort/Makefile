CC=g++
AR=ar

SRC_DIR     = .
LIB_DIR     = .
INC_DIR     = .
DERIVED     = $(SRC_DIR)/DERIVED/
LIB_PATH    = DERIVED
LIB         = hello
INCS        = sort.h

CFLAGS=-fPIC -I$(INC_DIR)

MAIN_OBJS = $(addprefix $(DERIVED), main.o )
MAIN_SRCS = $(addprefix $(SRC_DIR)/, main.c )

libbubble.so = $(LIB_PATH)/libbubble.so
libinsert.so = $(LIB_PATH)/libinsert.so
libmerge.so = $(LIB_PATH)/libmerge.so
libquick.so = $(LIB_PATH)/libquick.so
libshell.so = $(LIB_PATH)/libshell.so
libselect.so = $(LIB_PATH)/libselect.so
libheap.so = $(LIB_PATH)/libheap.so

bubble = $(DERIVED)/bubble
insert = $(DERIVED)/insert
merge = $(DERIVED)/merge
quick = $(DERIVED)/quick
shell = $(DERIVED)/shell
select = $(DERIVED)/select
heap = $(DERIVED)/heap

all: $(bubble) $(insert) $(merge) $(quick) $(shell) $(select) $(heap)

$(bubble): $(MAIN_SRCS) $(libbubble.so)
	@echo "building bubble with shared lib"
	$(CC) -o $@ $(MAIN_SRCS) $(CFLAGS) -L$(LIB_PATH) -lbubble

$(libbubble.so): bubble.c $(DERIVED)
	@echo "building bubble shared library"
	$(CC) -shared -o $(libbubble.so) bubble.c $(CFLAGS)
	
$(insert): $(MAIN_SRCS) $(libinsert.so)
	@echo "building insert with shared lib"
	$(CC) -o $@ $(MAIN_SRCS) $(CFLAGS) -L$(LIB_PATH) -linsert

$(libinsert.so): insert.c $(DERIVED)
	@echo "building insert shared library"
	$(CC) -shared -o $(libinsert.so) insert.c $(CFLAGS)
	
$(merge): $(MAIN_SRCS) $(libmerge.so)
	@echo "building merge with shared lib"
	$(CC) -o $@ $(MAIN_SRCS) $(CFLAGS) -L$(LIB_PATH) -lmerge

$(libmerge.so): merge.c $(DERIVED)
	@echo "building merge shared library"
	$(CC) -shared -o $(libmerge.so) merge.c $(CFLAGS)

$(quick): $(MAIN_SRCS) $(libquick.so)
	@echo "building quick with shared lib"
	$(CC) -o $@ $(MAIN_SRCS) $(CFLAGS) -L$(LIB_PATH) -lmerge

$(libquick.so): quick.c $(DERIVED)
	@echo "building quick shared library"
	$(CC) -shared -o $(libquick.so) quick.c $(CFLAGS)

$(shell): $(MAIN_SRCS) $(libshell.so)
	@echo "building shell with shared lib"
	$(CC) -o $@ $(MAIN_SRCS) $(CFLAGS) -L$(LIB_PATH) -lshell

$(libshell.so): shell.c $(DERIVED)
	@echo "building shell shared library"
	$(CC) -shared -o $(libshell.so) shell.c $(CFLAGS)

$(libselect.so): select.c $(DERIVED)
	@echo "building select shared library"
	$(CC) -shared -o $(libselect.so) select.c $(CFLAGS)

$(select): $(MAIN_SRCS) $(libselect.so)
	@echo "building select with shared lib"
	$(CC) -o $@ $(MAIN_SRCS) $(CFLAGS) -L$(LIB_PATH) -lselect

$(libheap.so): heap.c $(DERIVED)
	@echo "building select shared library"
	$(CC) -shared -o $(libheap.so) heap.c $(CFLAGS)

$(heap): $(MAIN_SRCS) $(libheap.so)
	@echo "building heap with shared lib"
	$(CC) -o $@ $(MAIN_SRCS) $(CFLAGS) -L$(LIB_PATH) -lheap

$(DERIVED):
	@mkdir $(DERIVED)

.PHONY : clean
clean: 
	@rm -rf $(DERIVED)