CXX = g++
EXEC = prog
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXEC)

%.o : %.cpp
	$(CXX) -o $@ -c $< -lpq -lpqxx `wx-config --cxxflags --libs`

$(EXEC) : $(OBJ)
	$(CXX) -o $@ $^ -lpq -lpqxx `wx-config --cxxflags --libs`

clean :
	rm -rf *.o

mrproper : clean
	rm -rf $(EXEC)
