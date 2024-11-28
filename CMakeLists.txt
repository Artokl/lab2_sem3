cmake_minimum_required(VERSION 3.28)
project(lab_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab_2 main.cpp
        ArraySequence.h
        Isorter.h
        Sequence.h
        QuickSort.h
        MergeSort.h
        CountingSort.h
        Person.h)
