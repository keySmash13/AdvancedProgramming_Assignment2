compiler = g++
flags = -Wall -std=c++17
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)

dynamicarray.o : dynamicarray.cc dynamicarray.h
	$(compile) $<

project2sampletests : project2sampletests.cc dynamicarray.o
	$(link) $^
	./a.out

clean :
	rm *.o a.out
