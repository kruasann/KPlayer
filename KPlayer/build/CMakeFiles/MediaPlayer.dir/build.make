# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = N:\KPlayer\KPlayer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = N:\KPlayer\KPlayer\build

# Include any dependencies generated for this target.
include CMakeFiles/MediaPlayer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MediaPlayer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MediaPlayer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MediaPlayer.dir/flags.make

MediaPlayer_autogen/timestamp: N:/Qt/6.6.3/mingw_64/./bin/moc.exe
MediaPlayer_autogen/timestamp: N:/Qt/6.6.3/mingw_64/./bin/uic.exe
MediaPlayer_autogen/timestamp: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target MediaPlayer"
	"C:\Program Files\CMake\bin\cmake.exe" -E cmake_autogen N:/KPlayer/KPlayer/build/CMakeFiles/MediaPlayer_autogen.dir/AutogenInfo.json ""
	"C:\Program Files\CMake\bin\cmake.exe" -E touch N:/KPlayer/KPlayer/build/MediaPlayer_autogen/timestamp

MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp: N:/KPlayer/KPlayer/src/resources.qrc
MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp: CMakeFiles/MediaPlayer_autogen.dir/AutoRcc_resources_UVLADIE3JM_Info.json
MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp: N:/KPlayer/KPlayer/src/assets/styles/style.qss
MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp: N:/KPlayer/KPlayer/src/assets/icons/delete.png
MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp: N:/KPlayer/KPlayer/src/assets/icons/stop.png
MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp: N:/KPlayer/KPlayer/src/assets/icons/pause.png
MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp: N:/KPlayer/KPlayer/src/assets/icons/play.png
MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp: N:/KPlayer/KPlayer/src/assets/icons/app_icon.ico
MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp: N:/Qt/6.6.3/mingw_64/./bin/rcc.exe
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Automatic RCC for src/resources.qrc"
	"C:\Program Files\CMake\bin\cmake.exe" -E cmake_autorcc N:/KPlayer/KPlayer/build/CMakeFiles/MediaPlayer_autogen.dir/AutoRcc_resources_UVLADIE3JM_Info.json 

CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/mocs_compilation.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/mocs_compilation.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/mocs_compilation.cpp.obj: MediaPlayer_autogen/mocs_compilation.cpp
CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/mocs_compilation.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/mocs_compilation.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\MediaPlayer.dir\MediaPlayer_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\MediaPlayer_autogen\mocs_compilation.cpp.obj -c N:\KPlayer\KPlayer\build\MediaPlayer_autogen\mocs_compilation.cpp

CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/mocs_compilation.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\build\MediaPlayer_autogen\mocs_compilation.cpp > CMakeFiles\MediaPlayer.dir\MediaPlayer_autogen\mocs_compilation.cpp.i

CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/mocs_compilation.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\build\MediaPlayer_autogen\mocs_compilation.cpp -o CMakeFiles\MediaPlayer.dir\MediaPlayer_autogen\mocs_compilation.cpp.s

CMakeFiles/MediaPlayer.dir/src/App.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/App.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/App.cpp.obj: N:/KPlayer/KPlayer/src/App.cpp
CMakeFiles/MediaPlayer.dir/src/App.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MediaPlayer.dir/src/App.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/App.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\App.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\App.cpp.obj -c N:\KPlayer\KPlayer\src\App.cpp

CMakeFiles/MediaPlayer.dir/src/App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/App.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\App.cpp > CMakeFiles\MediaPlayer.dir\src\App.cpp.i

CMakeFiles/MediaPlayer.dir/src/App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/App.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\App.cpp -o CMakeFiles\MediaPlayer.dir\src\App.cpp.s

CMakeFiles/MediaPlayer.dir/src/Player/AudioPlayer.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/Player/AudioPlayer.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/Player/AudioPlayer.cpp.obj: N:/KPlayer/KPlayer/src/Player/AudioPlayer.cpp
CMakeFiles/MediaPlayer.dir/src/Player/AudioPlayer.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MediaPlayer.dir/src/Player/AudioPlayer.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/Player/AudioPlayer.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\Player\AudioPlayer.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\Player\AudioPlayer.cpp.obj -c N:\KPlayer\KPlayer\src\Player\AudioPlayer.cpp

