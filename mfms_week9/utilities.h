#ifndef UTILITIES_H
#define UTILITIES_H

#include <stddef.h>

int inputInt(const char *prompt);
double inputDouble(const char *prompt);
void readString(const char *prompt, char *buffer, size_t size);
void clearInputBuffer(void);
void printDivider(void);

#endif
