compiler = g++
flags = -std=c++17 -Wall
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)

myset.o : myset.cc myset.h setinterface.h
	$(compile) $<

initialtest.o : initialtest.cc myset.h setinterface.h
	$(compile) $<

initialtest : test.o myset.o
	$(link) $^
	./a.out

tests.o: tests.cc myset.h setinterface.h
	$(compile) $<

tests : tests.o myset.o
	$(link) $^
	./a.out


clean :
	rm *.o a.out