CMakeFiles/MediaPlayer.dir/src/Player/AudioPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/Player/AudioPlayer.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\Player\AudioPlayer.cpp > CMakeFiles\MediaPlayer.dir\src\Player\AudioPlayer.cpp.i

CMakeFiles/MediaPlayer.dir/src/Player/AudioPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/Player/AudioPlayer.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\Player\AudioPlayer.cpp -o CMakeFiles\MediaPlayer.dir\src\Player\AudioPlayer.cpp.s

CMakeFiles/MediaPlayer.dir/src/Player/MediaPlayer.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/Player/MediaPlayer.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/Player/MediaPlayer.cpp.obj: N:/KPlayer/KPlayer/src/Player/MediaPlayer.cpp
CMakeFiles/MediaPlayer.dir/src/Player/MediaPlayer.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MediaPlayer.dir/src/Player/MediaPlayer.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/Player/MediaPlayer.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\Player\MediaPlayer.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\Player\MediaPlayer.cpp.obj -c N:\KPlayer\KPlayer\src\Player\MediaPlayer.cpp

CMakeFiles/MediaPlayer.dir/src/Player/MediaPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/Player/MediaPlayer.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\Player\MediaPlayer.cpp > CMakeFiles\MediaPlayer.dir\src\Player\MediaPlayer.cpp.i

CMakeFiles/MediaPlayer.dir/src/Player/MediaPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/Player/MediaPlayer.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\Player\MediaPlayer.cpp -o CMakeFiles\MediaPlayer.dir\src\Player\MediaPlayer.cpp.s

CMakeFiles/MediaPlayer.dir/src/Player/VideoPlayer.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/Player/VideoPlayer.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/Player/VideoPlayer.cpp.obj: N:/KPlayer/KPlayer/src/Player/VideoPlayer.cpp
CMakeFiles/MediaPlayer.dir/src/Player/VideoPlayer.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/MediaPlayer.dir/src/Player/VideoPlayer.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/Player/VideoPlayer.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\Player\VideoPlayer.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\Player\VideoPlayer.cpp.obj -c N:\KPlayer\KPlayer\src\Player\VideoPlayer.cpp

CMakeFiles/MediaPlayer.dir/src/Player/VideoPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/Player/VideoPlayer.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\Player\VideoPlayer.cpp > CMakeFiles\MediaPlayer.dir\src\Player\VideoPlayer.cpp.i

CMakeFiles/MediaPlayer.dir/src/Player/VideoPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/Player/VideoPlayer.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\Player\VideoPlayer.cpp -o CMakeFiles\MediaPlayer.dir\src\Player\VideoPlayer.cpp.s

CMakeFiles/MediaPlayer.dir/src/UI/AudioVisualizer.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/UI/AudioVisualizer.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/UI/AudioVisualizer.cpp.obj: N:/KPlayer/KPlayer/src/UI/AudioVisualizer.cpp
CMakeFiles/MediaPlayer.dir/src/UI/AudioVisualizer.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/MediaPlayer.dir/src/UI/AudioVisualizer.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/UI/AudioVisualizer.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\UI\AudioVisualizer.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\UI\AudioVisualizer.cpp.obj -c N:\KPlayer\KPlayer\src\UI\AudioVisualizer.cpp

CMakeFiles/MediaPlayer.dir/src/UI/AudioVisualizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/UI/AudioVisualizer.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\UI\AudioVisualizer.cpp > CMakeFiles\MediaPlayer.dir\src\UI\AudioVisualizer.cpp.i

CMakeFiles/MediaPlayer.dir/src/UI/AudioVisualizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/UI/AudioVisualizer.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\UI\AudioVisualizer.cpp -o CMakeFiles\MediaPlayer.dir\src\UI\AudioVisualizer.cpp.s

CMakeFiles/MediaPlayer.dir/src/UI/Button.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/UI/Button.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/UI/Button.cpp.obj: N:/KPlayer/KPlayer/src/UI/Button.cpp
CMakeFiles/MediaPlayer.dir/src/UI/Button.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/MediaPlayer.dir/src/UI/Button.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/UI/Button.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\UI\Button.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\UI\Button.cpp.obj -c N:\KPlayer\KPlayer\src\UI\Button.cpp

