﻿# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\hola_jupiter.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\hola_jupiter.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\hola_jupiter.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\hola_jupiter.dir\flags.make

CMakeFiles\hola_jupiter.dir\main.cpp.obj: CMakeFiles\hola_jupiter.dir\flags.make
CMakeFiles\hola_jupiter.dir\main.cpp.obj: C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter\main.cpp
CMakeFiles\hola_jupiter.dir\main.cpp.obj: CMakeFiles\hola_jupiter.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hola_jupiter.dir/main.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\hola_jupiter.dir\main.cpp.obj.d --working-dir=C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~1\MICROS~1\2022\COMMUN~1\VC\Tools\MSVC\1437~1.328\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\hola_jupiter.dir\main.cpp.obj /FdCMakeFiles\hola_jupiter.dir\ /FS -c C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter\main.cpp
<<

CMakeFiles\hola_jupiter.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hola_jupiter.dir/main.cpp.i"
	C:\PROGRA~1\MICROS~1\2022\COMMUN~1\VC\Tools\MSVC\1437~1.328\bin\Hostx64\x64\cl.exe > CMakeFiles\hola_jupiter.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter\main.cpp
<<

CMakeFiles\hola_jupiter.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hola_jupiter.dir/main.cpp.s"
	C:\PROGRA~1\MICROS~1\2022\COMMUN~1\VC\Tools\MSVC\1437~1.328\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\hola_jupiter.dir\main.cpp.s /c C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter\main.cpp
<<

# Object files for target hola_jupiter
hola_jupiter_OBJECTS = \
"CMakeFiles\hola_jupiter.dir\main.cpp.obj"

# External object files for target hola_jupiter
hola_jupiter_EXTERNAL_OBJECTS =

hola_jupiter.exe: CMakeFiles\hola_jupiter.dir\main.cpp.obj
hola_jupiter.exe: CMakeFiles\hola_jupiter.dir\build.make
hola_jupiter.exe: C:\Users\LENOVO\.vcpkg-clion\vcpkg\installed\x64-windows\debug\lib\box2d.lib
hola_jupiter.exe: CMakeFiles\hola_jupiter.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hola_jupiter.exe"
	"C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\hola_jupiter.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100226~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100226~1.0\x64\mt.exe --manifests -- C:\PROGRA~1\MICROS~1\2022\COMMUN~1\VC\Tools\MSVC\1437~1.328\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\hola_jupiter.dir\objects1.rsp @<<
 /out:hola_jupiter.exe /implib:hola_jupiter.lib /pdb:C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter\cmake-build-debug\hola_jupiter.pdb /version:0.0 /machine:x64 /debug /INCREMENTAL /subsystem:console  C:\Users\LENOVO\.vcpkg-clion\vcpkg\installed\x64-windows\debug\lib\box2d.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe -noprofile -executionpolicy Bypass -file C:/Users/LENOVO/.vcpkg-clion/vcpkg/scripts/buildsystems/msbuild/applocal.ps1 -targetBinary C:/Users/LENOVO/Documents/Sim_Fisicas_KAAC/hola_jupiter/cmake-build-debug/hola_jupiter.exe -installedDir C:/Users/LENOVO/.vcpkg-clion/vcpkg/installed/x64-windows/debug/bin -OutVariable out

# Rule to build all files generated by this target.
CMakeFiles\hola_jupiter.dir\build: hola_jupiter.exe
.PHONY : CMakeFiles\hola_jupiter.dir\build

CMakeFiles\hola_jupiter.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hola_jupiter.dir\cmake_clean.cmake
.PHONY : CMakeFiles\hola_jupiter.dir\clean

CMakeFiles\hola_jupiter.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter\cmake-build-debug C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter\cmake-build-debug C:\Users\LENOVO\Documents\Sim_Fisicas_KAAC\hola_jupiter\cmake-build-debug\CMakeFiles\hola_jupiter.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\hola_jupiter.dir\depend

