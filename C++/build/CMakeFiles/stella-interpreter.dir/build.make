# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build

# Include any dependencies generated for this target.
include CMakeFiles/stella-interpreter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stella-interpreter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stella-interpreter.dir/flags.make

CMakeFiles/stella-interpreter.dir/Stella/Absyn.C.o: CMakeFiles/stella-interpreter.dir/flags.make
CMakeFiles/stella-interpreter.dir/Stella/Absyn.C.o: ../Stella/Absyn.C
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stella-interpreter.dir/Stella/Absyn.C.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stella-interpreter.dir/Stella/Absyn.C.o -c /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Absyn.C

CMakeFiles/stella-interpreter.dir/Stella/Absyn.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stella-interpreter.dir/Stella/Absyn.C.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Absyn.C > CMakeFiles/stella-interpreter.dir/Stella/Absyn.C.i

CMakeFiles/stella-interpreter.dir/Stella/Absyn.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stella-interpreter.dir/Stella/Absyn.C.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Absyn.C -o CMakeFiles/stella-interpreter.dir/Stella/Absyn.C.s

CMakeFiles/stella-interpreter.dir/Stella/Parser.C.o: CMakeFiles/stella-interpreter.dir/flags.make
CMakeFiles/stella-interpreter.dir/Stella/Parser.C.o: ../Stella/Parser.C
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/stella-interpreter.dir/Stella/Parser.C.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stella-interpreter.dir/Stella/Parser.C.o -c /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Parser.C

CMakeFiles/stella-interpreter.dir/Stella/Parser.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stella-interpreter.dir/Stella/Parser.C.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Parser.C > CMakeFiles/stella-interpreter.dir/Stella/Parser.C.i

CMakeFiles/stella-interpreter.dir/Stella/Parser.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stella-interpreter.dir/Stella/Parser.C.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Parser.C -o CMakeFiles/stella-interpreter.dir/Stella/Parser.C.s

CMakeFiles/stella-interpreter.dir/Stella/Printer.C.o: CMakeFiles/stella-interpreter.dir/flags.make
CMakeFiles/stella-interpreter.dir/Stella/Printer.C.o: ../Stella/Printer.C
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/stella-interpreter.dir/Stella/Printer.C.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stella-interpreter.dir/Stella/Printer.C.o -c /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Printer.C

CMakeFiles/stella-interpreter.dir/Stella/Printer.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stella-interpreter.dir/Stella/Printer.C.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Printer.C > CMakeFiles/stella-interpreter.dir/Stella/Printer.C.i

CMakeFiles/stella-interpreter.dir/Stella/Printer.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stella-interpreter.dir/Stella/Printer.C.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Printer.C -o CMakeFiles/stella-interpreter.dir/Stella/Printer.C.s

CMakeFiles/stella-interpreter.dir/Stella/Buffer.C.o: CMakeFiles/stella-interpreter.dir/flags.make
CMakeFiles/stella-interpreter.dir/Stella/Buffer.C.o: ../Stella/Buffer.C
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/stella-interpreter.dir/Stella/Buffer.C.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stella-interpreter.dir/Stella/Buffer.C.o -c /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Buffer.C

CMakeFiles/stella-interpreter.dir/Stella/Buffer.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stella-interpreter.dir/Stella/Buffer.C.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Buffer.C > CMakeFiles/stella-interpreter.dir/Stella/Buffer.C.i

CMakeFiles/stella-interpreter.dir/Stella/Buffer.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stella-interpreter.dir/Stella/Buffer.C.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Buffer.C -o CMakeFiles/stella-interpreter.dir/Stella/Buffer.C.s

CMakeFiles/stella-interpreter.dir/Stella/Lexer.C.o: CMakeFiles/stella-interpreter.dir/flags.make
CMakeFiles/stella-interpreter.dir/Stella/Lexer.C.o: ../Stella/Lexer.C
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/stella-interpreter.dir/Stella/Lexer.C.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stella-interpreter.dir/Stella/Lexer.C.o -c /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Lexer.C

CMakeFiles/stella-interpreter.dir/Stella/Lexer.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stella-interpreter.dir/Stella/Lexer.C.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Lexer.C > CMakeFiles/stella-interpreter.dir/Stella/Lexer.C.i

CMakeFiles/stella-interpreter.dir/Stella/Lexer.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stella-interpreter.dir/Stella/Lexer.C.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Stella/Lexer.C -o CMakeFiles/stella-interpreter.dir/Stella/Lexer.C.s

CMakeFiles/stella-interpreter.dir/StoredType.cpp.o: CMakeFiles/stella-interpreter.dir/flags.make
CMakeFiles/stella-interpreter.dir/StoredType.cpp.o: ../StoredType.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/stella-interpreter.dir/StoredType.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stella-interpreter.dir/StoredType.cpp.o -c /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/StoredType.cpp

CMakeFiles/stella-interpreter.dir/StoredType.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stella-interpreter.dir/StoredType.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/StoredType.cpp > CMakeFiles/stella-interpreter.dir/StoredType.cpp.i

CMakeFiles/stella-interpreter.dir/StoredType.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stella-interpreter.dir/StoredType.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/StoredType.cpp -o CMakeFiles/stella-interpreter.dir/StoredType.cpp.s

CMakeFiles/stella-interpreter.dir/MyVisitor.cpp.o: CMakeFiles/stella-interpreter.dir/flags.make
CMakeFiles/stella-interpreter.dir/MyVisitor.cpp.o: ../MyVisitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/stella-interpreter.dir/MyVisitor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stella-interpreter.dir/MyVisitor.cpp.o -c /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/MyVisitor.cpp

