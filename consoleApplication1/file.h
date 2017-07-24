#pragma once
#ifndef FILE_H
#define FILE_H

#include "busInfo.h"
#include "driverInfo.h"
#include "routeInfo.h"
#include <stdio.h>
#include <stdlib.h>

FILE *sysFile;
errno_t error;

int readFile(int type);
int saveFile(int type);

#endif // !FILE_H
