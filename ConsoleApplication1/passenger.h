#pragma once
#ifndef PASSENGER_H
#define PASSENGER_H

#include "busInfo.h"
#include "routeInfo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void passengerChoice();
bus *searchBusNum(int busNum);
void displayRouteInfo2(int busNum);

#endif // !DRIVERINFO_H