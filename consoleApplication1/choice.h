#pragma once
#ifndef CHOICE_H
#define CHOICE_H

#include "busInfo.h"
#include "driverInfo.h"
#include "routeInfo.h"
#include "passenger.h"
#include <stdio.h>
#include <stdlib.h>

void passMenu(void);
void mainChoice(void);
void busInfoChoice(void);
void driverInfoChoice(void);
void routeInfoChoice(void);

int main_choice;
int bus_InfoChoice;

#endif // !CHOICE_H
