/**
 * @file spinningdot.h
 * @brief Header file for displaying a spinning dot animation and detecting the
 * OS.
 *
 * This header file provides the declaration for the `show_spinning_dot`
 * function, which displays a spinning dot animation for a specified duration.
 * It is useful for indicating loading or processing states in a console
 * application. Additionally, it includes a function to determine the operating
 * system at runtime.
 */
#ifndef SPINNINGDOT_H
#define SPINNINGDOT_H

void show_spinning_dot(int duration);

#endif

#ifdef _WIN32
#include <windows.h>
#define usleep(x) Sleep((x) / 1000) // Convert microseconds to milliseconds
#endif
