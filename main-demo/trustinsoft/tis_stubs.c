// This file should contain stubs that are required to run the project's
// analyses.
//
// For instance, if your program calls an external function [int foo(int)] and
// you do not have its definition, you can write a stub like:
//
//     int foo(int x) {
//         return tis_interval(0, 100);
//     }
//
// If you have the definition, but you want to override it, you can write a stub
// like:
//
//    int foo(int x) __attribute__((tis_override)) {
//        return tis_interval(0, 100);
//    }
//
// This header contains all the necessary utilities to stub functions.
#include <tis_builtin.h>
