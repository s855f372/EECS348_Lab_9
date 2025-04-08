matrix.exe: main.cpp matrix.hpp
	g++ -Wall -Wextra main.cpp matrix.hpp -o matrix.exe

clean:
	rm -f matrix.exe

run:
	./matrix.exe