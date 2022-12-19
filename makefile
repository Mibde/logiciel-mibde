CXX = g++
EXEC = prog
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXEC)

%.o : %.cpp
	$(CXX) -o $@ -c $< `wx-config --cxxflags --libs`

$(EXEC) : $(OBJ)
	$(CXX) -o $@ $^ `wx-config --cxxflags --libs`
