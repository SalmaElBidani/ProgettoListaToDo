cmake_minimum_required(VERSION 3.9)
project(ProgettoListaToDo)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProgettoListaToDo main.cpp Board.cpp Board.h Checklist.cpp Checklist.h Date.cpp Date.h MainWindow.cpp MainWindow.h Observer.cpp Observer.h SottoTask.cpp SottoTask.h Subject.cpp Subject.h Task.cpp Task.h TaskView.cpp TaskView.h Time.cpp Time.h User.cpp User.h )