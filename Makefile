CXX := g++
CXXFLAGS := -std=c++23 -Wall -Werror -Wextra -pedantic -O3 -march=native

TARGET := main

SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

format:
	clang-format -style=Microsoft -i src/*.cpp include/*.hpp

clean:
	rm -rf $(TARGET) $(OBJS)