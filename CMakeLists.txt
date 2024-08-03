cmake_minimum_required(VERSION 3.28)
project(singlyLinkedList C)

set(CMAKE_C_STANDARD 11)

add_executable(singlyLinkedList main.c
        linked_list.h
        linked_list.c)
