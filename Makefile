# source directories (.c source files)
SRCDIR=./src
# include directories (.h header files)
INCDIR=./include
# build directories (o. object files)
BUILDDIR=./build
# bin directory
BINDIR=./bin
# binaries
BINARIES=geom tip

# C compiler
CC=gcc
# compiler optmization level option
OPT=-O0
# compiler other options
CFLAGS=-Wall -Wextra -g
# related to generating dependency files in GCC, which are useful for managing dependencies between source files in a project, especially in the context of Makefiles. It mean, don't just build the program, but also generate the depencies in a way that `make` will understand.
DEPFLAGS=-MP -MD
# c compiler flags. The foreach function will expand to `-I. -I./include/`
CFLAGS=-Wall -Wextra -g $(foreach DIR,$(INCDIR),-I$(DIR)) $(OPT) $(DEPFLAGS)
# all .c files. The foreach function will expand to `./*.c ./src/*.c`
CFILES=$(foreach DIR,$(SRCDIR),$(wildcard $(DIR)/*.c))
# all .o files. patsubst will expand to the respective C files, but within `build` directory
#         match by it ,replace by it  , from it
OBJECTS=$(patsubst %.c,$(BUILDDIR)/%.o,$(notdir $(CFILES)))
# all .d files
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

all: $(BINARIES)

$(BINARIES): $(OBJECTS)
	echo $^
	$(CC) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o tip geom