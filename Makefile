# CC = gcc: Defines the C compiler to be used (GNU C Compiler).
# CFLAGS = -Wall -g: Defines compiler flags. -Wall enables all warnings, and -g includes debugging information.
# TARGET = myprogram: Defines the name of the executable file.
# SOURCES = main.c: Lists the source files for your program.
# all: $(TARGET): The default target.
# $(TARGET): $(SOURCES): This rule specifies how to build the $(TARGET) executable. It depends on $(SOURCES).
# $(CC) $(CFLAGS) $(SOURCES) -o $(TARGET): This is the command to compile the C source files into an executable. Crucially, this line must start with a tab character, not spaces.
# run: $(TARGET): This target allows you to run the compiled program. It depends on $(TARGET) to ensure the program is built before running.
# ./$(TARGET): The command to execute the compiled program.
# clean:: This target allows you to remove the compiled executable.
# rm -f $(TARGET): The command to delete the executable file.


CC = gcc
CFLAGS = -Wall -g
TARGET = myprogram
SOURCES = main.c


all:


run:


clean: