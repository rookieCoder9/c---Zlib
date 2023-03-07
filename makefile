TARGET=zpipe
CC=g++
DEBUG=-g
OPT=-O2
WARN=-Wall
LZ=-lz
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=g++
OBJS= main.o zpipe.o
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LZ)
	@rm -f *.o

main.o: main.cpp
	$(CC) -c $(CCFLAGS) $(LZ) main.cpp -o main.o
 
zpipe.o: zpipe.cpp
	$(CC) -c $(CCFLAGS) $(LZ) zpipe.cpp -o zpipe.o