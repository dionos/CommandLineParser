#Makefile

NAME = cmparser

CC = g++
LD = ld
AR = ar
RM = rm

CPPFLAGS = -Wall -fPIC
LDFLAGS = 
ARFLAGS = rcs

BUILDDIR = build
SOURCEDIR = src
HEADERDIR = inc

STATICNAME = $(BUILDDIR)/libcmparser.a
SHAREDNAME = $(BUILDDIR)/libcmparser.so
BINARY = $(BUILDDIR)/$(NAME)


SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

INCLUDE = -I$(HEADERDIR)

all: $(BINARY)



$(BINARY): $(OBJECTS) static shared main
	@echo $(SOURCES)
	@echo $(OBJECTS)

static:
	@echo "Creating Static Lib"
#	AROBJECTS = $(wildcard $(BUILDDIR)/*.o)
	$(AR) $(ARFLAGS) $(STATICNAME) $(OBJECTS)

shared:
	@echo "Creating Shared Lib"
#	SOOBJECTS = $(wildcard $(BUILDDIR)/*.o)
	$(CC) -shared $(OBJECTS) -o $(SHAREDNAME)

main:
	@echo "Building main"
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(INCLUDE) main.cpp -o $(BINARY) -L./$(BUILDDIR) ./build/libcmparser.a

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
#	@echo "Building libs"
#	@echo $< $@
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) -rf $(OBJECTS)
	$(RM) -rf $(STATICNAME)
	$(RM) -rf $(SHAREDNAME)
	$(RM) -rf $(BINARY)

	
