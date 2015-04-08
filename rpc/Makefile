BIN = server client
GEN = date_clnt.c date_svc.c date_xdr.c date.h
RPCGEN = rpcgen

CFLAGS = -Wall -O -DRPC_SVC_FG #-g
#LDLIBS =
#LDFLAGS =

all: $(BIN)

client: date_client.o date_clnt.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)
server: date_server.o date_svc.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

date_client.o: date.h
date_server.o: date.h

$(GEN): date.x
	$(RPCGEN) -C $^
clean:
	$(RM) *.o $(BIN) $(GEN)