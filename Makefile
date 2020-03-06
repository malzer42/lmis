# ----------------------------------------------------------------
# Makefile : for TD1 Cpp-src
#
# The CURSES variable defines the BSD curses library is being used.
# The LIBS variable defines the C libraries to link with.
# The SRC variable defines the CPP sources files.
# The OBJ variable defines the object files.
#
# The C sources are compiled with flags as described by CFLAGS.
# ----------------------------------------------------------------

LIBS = -lstdc++ # OS/2

WITH_CURSES = no

ifeq ($(WITH_CURSES),yes)
  LIBS = -lstdc++ -lcurses -ltermcap -lpthread -lgtest -lgtest_main
else
  LIBS = -lstdc++ -lpthread -lgtest -lgtest_main
endif

EXEC = lmis
BIN = bin

# ------- Source Files are Listed Here ---------------------------

SRC = $(notdir $(wildcard *.cpp))

# ------- Header Files are Listed Here ---------------------------

#INCLUDES = $(notdir $(wildcard $(INC)/*.h))

# ------- Object Files are the same as Sources -------------------

OBJ = $(notdir $(SRC:.cpp=.o))

# ------- Compiler flags and things ------------------------------

FLAGS = 2>>err
DEBUG =    -ggdb3
WARNINGS = -Wall
         # -W -Wcast-qual -Wcast-align \
         # -Wmissing-prototypes \
         # -Wmissing-declarations \
         # -Wnested-externs \
         # -Wstrict-prototypes
         # -Wconversion \
         # -Wredundant-decls
OPTIMIZE = -O0
PROFILE  = -pg
BOUNDS   = -fbounds-check
FLOAT0   = -ffloat-store
           # Do not store floating point variables in registers, and
           # inhibit other options that might change whether a floating
           # point value is taken from a register or memory.
FLOAT1   = -mieee-fp
           # Control whether or not the compiler uses IEEE floating
           # point comparisons.  These handle correctly the case where
           # the result of a comparison is unordered.
FLOAT2   = # -mwide-multiply
           # Control whether GNU CC uses the @code{mul} and @code{imul}
           # that produce 64 bit results in @code{eax:edx} from 32 bit
           # operands to do @code{long long} multiplies and 32-bit
           # division by constants.
FAST     = -ffast-math
           # This option allows GCC to violate some ANSI or IEEE rules
           # and/or specifications in the interest of optimizing code
           # for speed.  For example, it allows the compiler to assume
           # arguments to the @code{sqrt} function are non-negative
           # numbers and that no floating-point values are NaNs.
CODE0    = -mtune=pentium
CODE1    = -march=pentium
CFLAGS =  ${OPTIMIZE} ${DEBUG}  ${WARNINGS} ${BOUNDS} ${PROFILE} \
          ${FLOAT0}   ${FLOAT1} ${FLOAT2}   ${CODE0}  ${CODE1} ${FAST} 

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
NC = \033[1;0m

CC = g++-9 -std=c++17 -Wno-deprecated -pedantic # -fguiding-decls

all: $(BIN)/$(EXEC)
	@echo "$(RED)Done!$(NC)"
	@echo "Congratulation the program $(GREEN)$(EXEC)$(NC) has been created successfully.$(NC)"
	@echo "To compile: type $(GREEN)make all$(NC) in the terminal/command prompt.$(NC)"
	@echo "To run: type $(GREEN)make run$(NC) or $(GREEN)./$(EXEC)$(NC) in the terminal/command prompt.$(NC)"
	@echo "To clean: type $(GREEN)make clean$(NC) in the terminal/command prompt.$(NC)"
	@echo "To archive: type $(GREEN)make zip$(NC) in the terminal/command prompt.$(NC)"
	@echo "To debug: type $(GREEN)make debug$(NC) in the terminal/command prompt.$(NC)"
	@echo "To profile: type $(GREEN)make profile$(NC) in the terminal/command prompt.$(NC)" 
	@echo "For help: type $(GREEN)make help$(NC) in the terminal/command prompt.$(NC)"
	@echo "$(GREEN)Weldone!$(NC)"


$%.o: %.cpp
	@echo "$(RED)Compiling...$(NC)"
	$(CC) -o $@ -c $(FLAGS) $(CFLAGS) $<
	@echo "$(RED)Compiling...$(NC)"

$(BIN)/$(EXEC): $(OBJ)
	@echo "$(RED)Linking...$(NC)"
	${CC} -o $@ $^  $(FLAGS) $(CFLAGS)


# ------- The real makecoy ---------------------------------------
.PHONY: all clean help run zip

clean:
	@echo "$(RED)Cleaning...$(NC)"
	rm -f err $(BIN)/$(EXEC) *~ *.o *.tgz

help:
	@echo "Source files: $(RED)$(SRC)$(NC)"
	@echo "Objet files : $(YELLOW)$(OBJ)$(NC)"
	@echo "Binary file : $(GREEN)$(EXEC)$(NC)"
	@echo "The CURSES variable defines the $(GREEN)BSD$(NC) curses library is being used.$(NC)"
	@echo "The LIBS variable defines the $(GREEN)C$(NC) libraries to link with.$(NC)"
	@echo "The C sources are compiled with $(GREEN)flags$(NC) as described by $(GREEN) CFLAGS.$(NC)"
	@echo "To compile: type $(GREEN)make all$(NC) in the terminal/command prompt.$(NC)"
	@echo "To run: type $(GREEN)make run$(NC) or $(GREEN)./$(EXEC)$(NC) in the terminal/command prompt.$(NC)"
	@echo "To clean: type $(GREEN)make clean$(NC) in the terminal/command prompt.$(NC)"
	@echo "To archive: type $(GREEN)make zip$(NC) in the terminal/command prompt.$(NC)"
	@echo "To debug: type $(GREEN)make debug$(NC) in the terminal/command prompt.$(NC)"
	@echo "To profile: type $(GREEN)make profile$(NC) in the terminal/command prompt.$(NC)" 
	@echo "For help: type $(GREEN)make help$(NC) in the terminal/command prompt.$(NC)"

run:
	@echo "$(GREEN)Running...$(NC)"
	./$(BIN)/$(EXEC)

zip:
	@echo "$(RED)Archiving...$(NC)"
	tar cvzf $(EXEC).tgz $(SRC) *.h Makefile

profile:
	@echo "$(GREEN)Profiling...$(NC)"
	valgrind ./$(BIN)/$(EXEC)

debug:
	@echo "$(RED)Debugging...$(NC)"
	gdb ./$(BIN)/$(EXEC)













