#pragma once
#ifndef ROUTEINFO_H
#define ROUTEINFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

#define MAXSTATIONNAME 15

typedef struct Route {
	int routeName;
	char station1[MAXSTATIONNAME];
	char station2[MAXSTATIONNAME];
	char station3[MAXSTATIONNAME];
	char station4[MAXSTATIONNAME];
	char station5[MAXSTATIONNAME];
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
