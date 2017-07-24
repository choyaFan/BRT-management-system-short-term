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
	char plateNum[MAXPLATENUM]; //���ƺ�
	int carRepairing; //0Ϊ������1Ϊ��ά�ޣ�2Ϊ����
	int capacity;  //����ؿ�����
	int busNum;  //��һ·������
	int route;  //�ߵ��Ǽ�����
	char modelNum[MAXMODELNUM];  //�ͺ�
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
void searchByBusNum(int busNum);
void deleteBusInfoByRouteName(int routeName);

#endif