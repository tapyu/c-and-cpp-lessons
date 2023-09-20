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
# The -g option in GCC is used to include debugging information in the generated executable. When you compile your code with -g, it adds debugging symbols to the binary, which can be extremely helpful for debugging and analyzing your program when it encounters issues or crashes.
# The -Wall and -Wextra options in GCC are used to enable a variety of warning messages during compilation. They are part of a set of compiler warning options that can help you catch potential issues and improve the quality of your code.
CFLAGS=-Wall -Wextra -g
# related to generating dependency files (.d files) in GCC, which are useful for managing dependencies between source files in a project, especially in the context of Makefiles. It mean, don't just build the program, but also generate the depencies in a way that `make` will understand.
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

all: $(foreach BIN,$(BINARIES),$(BINDIR)/$(BIN))

# geom
$(BINDIR)/$(filter-out tip,$(BINARIES)): $(filter-out %tip.o,$(OBJECTS))
	$(CC) -o $@ $^ -lm

# tip
$(BINDIR)/$(filter-out geom,$(BINARIES)): $(filter-out %geom.o,$(OBJECTS))
	$(CC) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o tip geom