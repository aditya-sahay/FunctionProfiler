# =====================================
# Compiler Settings
# =====================================

CXX = g++
CC = gcc

CXXFLAGS = -std=c++11 \
           -Iast \
           -Isymboltable \
           -Iinstrumentor \
           -Ireport \
           -Iprofiler
CFLAGS = -std=c11

# =====================================
# Generated Files
# =====================================

LEX_SRC = lexer.l
YACC_SRC = parser.y

LEX_OUT = lex.yy.c
YACC_OUT = parser.tab.c
YACC_HDR = parser.tab.h

# =====================================
# Source Files
# =====================================

CPP_SOURCES = \
    ast/ast.cpp \
    symboltable/symboltable.cpp \
    instrumentor/instrumentor.cpp \
    report/report.cpp

C_SOURCES = \
    profiler/profiler.c

# =====================================
# Object Files
# =====================================

CPP_OBJECTS = $(CPP_SOURCES:.cpp=.o)
C_OBJECTS = $(C_SOURCES:.c=.o)

# =====================================
# Executable
# =====================================

TARGET = profiler_compiler

# =====================================
# Default Target
# =====================================

all: $(TARGET)

# =====================================
# Build Parser
# =====================================

$(YACC_OUT) $(YACC_HDR): parser.y
	bison -d parser.y

# =====================================
# Build Lexer
# =====================================

$(LEX_OUT): lexer.l $(YACC_HDR)
	flex lexer.l

# =====================================
# Compile C++
# =====================================

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =====================================
# Compile C
# =====================================

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# =====================================
# Link Everything
# =====================================

$(TARGET): $(YACC_OUT) $(LEX_OUT) $(CPP_OBJECTS) $(C_OBJECTS)
	$(CXX) $(CXXFLAGS) \
		$(YACC_OUT) \
		$(LEX_OUT) \
		$(CPP_OBJECTS) \
		$(C_OBJECTS) \
		-o $(TARGET)

# =====================================
# Clean
# =====================================

clean:
	rm -f \
		$(TARGET) \
		$(LEX_OUT) \
		$(YACC_OUT) \
		$(YACC_HDR) \
		*.o

# =====================================
# Rebuild
# =====================================

rebuild: clean all