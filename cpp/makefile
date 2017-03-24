BASEDIR="E:\Sharki\Code Projects\kalman\cpp"
OBJDIR="E:\Sharki\Code Projects\kalman\cpp\obj\"
 
CXX=g++
 
SOURCE=$(wildcard ./*cpp)
OBJECTS=$(pathsubst %.cpp, %.o, $(SOURCE))
 
CXXFLAGS=-I.
SOFLAGS=-g –lthread –lnsl –lsocket
 
$(OBJECTS): ./%.o : ./%.cpp
                @makedir –p $(OBJDIR)
                @makefir –p %(BASEDIR)/bin
                $(CXX) $(SOFLAGS) $(CXXFLAGS) –c $< -o $(OBJDIR)/$@
 
Kalman : $(OBJECTS)
                $(CXX) $(SOFLAGS) $(CXXFLAGS) $(OBJDIR)/*.o \
                -o $(BASEDIR)/bin/kalman.exe
 
Clean :
                Rm $(OBJDIR)/*.o
 
List :
                @grep : makefile | grep –v grep | grep –v “OBJECTS):”