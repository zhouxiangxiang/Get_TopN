CXX = g++
CFLAGS = -std=c++11

main 	: main.cpp
	$(CXX) $(CFLAGS) -o $@ $^

.PHONY	: clean

clean:
	rm -f main
