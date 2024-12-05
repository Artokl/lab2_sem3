cmake_minimum_required(VERSION 3.28)
project(lab_2)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(lab_2 main.cpp
        ArraySequence.h
        Isorter.h
        Sequence.h
        QuickSort.h
        MergeSort.h
        Person.h
        DefaultComparators.h
        PersonComparators.h
        Generator.h
        Tests/QuickSortTests.h
        Tests/MergeSortTests.h
        BinaryInsertionSort.h
        Tests/BinaryInsertionSortTests.h
        Ui/MainMenu.h
        Ui/SortMenu.h
        Ui/TestMenu.h)

target_link_libraries(lab_2 PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
