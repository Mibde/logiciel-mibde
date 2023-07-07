CXX = g++
EXEC = prog
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXEC)

%.o : %.cpp
	$(CXX) -o $@ -c $< -lpqxx -lpq -I/usr/include/python3.10 -lpython3.10 `wx-config --cxxflags --libs`

$(EXEC) : $(OBJ)
	$(CXX) -o $@ $^ -lpqxx -lpq -I/usr/include/python3.10 -lpython3.10 `wx-config --cxxflags --libs`

clean :
	rm -rf *.o

mrproper : clean
	rm -rf $(EXEC)
