#pragma once
#ifndef BUSINFO_H
#define BUSINFO_H

#include "file.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAXPLATENUM 10
#define MAXMODELNUM 20

typedef struct Bus {
	char plateNum[MAXPLATENUM]; //车牌号
	int carRepairing; //0为正常，1为需维修，2为报废
	int capacity;  //最大载客人数
	int busNum;  //哪一路公交车
	int route;  //走的是几号线
	char modelNum[MAXMODELNUM];  //型号
	struct Bus *next;
}bus;
bus *busList;

int initBusInfoList(void);
int checkBusListEmpty(void);
bus *searchBusList(char plateNum[]);
void displayBusInfo(void);
int addBusInfo(void);
int deleteBusInfo(char plateNum[]);
int modifyBusInfo(char plateNum[]);
void searchByPlateNum(char plateNum[]);

#endif