CC:=g++

all: main.o Vector.o Trace.o
	$(CC) -o main main.o Vector.o Trace.o
dep: main.cpp src/Vector.cpp src/Trace.cpp
	$(CC) -c -D__TRACE__ -W main.cpp
	$(CC) -c -W src/Vector.cpp
	$(CC) -c -W src/Trace.cpp
clean:
	rm *.o
