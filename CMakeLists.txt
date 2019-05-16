cmake_minimum_required(VERSION 3.9)
project(ProgettoListaToDo)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "PATH_TO_QT/QT_VERSION/QT_ARCH/lib/cmake")
# Include a library search using find_package()
# via REQUIRED, specify that libraries are required
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
include_directories(.)


add_executable(ProgettoListaToDo main.cpp
        Board.cpp Board.h
        Checklist.cpp Checklist.h
        Date.cpp Date.h
        MainWindow.cpp MainWindow.h
        Observer.cpp Observer.h
        SottoTask.cpp SottoTask.h
        Subject.cpp Subject.h
        Task.cpp Task.h
        TaskView.cpp TaskView.h
        Time.cpp Time.h
        User.cpp User.h )


# specify which libraries to connect
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

