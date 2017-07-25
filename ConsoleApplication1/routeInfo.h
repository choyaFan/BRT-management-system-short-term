#pragma once
#ifndef ROUTEINFO_H
#define ROUTEINFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "busInfo.h"

#define MAXSTATIONNAME 15
#define MAXSTATIONNUM 30

typedef struct Route {
	int routeName;
	char station[MAXSTATIONNUM][MAXSTATIONNAME];
	int stationNum;
	struct Route *next;
}route;

route *routeList;

int initRouteInfoList(void);
int checkRouteListEmpty(void);
route *searchRouteList(int routeName);
void displayRouteInfo(void);
int addRouteInfo(void);
int deleteRouteInfo(int routeName);
int modifyRouteInfo(int routeName);
void searchByRouteName(int routeName);

#endif // !ROUTEINFO_H
