INCLUDE_DIRS="../../catch2"
SRC_FILES:= $(wildcard *.cpp)
CXX=g++
CXXFLAGS=-I$(INCLUDE_DIRS) -std=c++17 -Wall -Werror

test: $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -o test $(SRC_FILES)

.PHONY: debug check clean

debug: $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -g -o test $(SRC_FILES)

check: test
	./test

clean:
	rm -rf test test.dSYM
