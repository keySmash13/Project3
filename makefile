compiler = g++
flags = -std=c++17 -Wall
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)

drive.o: drive.cc myset.h setinterface.h
	$(compile) $<

drive : drive.o myset.o
	$(link) $^
	./a.out

clean :
	rm *.o a.out
