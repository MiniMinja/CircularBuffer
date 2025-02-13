libring.so: ring.o
	echo "Producing the .so file"
	echo "If you want to test the main, call 'make testring'"
	g++ -shared -o libring.so ring.o

ring.o: ring.hpp ring.cpp
	g++ -c -fPIC ring.cpp

testring: compiletest runtest clean 

compiletest: libring.so main.cpp 
	g++ main.cpp -L. -lring -o test

runtest:
	LD_LIBRARY_PATH=. ./test

clean: 
	rm *.o
	rm test
