# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cveeta/CLionProjects/minishell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cveeta/CLionProjects/minishell/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/minishell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minishell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minishell.dir/flags.make

CMakeFiles/minishell.dir/main.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/minishell.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/main.c.o   -c /Users/cveeta/CLionProjects/minishell/main.c

CMakeFiles/minishell.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/main.c > CMakeFiles/minishell.dir/main.c.i

CMakeFiles/minishell.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/main.c -o CMakeFiles/minishell.dir/main.c.s

CMakeFiles/minishell.dir/libft-main/ft_strjoin.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/libft-main/ft_strjoin.c.o: ../libft-main/ft_strjoin.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/minishell.dir/libft-main/ft_strjoin.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/libft-main/ft_strjoin.c.o   -c /Users/cveeta/CLionProjects/minishell/libft-main/ft_strjoin.c

CMakeFiles/minishell.dir/libft-main/ft_strjoin.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/libft-main/ft_strjoin.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/libft-main/ft_strjoin.c > CMakeFiles/minishell.dir/libft-main/ft_strjoin.c.i

CMakeFiles/minishell.dir/libft-main/ft_strjoin.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/libft-main/ft_strjoin.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/libft-main/ft_strjoin.c -o CMakeFiles/minishell.dir/libft-main/ft_strjoin.c.s

CMakeFiles/minishell.dir/libft-main/ft_strlen.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/libft-main/ft_strlen.c.o: ../libft-main/ft_strlen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/minishell.dir/libft-main/ft_strlen.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/libft-main/ft_strlen.c.o   -c /Users/cveeta/CLionProjects/minishell/libft-main/ft_strlen.c

CMakeFiles/minishell.dir/libft-main/ft_strlen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/libft-main/ft_strlen.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/libft-main/ft_strlen.c > CMakeFiles/minishell.dir/libft-main/ft_strlen.c.i

CMakeFiles/minishell.dir/libft-main/ft_strlen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/libft-main/ft_strlen.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/libft-main/ft_strlen.c -o CMakeFiles/minishell.dir/libft-main/ft_strlen.c.s

CMakeFiles/minishell.dir/libft-main/ft_strncmp.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/libft-main/ft_strncmp.c.o: ../libft-main/ft_strncmp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/minishell.dir/libft-main/ft_strncmp.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/libft-main/ft_strncmp.c.o   -c /Users/cveeta/CLionProjects/minishell/libft-main/ft_strncmp.c

CMakeFiles/minishell.dir/libft-main/ft_strncmp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/libft-main/ft_strncmp.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/libft-main/ft_strncmp.c > CMakeFiles/minishell.dir/libft-main/ft_strncmp.c.i

CMakeFiles/minishell.dir/libft-main/ft_strncmp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/libft-main/ft_strncmp.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/libft-main/ft_strncmp.c -o CMakeFiles/minishell.dir/libft-main/ft_strncmp.c.s

CMakeFiles/minishell.dir/libft-main/ft_strdup.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/libft-main/ft_strdup.c.o: ../libft-main/ft_strdup.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/minishell.dir/libft-main/ft_strdup.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/libft-main/ft_strdup.c.o   -c /Users/cveeta/CLionProjects/minishell/libft-main/ft_strdup.c

CMakeFiles/minishell.dir/libft-main/ft_strdup.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/libft-main/ft_strdup.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/libft-main/ft_strdup.c > CMakeFiles/minishell.dir/libft-main/ft_strdup.c.i

CMakeFiles/minishell.dir/libft-main/ft_strdup.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/libft-main/ft_strdup.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/libft-main/ft_strdup.c -o CMakeFiles/minishell.dir/libft-main/ft_strdup.c.s

CMakeFiles/minishell.dir/libft-main/ft_calloc.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/libft-main/ft_calloc.c.o: ../libft-main/ft_calloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/minishell.dir/libft-main/ft_calloc.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/libft-main/ft_calloc.c.o   -c /Users/cveeta/CLionProjects/minishell/libft-main/ft_calloc.c

