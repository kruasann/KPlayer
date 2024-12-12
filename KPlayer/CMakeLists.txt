cmake_minimum_required(VERSION 3.16)
project(MediaPlayer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Укажите путь к вашей установке Qt
set(CMAKE_PREFIX_PATH "N:/Qt/6.6.3/mingw_64/lib/cmake")  # Замените на ваш путь

# Находим необходимые компоненты Qt
find_package(Qt6 COMPONENTS Widgets Multimedia MultimediaWidgets REQUIRED)

# Enable automatic MOC, UIC, and RCC processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Explicitly list source files
set(SOURCES
src/main.cpp
src/App.cpp
src/UI/Button.cpp
src/UI/Slider.cpp
src/UI/AudioVisualizer.cpp
src/UI/MainScene.cpp
src/UI/Scene.cpp
src/UI/Menu.cpp
src/UI/PlayerScene.cpp
src/Utils/FileManager.cpp
src/Player/MediaPlayer.cpp
src/resources.qrc
)

# Add executable
qt_add_executable(MediaPlayer
${SOURCES}
)

# Link required Qt libraries
target_link_libraries(MediaPlayer PRIVATE
Qt6::Widgets
Qt6::Multimedia
Qt6::MultimediaWidgets
)

# Add include directories
target_include_directories(MediaPlayer PRIVATE
${CMAKE_SOURCE_DIR}/src
)

# Windows-specific settings
if(WIN32)
target_sources(MediaPlayer PRIVATE src/app.rc)
set_target_properties(MediaPlayer PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

# Debug output
message(STATUS "Source files: ${SOURCES}")

# Add MSVC-specific flags
if (MSVC)
add_compile_options(/Zc:__cplusplus)
endif()