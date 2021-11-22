CXX = g++
CXXFLAGS = -g -w
NAMEGLAGS = -o
SRC = src

make:
	$(CXX) $(CXXFLAGS) ./$(SRC)/*.cc $(NAMEGLAGS) cfg_simulation

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f cfg_simulation *.o
	rm -rf *~ basura b i
