cmake_minimum_required(VERSION 3.16)
project(MediaPlayer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Укажите путь к вашей установке Qt
set(CMAKE_PREFIX_PATH "C:/Qt/6.6.0/mingw_64/lib/cmake")  # Замените на ваш путь

# Находим необходимые компоненты Qt
find_package(Qt6 COMPONENTS Widgets Multimedia MultimediaWidgets REQUIRED)

# Включаем автоматическую обработку MOC, UIC и RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Собираем все исходные файлы
file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/*.h
    src/resources.qrc
)

# Создаем исполняемый файл с поддержкой Qt
qt_add_executable(MediaPlayer
    ${SOURCES}
)

# Линкуем библиотеки Qt
target_link_libraries(MediaPlayer PRIVATE
    Qt6::Widgets
    Qt6::Multimedia
    Qt6::MultimediaWidgets
)

# Добавляем директории include
target_include_directories(MediaPlayer PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Установка флага для MSVC
if (MSVC)
    add_compile_options(/Zc:__cplusplus)
endif()
