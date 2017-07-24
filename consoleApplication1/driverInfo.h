#pragma once
#ifndef DRIVERINFO_H
#define DRIVERINFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

#define MAXNAMENUM 15
#define MAXPHONENUM 12
#define MAXPLATENUM 15

typedef struct Driver {
	char driverName[MAXNAMENUM];
	char phone[MAXPHONENUM];
	int age;
	char currentPlate[MAXPLATENUM];
	struct Driver *next;
}driver;
driver *driverList;

int initDriverInfoList(void);
int checkDriverListEmpty(void);
driver *searchDriverList(char driverName[]);
void displayDriverInfo(void);
int addDriverInfo(void);
int deleteDriverInfo(char driverName[]);
int modifyDriverInfo(char driverName[]);
void searchByDriverName(char driverName[]);

#endif // !DRIVERINFO_H