CMakeFiles/stella-interpreter.dir/MyVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stella-interpreter.dir/MyVisitor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/MyVisitor.cpp > CMakeFiles/stella-interpreter.dir/MyVisitor.cpp.i

CMakeFiles/stella-interpreter.dir/MyVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stella-interpreter.dir/MyVisitor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/MyVisitor.cpp -o CMakeFiles/stella-interpreter.dir/MyVisitor.cpp.s

CMakeFiles/stella-interpreter.dir/Interpret.cpp.o: CMakeFiles/stella-interpreter.dir/flags.make
CMakeFiles/stella-interpreter.dir/Interpret.cpp.o: ../Interpret.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/stella-interpreter.dir/Interpret.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stella-interpreter.dir/Interpret.cpp.o -c /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Interpret.cpp

CMakeFiles/stella-interpreter.dir/Interpret.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stella-interpreter.dir/Interpret.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Interpret.cpp > CMakeFiles/stella-interpreter.dir/Interpret.cpp.i

CMakeFiles/stella-interpreter.dir/Interpret.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stella-interpreter.dir/Interpret.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Interpret.cpp -o CMakeFiles/stella-interpreter.dir/Interpret.cpp.s

CMakeFiles/stella-interpreter.dir/Eval.cpp.o: CMakeFiles/stella-interpreter.dir/flags.make
CMakeFiles/stella-interpreter.dir/Eval.cpp.o: ../Eval.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/stella-interpreter.dir/Eval.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stella-interpreter.dir/Eval.cpp.o -c /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Eval.cpp

CMakeFiles/stella-interpreter.dir/Eval.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stella-interpreter.dir/Eval.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Eval.cpp > CMakeFiles/stella-interpreter.dir/Eval.cpp.i

CMakeFiles/stella-interpreter.dir/Eval.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stella-interpreter.dir/Eval.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/Eval.cpp -o CMakeFiles/stella-interpreter.dir/Eval.cpp.s

CMakeFiles/stella-interpreter.dir/TypeCheck.cpp.o: CMakeFiles/stella-interpreter.dir/flags.make
CMakeFiles/stella-interpreter.dir/TypeCheck.cpp.o: ../TypeCheck.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/stella-interpreter.dir/TypeCheck.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stella-interpreter.dir/TypeCheck.cpp.o -c /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/TypeCheck.cpp

CMakeFiles/stella-interpreter.dir/TypeCheck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stella-interpreter.dir/TypeCheck.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/TypeCheck.cpp > CMakeFiles/stella-interpreter.dir/TypeCheck.cpp.i

CMakeFiles/stella-interpreter.dir/TypeCheck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stella-interpreter.dir/TypeCheck.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/TypeCheck.cpp -o CMakeFiles/stella-interpreter.dir/TypeCheck.cpp.s

# Object files for target stella-interpreter
stella__interpreter_OBJECTS = \
"CMakeFiles/stella-interpreter.dir/Stella/Absyn.C.o" \
"CMakeFiles/stella-interpreter.dir/Stella/Parser.C.o" \
"CMakeFiles/stella-interpreter.dir/Stella/Printer.C.o" \
"CMakeFiles/stella-interpreter.dir/Stella/Buffer.C.o" \
"CMakeFiles/stella-interpreter.dir/Stella/Lexer.C.o" \
"CMakeFiles/stella-interpreter.dir/StoredType.cpp.o" \
"CMakeFiles/stella-interpreter.dir/MyVisitor.cpp.o" \
"CMakeFiles/stella-interpreter.dir/Interpret.cpp.o" \
"CMakeFiles/stella-interpreter.dir/Eval.cpp.o" \
"CMakeFiles/stella-interpreter.dir/TypeCheck.cpp.o"

# External object files for target stella-interpreter
stella__interpreter_EXTERNAL_OBJECTS =

stella-interpreter: CMakeFiles/stella-interpreter.dir/Stella/Absyn.C.o
stella-interpreter: CMakeFiles/stella-interpreter.dir/Stella/Parser.C.o
stella-interpreter: CMakeFiles/stella-interpreter.dir/Stella/Printer.C.o
stella-interpreter: CMakeFiles/stella-interpreter.dir/Stella/Buffer.C.o
stella-interpreter: CMakeFiles/stella-interpreter.dir/Stella/Lexer.C.o
stella-interpreter: CMakeFiles/stella-interpreter.dir/StoredType.cpp.o
stella-interpreter: CMakeFiles/stella-interpreter.dir/MyVisitor.cpp.o
stella-interpreter: CMakeFiles/stella-interpreter.dir/Interpret.cpp.o
stella-interpreter: CMakeFiles/stella-interpreter.dir/Eval.cpp.o
stella-interpreter: CMakeFiles/stella-interpreter.dir/TypeCheck.cpp.o
stella-interpreter: CMakeFiles/stella-interpreter.dir/build.make
stella-interpreter: CMakeFiles/stella-interpreter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable stella-interpreter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stella-interpreter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stella-interpreter.dir/build: stella-interpreter

.PHONY : CMakeFiles/stella-interpreter.dir/build

CMakeFiles/stella-interpreter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stella-interpreter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stella-interpreter.dir/clean

CMakeFiles/stella-interpreter.dir/depend:
	cd /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++ /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++ /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build /home/justsomedude/Documents/GitHub/week-2-typechecker-for-stella-with-simple-extensions-JustSomeDude2001/C++/build/CMakeFiles/stella-interpreter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stella-interpreter.dir/depend

