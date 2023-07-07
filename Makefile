CC = g++
CFLAGS = -w -O2 -std=gnu++11 -std=gnu99 -g3
#CFLAGS = -Wfatal-errors -w -O2 -std=gnu++11 -std=gnu99 -g3
#CXXFLAGS = -Wall -g -std=gnu99 -O2
LDFLAGS = -lprotobuf -lddfyang
#LDFLAGS = -lddfyang -lddymsg -lprotobuf
INCLUDE_DIRS = -I/usr/include/ -I/usr/local/include/
LIB_DIRS = -L/usr/lib64 -L/usr/local/lib/
RPATH_FLAGS = -Wl,-rpath=/usr/lib64 -Wl,-rpath=/usr/local/lib/

all: proto_heap

proto_heap: main.o proto_gnmi.o gNMI.pb.o
	$(CC) $(CFLAGS) $(LIB_DIRS) $(RPATH_FLAGS) -o $@ $^ $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

proto_gnmi.o: proto_gnmi.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

gNMI.pb.o: gNMI.pb.cc
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@


clean:
	rm -f proto_heap *.o

