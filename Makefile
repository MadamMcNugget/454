#! /usr/bin/make

# Source file
SOURCE= scrap.cpp 

# The compiler we are using 
CC= g++

# The flags that will be used to compile the object file.
# If you want to debug your program,
# you can add '-g' on the following line
CFLAGS= -O3 -g -Wall -pedantic -DGL_GLEXT_PROTOTYPES

# The name of the final executable 
EXECUTABLE= tree

# Don't touch 
OBJECT= $(SOURCE:.cpp=.o)

all: $(OBJECT) depend
	$(CC) $(CFLAGS) $(INCLUDEFLAG) $(LIBFLAG) $(OBJECT) -o $(EXECUTABLE) $(LDFLAGS)

depend:
	$(CC) -M $(SOURCE) > depend

$(OBJECT):
	$(CC) $(CFLAGS) $(INCLUDEFLAG) -c -o $@ $(@:.o=.cpp)

clean_object:
	rm -f $(OBJECT)

clean:
	rm -f $(OBJECT) depend $(EXECUTABLE)

run: all
	rm -f $(OBJECT)
	./demo

include depend
