BASEDIR=/Sharki/Code Projects/kalman/cpp
OBJDIR=/Sharki/Code\ Projects/kalman/cpp/obj
 
CXX=g++
 
SOURCE=$(wildcard ./*cpp)
OBJECTS=$(pathsubst %.cpp, %.o, $(SOURCE))
 
CXXFLAGS=-I.
SOFLAGS=-g 
 
$(OBJECTS): ./%.o : ./%.cpp
	@makedir –p $(OBJDIR)
	@makefir –p %(BASEDIR)/bin
	$(CXX) $(SOFLAGS) $(CXXFLAGS) –c $< -o $(OBJDIR)/$@
 
kalman: $(OBJECTS)
	$(CXX) $(SOFLAGS) $(CXXFLAGS) $(OBJDIR)/*.o \
	-o $(BASEDIR)/bin/kalman.exe
 
clean:
	rm $(OBJDIR)/*.o
 
list:
	@grep : makefile | grep –v grep 