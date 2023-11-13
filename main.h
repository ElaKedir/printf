#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#ifndef MAIN_H
#define MAIN_H


int _printf(const char *format, ...);
int print_char(int spec);
int print_string(char *spec);
int print_int(int spec);

#endif