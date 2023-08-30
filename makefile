CXX = g++
EXEC = prog
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXEC)

%.o : %.cpp
	$(CXX) -o $@ -c $< -lpqxx -lpq `wx-config --cxxflags --libs`

$(EXEC) : $(OBJ)
	$(CXX) -o $@ $^ -lpqxx -lpq `wx-config --cxxflags --libs`

clean :
	rm -rf *.o

mrproper : clean
	rm -rf $(EXEC)