CMakeFiles/minishell.dir/libft-main/ft_calloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/libft-main/ft_calloc.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/libft-main/ft_calloc.c > CMakeFiles/minishell.dir/libft-main/ft_calloc.c.i

CMakeFiles/minishell.dir/libft-main/ft_calloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/libft-main/ft_calloc.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/libft-main/ft_calloc.c -o CMakeFiles/minishell.dir/libft-main/ft_calloc.c.s

CMakeFiles/minishell.dir/libft-main/ft_bzero.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/libft-main/ft_bzero.c.o: ../libft-main/ft_bzero.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/minishell.dir/libft-main/ft_bzero.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/libft-main/ft_bzero.c.o   -c /Users/cveeta/CLionProjects/minishell/libft-main/ft_bzero.c

CMakeFiles/minishell.dir/libft-main/ft_bzero.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/libft-main/ft_bzero.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/libft-main/ft_bzero.c > CMakeFiles/minishell.dir/libft-main/ft_bzero.c.i

CMakeFiles/minishell.dir/libft-main/ft_bzero.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/libft-main/ft_bzero.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/libft-main/ft_bzero.c -o CMakeFiles/minishell.dir/libft-main/ft_bzero.c.s

CMakeFiles/minishell.dir/libft-main/ft_substr.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/libft-main/ft_substr.c.o: ../libft-main/ft_substr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/minishell.dir/libft-main/ft_substr.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/libft-main/ft_substr.c.o   -c /Users/cveeta/CLionProjects/minishell/libft-main/ft_substr.c

CMakeFiles/minishell.dir/libft-main/ft_substr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/libft-main/ft_substr.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/libft-main/ft_substr.c > CMakeFiles/minishell.dir/libft-main/ft_substr.c.i

CMakeFiles/minishell.dir/libft-main/ft_substr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/libft-main/ft_substr.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/libft-main/ft_substr.c -o CMakeFiles/minishell.dir/libft-main/ft_substr.c.s

CMakeFiles/minishell.dir/libft-main/ft_strchr.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/libft-main/ft_strchr.c.o: ../libft-main/ft_strchr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/minishell.dir/libft-main/ft_strchr.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/libft-main/ft_strchr.c.o   -c /Users/cveeta/CLionProjects/minishell/libft-main/ft_strchr.c

CMakeFiles/minishell.dir/libft-main/ft_strchr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/libft-main/ft_strchr.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/libft-main/ft_strchr.c > CMakeFiles/minishell.dir/libft-main/ft_strchr.c.i

CMakeFiles/minishell.dir/libft-main/ft_strchr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/libft-main/ft_strchr.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/libft-main/ft_strchr.c -o CMakeFiles/minishell.dir/libft-main/ft_strchr.c.s

CMakeFiles/minishell.dir/f.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/f.c.o: ../f.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/minishell.dir/f.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/f.c.o   -c /Users/cveeta/CLionProjects/minishell/f.c

CMakeFiles/minishell.dir/f.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/f.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/f.c > CMakeFiles/minishell.dir/f.c.i

CMakeFiles/minishell.dir/f.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/f.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/f.c -o CMakeFiles/minishell.dir/f.c.s

CMakeFiles/minishell.dir/realized_f.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/realized_f.c.o: ../realized_f.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/minishell.dir/realized_f.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/realized_f.c.o   -c /Users/cveeta/CLionProjects/minishell/realized_f.c

CMakeFiles/minishell.dir/realized_f.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/realized_f.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/realized_f.c > CMakeFiles/minishell.dir/realized_f.c.i

CMakeFiles/minishell.dir/realized_f.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/realized_f.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/realized_f.c -o CMakeFiles/minishell.dir/realized_f.c.s

CMakeFiles/minishell.dir/execve.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/execve.c.o: ../execve.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/minishell.dir/execve.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/execve.c.o   -c /Users/cveeta/CLionProjects/minishell/execve.c

CMakeFiles/minishell.dir/execve.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/execve.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/execve.c > CMakeFiles/minishell.dir/execve.c.i

CMakeFiles/minishell.dir/execve.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/execve.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/execve.c -o CMakeFiles/minishell.dir/execve.c.s

