compiler = g++
flags = -std=c++17 -Wall
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)

myset.o : myset.cc myset.h setinterface.h
	$(compile) $<

test.o : initialtest.cc myset.h setinterface.h
	$(compile) $<

test : test.o myset.o
	$(link) $^
	./a.out

clean :
	rm *.o a.out
