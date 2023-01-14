cmake_minimum_required(VERSION 3.22)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(DesignPatterns main.cpp ExplicitConstructors/Printer.cpp ExplicitConstructors/Printer.h InterfaceInheritance/Person.h InterfaceInheritance/Talks.h InterfaceInheritance/Student.h)