CMakeFiles/MediaPlayer.dir/src/UI/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/UI/Button.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\UI\Button.cpp > CMakeFiles\MediaPlayer.dir\src\UI\Button.cpp.i

CMakeFiles/MediaPlayer.dir/src/UI/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/UI/Button.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\UI\Button.cpp -o CMakeFiles\MediaPlayer.dir\src\UI\Button.cpp.s

CMakeFiles/MediaPlayer.dir/src/UI/MainScene.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/UI/MainScene.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/UI/MainScene.cpp.obj: N:/KPlayer/KPlayer/src/UI/MainScene.cpp
CMakeFiles/MediaPlayer.dir/src/UI/MainScene.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/MediaPlayer.dir/src/UI/MainScene.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/UI/MainScene.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\UI\MainScene.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\UI\MainScene.cpp.obj -c N:\KPlayer\KPlayer\src\UI\MainScene.cpp

CMakeFiles/MediaPlayer.dir/src/UI/MainScene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/UI/MainScene.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\UI\MainScene.cpp > CMakeFiles\MediaPlayer.dir\src\UI\MainScene.cpp.i

CMakeFiles/MediaPlayer.dir/src/UI/MainScene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/UI/MainScene.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\UI\MainScene.cpp -o CMakeFiles\MediaPlayer.dir\src\UI\MainScene.cpp.s

CMakeFiles/MediaPlayer.dir/src/UI/Menu.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/UI/Menu.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/UI/Menu.cpp.obj: N:/KPlayer/KPlayer/src/UI/Menu.cpp
CMakeFiles/MediaPlayer.dir/src/UI/Menu.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/MediaPlayer.dir/src/UI/Menu.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/UI/Menu.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\UI\Menu.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\UI\Menu.cpp.obj -c N:\KPlayer\KPlayer\src\UI\Menu.cpp

CMakeFiles/MediaPlayer.dir/src/UI/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/UI/Menu.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\UI\Menu.cpp > CMakeFiles\MediaPlayer.dir\src\UI\Menu.cpp.i

CMakeFiles/MediaPlayer.dir/src/UI/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/UI/Menu.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\UI\Menu.cpp -o CMakeFiles\MediaPlayer.dir\src\UI\Menu.cpp.s

CMakeFiles/MediaPlayer.dir/src/UI/PlayerScene.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/UI/PlayerScene.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/UI/PlayerScene.cpp.obj: N:/KPlayer/KPlayer/src/UI/PlayerScene.cpp
CMakeFiles/MediaPlayer.dir/src/UI/PlayerScene.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/MediaPlayer.dir/src/UI/PlayerScene.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/UI/PlayerScene.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\UI\PlayerScene.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\UI\PlayerScene.cpp.obj -c N:\KPlayer\KPlayer\src\UI\PlayerScene.cpp

CMakeFiles/MediaPlayer.dir/src/UI/PlayerScene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/UI/PlayerScene.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\UI\PlayerScene.cpp > CMakeFiles\MediaPlayer.dir\src\UI\PlayerScene.cpp.i

CMakeFiles/MediaPlayer.dir/src/UI/PlayerScene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/UI/PlayerScene.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\UI\PlayerScene.cpp -o CMakeFiles\MediaPlayer.dir\src\UI\PlayerScene.cpp.s

CMakeFiles/MediaPlayer.dir/src/UI/Scene.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/UI/Scene.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/UI/Scene.cpp.obj: N:/KPlayer/KPlayer/src/UI/Scene.cpp
CMakeFiles/MediaPlayer.dir/src/UI/Scene.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/MediaPlayer.dir/src/UI/Scene.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/UI/Scene.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\UI\Scene.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\UI\Scene.cpp.obj -c N:\KPlayer\KPlayer\src\UI\Scene.cpp

CMakeFiles/MediaPlayer.dir/src/UI/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/UI/Scene.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\UI\Scene.cpp > CMakeFiles\MediaPlayer.dir\src\UI\Scene.cpp.i