CMakeFiles/minishell.dir/perser.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/perser.c.o: ../perser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/minishell.dir/perser.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/perser.c.o   -c /Users/cveeta/CLionProjects/minishell/perser.c

CMakeFiles/minishell.dir/perser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/perser.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/perser.c > CMakeFiles/minishell.dir/perser.c.i

CMakeFiles/minishell.dir/perser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/perser.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/perser.c -o CMakeFiles/minishell.dir/perser.c.s

CMakeFiles/minishell.dir/pepe.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/pepe.c.o: ../pepe.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/minishell.dir/pepe.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/pepe.c.o   -c /Users/cveeta/CLionProjects/minishell/pepe.c

CMakeFiles/minishell.dir/pepe.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/pepe.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/pepe.c > CMakeFiles/minishell.dir/pepe.c.i

CMakeFiles/minishell.dir/pepe.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/pepe.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/pepe.c -o CMakeFiles/minishell.dir/pepe.c.s

CMakeFiles/minishell.dir/libft-main/ft_free.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/libft-main/ft_free.c.o: ../libft-main/ft_free.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/minishell.dir/libft-main/ft_free.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/libft-main/ft_free.c.o   -c /Users/cveeta/CLionProjects/minishell/libft-main/ft_free.c

CMakeFiles/minishell.dir/libft-main/ft_free.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/libft-main/ft_free.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/libft-main/ft_free.c > CMakeFiles/minishell.dir/libft-main/ft_free.c.i

CMakeFiles/minishell.dir/libft-main/ft_free.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/libft-main/ft_free.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/libft-main/ft_free.c -o CMakeFiles/minishell.dir/libft-main/ft_free.c.s

CMakeFiles/minishell.dir/ft_init.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/ft_init.c.o: ../ft_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/minishell.dir/ft_init.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/ft_init.c.o   -c /Users/cveeta/CLionProjects/minishell/ft_init.c

CMakeFiles/minishell.dir/ft_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/ft_init.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/ft_init.c > CMakeFiles/minishell.dir/ft_init.c.i

CMakeFiles/minishell.dir/ft_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/ft_init.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/ft_init.c -o CMakeFiles/minishell.dir/ft_init.c.s

CMakeFiles/minishell.dir/libft-main/ft_isolating.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/libft-main/ft_isolating.c.o: ../libft-main/ft_isolating.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/minishell.dir/libft-main/ft_isolating.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/libft-main/ft_isolating.c.o   -c /Users/cveeta/CLionProjects/minishell/libft-main/ft_isolating.c

CMakeFiles/minishell.dir/libft-main/ft_isolating.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/libft-main/ft_isolating.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/libft-main/ft_isolating.c > CMakeFiles/minishell.dir/libft-main/ft_isolating.c.i

CMakeFiles/minishell.dir/libft-main/ft_isolating.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/libft-main/ft_isolating.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/libft-main/ft_isolating.c -o CMakeFiles/minishell.dir/libft-main/ft_isolating.c.s

CMakeFiles/minishell.dir/libft-main/ft_lastcoldel.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/libft-main/ft_lastcoldel.c.o: ../libft-main/ft_lastcoldel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/minishell.dir/libft-main/ft_lastcoldel.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/libft-main/ft_lastcoldel.c.o   -c /Users/cveeta/CLionProjects/minishell/libft-main/ft_lastcoldel.c

CMakeFiles/minishell.dir/libft-main/ft_lastcoldel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/libft-main/ft_lastcoldel.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/libft-main/ft_lastcoldel.c > CMakeFiles/minishell.dir/libft-main/ft_lastcoldel.c.i

CMakeFiles/minishell.dir/libft-main/ft_lastcoldel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/libft-main/ft_lastcoldel.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/libft-main/ft_lastcoldel.c -o CMakeFiles/minishell.dir/libft-main/ft_lastcoldel.c.s

CMakeFiles/minishell.dir/utils.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/utils.c.o: ../utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/minishell.dir/utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/utils.c.o   -c /Users/cveeta/CLionProjects/minishell/utils.c

CMakeFiles/minishell.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/cveeta/CLionProjects/minishell/utils.c > CMakeFiles/minishell.dir/utils.c.i

CMakeFiles/minishell.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/cveeta/CLionProjects/minishell/utils.c -o CMakeFiles/minishell.dir/utils.c.s

# Object files for target minishell
minishell_OBJECTS = \
"CMakeFiles/minishell.dir/main.c.o" \
"CMakeFiles/minishell.dir/libft-main/ft_strjoin.c.o" \
"CMakeFiles/minishell.dir/libft-main/ft_strlen.c.o" \
"CMakeFiles/minishell.dir/libft-main/ft_strncmp.c.o" \
"CMakeFiles/minishell.dir/libft-main/ft_strdup.c.o" \
"CMakeFiles/minishell.dir/libft-main/ft_calloc.c.o" \
"CMakeFiles/minishell.dir/libft-main/ft_bzero.c.o" \
"CMakeFiles/minishell.dir/libft-main/ft_substr.c.o" \
"CMakeFiles/minishell.dir/libft-main/ft_strchr.c.o" \
"CMakeFiles/minishell.dir/f.c.o" \
"CMakeFiles/minishell.dir/realized_f.c.o" \
"CMakeFiles/minishell.dir/execve.c.o" \
"CMakeFiles/minishell.dir/perser.c.o" \
"CMakeFiles/minishell.dir/pepe.c.o" \
"CMakeFiles/minishell.dir/libft-main/ft_free.c.o" \
"CMakeFiles/minishell.dir/ft_init.c.o" \
"CMakeFiles/minishell.dir/libft-main/ft_isolating.c.o" \
"CMakeFiles/minishell.dir/libft-main/ft_lastcoldel.c.o" \
"CMakeFiles/minishell.dir/utils.c.o"

# External object files for target minishell
minishell_EXTERNAL_OBJECTS =

minishell: CMakeFiles/minishell.dir/main.c.o
minishell: CMakeFiles/minishell.dir/libft-main/ft_strjoin.c.o
minishell: CMakeFiles/minishell.dir/libft-main/ft_strlen.c.o
minishell: CMakeFiles/minishell.dir/libft-main/ft_strncmp.c.o
minishell: CMakeFiles/minishell.dir/libft-main/ft_strdup.c.o
minishell: CMakeFiles/minishell.dir/libft-main/ft_calloc.c.o
minishell: CMakeFiles/minishell.dir/libft-main/ft_bzero.c.o
minishell: CMakeFiles/minishell.dir/libft-main/ft_substr.c.o
minishell: CMakeFiles/minishell.dir/libft-main/ft_strchr.c.o
minishell: CMakeFiles/minishell.dir/f.c.o
minishell: CMakeFiles/minishell.dir/realized_f.c.o
minishell: CMakeFiles/minishell.dir/execve.c.o
minishell: CMakeFiles/minishell.dir/perser.c.o
minishell: CMakeFiles/minishell.dir/pepe.c.o
minishell: CMakeFiles/minishell.dir/libft-main/ft_free.c.o
minishell: CMakeFiles/minishell.dir/ft_init.c.o
minishell: CMakeFiles/minishell.dir/libft-main/ft_isolating.c.o
minishell: CMakeFiles/minishell.dir/libft-main/ft_lastcoldel.c.o
minishell: CMakeFiles/minishell.dir/utils.c.o
minishell: CMakeFiles/minishell.dir/build.make
minishell: CMakeFiles/minishell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking C executable minishell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minishell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minishell.dir/build: minishell

.PHONY : CMakeFiles/minishell.dir/build

CMakeFiles/minishell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minishell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minishell.dir/clean

CMakeFiles/minishell.dir/depend:
	cd /Users/cveeta/CLionProjects/minishell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cveeta/CLionProjects/minishell /Users/cveeta/CLionProjects/minishell /Users/cveeta/CLionProjects/minishell/cmake-build-debug /Users/cveeta/CLionProjects/minishell/cmake-build-debug /Users/cveeta/CLionProjects/minishell/cmake-build-debug/CMakeFiles/minishell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minishell.dir/depend