CMakeFiles/MediaPlayer.dir/src/UI/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/UI/Scene.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\UI\Scene.cpp -o CMakeFiles\MediaPlayer.dir\src\UI\Scene.cpp.s

CMakeFiles/MediaPlayer.dir/src/UI/Slider.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/UI/Slider.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/UI/Slider.cpp.obj: N:/KPlayer/KPlayer/src/UI/Slider.cpp
CMakeFiles/MediaPlayer.dir/src/UI/Slider.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/MediaPlayer.dir/src/UI/Slider.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/UI/Slider.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\UI\Slider.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\UI\Slider.cpp.obj -c N:\KPlayer\KPlayer\src\UI\Slider.cpp

CMakeFiles/MediaPlayer.dir/src/UI/Slider.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/UI/Slider.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\UI\Slider.cpp > CMakeFiles\MediaPlayer.dir\src\UI\Slider.cpp.i

CMakeFiles/MediaPlayer.dir/src/UI/Slider.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/UI/Slider.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\UI\Slider.cpp -o CMakeFiles\MediaPlayer.dir\src\UI\Slider.cpp.s

CMakeFiles/MediaPlayer.dir/src/Utils/FileManager.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/Utils/FileManager.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/Utils/FileManager.cpp.obj: N:/KPlayer/KPlayer/src/Utils/FileManager.cpp
CMakeFiles/MediaPlayer.dir/src/Utils/FileManager.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/MediaPlayer.dir/src/Utils/FileManager.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/Utils/FileManager.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\Utils\FileManager.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\Utils\FileManager.cpp.obj -c N:\KPlayer\KPlayer\src\Utils\FileManager.cpp

CMakeFiles/MediaPlayer.dir/src/Utils/FileManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/Utils/FileManager.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\Utils\FileManager.cpp > CMakeFiles\MediaPlayer.dir\src\Utils\FileManager.cpp.i

CMakeFiles/MediaPlayer.dir/src/Utils/FileManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/Utils/FileManager.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\Utils\FileManager.cpp -o CMakeFiles\MediaPlayer.dir\src\Utils\FileManager.cpp.s

CMakeFiles/MediaPlayer.dir/src/Utils/ThreadPool.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/Utils/ThreadPool.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/Utils/ThreadPool.cpp.obj: N:/KPlayer/KPlayer/src/Utils/ThreadPool.cpp
CMakeFiles/MediaPlayer.dir/src/Utils/ThreadPool.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/MediaPlayer.dir/src/Utils/ThreadPool.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/Utils/ThreadPool.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\Utils\ThreadPool.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\Utils\ThreadPool.cpp.obj -c N:\KPlayer\KPlayer\src\Utils\ThreadPool.cpp

CMakeFiles/MediaPlayer.dir/src/Utils/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/Utils/ThreadPool.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\Utils\ThreadPool.cpp > CMakeFiles\MediaPlayer.dir\src\Utils\ThreadPool.cpp.i

CMakeFiles/MediaPlayer.dir/src/Utils/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/Utils/ThreadPool.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\Utils\ThreadPool.cpp -o CMakeFiles\MediaPlayer.dir\src\Utils\ThreadPool.cpp.s

CMakeFiles/MediaPlayer.dir/src/main.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/main.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/src/main.cpp.obj: N:/KPlayer/KPlayer/src/main.cpp
CMakeFiles/MediaPlayer.dir/src/main.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/MediaPlayer.dir/src/main.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/src/main.cpp.obj -MF CMakeFiles\MediaPlayer.dir\src\main.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\src\main.cpp.obj -c N:\KPlayer\KPlayer\src\main.cpp

CMakeFiles/MediaPlayer.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/src/main.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\src\main.cpp > CMakeFiles\MediaPlayer.dir\src\main.cpp.i

CMakeFiles/MediaPlayer.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/src/main.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\src\main.cpp -o CMakeFiles\MediaPlayer.dir\src\main.cpp.s

CMakeFiles/MediaPlayer.dir/src/app.rc.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/src/app.rc.obj: N:/KPlayer/KPlayer/src/app.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building RC object CMakeFiles/MediaPlayer.dir/src/app.rc.obj"
	N:\Qt\Tools\mingw1120_64\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) N:\KPlayer\KPlayer\src\app.rc CMakeFiles\MediaPlayer.dir\src\app.rc.obj

CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp.obj: CMakeFiles/MediaPlayer.dir/flags.make
CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp.obj: CMakeFiles/MediaPlayer.dir/includes_CXX.rsp
CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp.obj: MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp
CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp.obj: CMakeFiles/MediaPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp.obj"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp.obj -MF CMakeFiles\MediaPlayer.dir\MediaPlayer_autogen\UVLADIE3JM\qrc_resources.cpp.obj.d -o CMakeFiles\MediaPlayer.dir\MediaPlayer_autogen\UVLADIE3JM\qrc_resources.cpp.obj -c N:\KPlayer\KPlayer\build\MediaPlayer_autogen\UVLADIE3JM\qrc_resources.cpp

CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp.i"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E N:\KPlayer\KPlayer\build\MediaPlayer_autogen\UVLADIE3JM\qrc_resources.cpp > CMakeFiles\MediaPlayer.dir\MediaPlayer_autogen\UVLADIE3JM\qrc_resources.cpp.i

CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp.s"
	N:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S N:\KPlayer\KPlayer\build\MediaPlayer_autogen\UVLADIE3JM\qrc_resources.cpp -o CMakeFiles\MediaPlayer.dir\MediaPlayer_autogen\UVLADIE3JM\qrc_resources.cpp.s

# Object files for target MediaPlayer
MediaPlayer_OBJECTS = \
"CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/App.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/Player/AudioPlayer.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/Player/MediaPlayer.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/Player/VideoPlayer.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/UI/AudioVisualizer.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/UI/Button.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/UI/MainScene.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/UI/Menu.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/UI/PlayerScene.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/UI/Scene.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/UI/Slider.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/Utils/FileManager.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/Utils/ThreadPool.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/main.cpp.obj" \
"CMakeFiles/MediaPlayer.dir/src/app.rc.obj" \
"CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp.obj"

# External object files for target MediaPlayer
MediaPlayer_EXTERNAL_OBJECTS =

MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/mocs_compilation.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/App.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/Player/AudioPlayer.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/Player/MediaPlayer.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/Player/VideoPlayer.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/UI/AudioVisualizer.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/UI/Button.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/UI/MainScene.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/UI/Menu.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/UI/PlayerScene.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/UI/Scene.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/UI/Slider.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/Utils/FileManager.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/Utils/ThreadPool.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/main.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/src/app.rc.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp.obj
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/build.make
MediaPlayer.exe: N:/Qt/6.6.3/mingw_64/lib/libQt6MultimediaWidgets.a
MediaPlayer.exe: N:/Qt/6.6.3/mingw_64/lib/libQt6Multimedia.a
MediaPlayer.exe: N:/Qt/6.6.3/mingw_64/lib/libQt6Network.a
MediaPlayer.exe: N:/Qt/6.6.3/mingw_64/lib/libQt6Widgets.a
MediaPlayer.exe: N:/Qt/6.6.3/mingw_64/lib/libQt6Gui.a
MediaPlayer.exe: N:/Qt/6.6.3/mingw_64/lib/libQt6Core.a
MediaPlayer.exe: N:/Qt/6.6.3/mingw_64/lib/libQt6EntryPoint.a
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/linkLibs.rsp
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/objects1.rsp
MediaPlayer.exe: CMakeFiles/MediaPlayer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=N:\KPlayer\KPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking CXX executable MediaPlayer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MediaPlayer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MediaPlayer.dir/build: MediaPlayer.exe
.PHONY : CMakeFiles/MediaPlayer.dir/build

CMakeFiles/MediaPlayer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MediaPlayer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MediaPlayer.dir/clean

CMakeFiles/MediaPlayer.dir/depend: MediaPlayer_autogen/UVLADIE3JM/qrc_resources.cpp
CMakeFiles/MediaPlayer.dir/depend: MediaPlayer_autogen/timestamp
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" N:\KPlayer\KPlayer N:\KPlayer\KPlayer N:\KPlayer\KPlayer\build N:\KPlayer\KPlayer\build N:\KPlayer\KPlayer\build\CMakeFiles\MediaPlayer.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MediaPlayer.dir/depend

