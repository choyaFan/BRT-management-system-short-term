#include "busInfo.h"

int initBusInfoList(void) {
	busList = (bus *)malloc(sizeof(bus)); //分配内存！
	if (!busList) {
		return 0;
	}
	busList->next = NULL;
	return 1;
}

int checkBusListEmpty(void) {
	return busList->next == NULL;
}

bus *searchBusList(char plateNum[]) {
	bus *p;
	p = busList->next;
	while (p && strcmp(p->plateNum, plateNum) != 0) {
		p = p->next;
	}
	return p;
}

void displayBusInfo(void) {
	bus *p;
	p = busList->next;

	printf("\n\t\t\t\t所有车辆信息：\n\n");
	printf("\n\t\t车牌号\t车况\t载客数\tX路\tX号线\t型号\n");
	while (p) {
		printf("\t\t%s\t", p->plateNum);
		if (!p->carRepairing)  printf("正常");
		else if (p->carRepairing == 1)  printf("需维修");
		else printf("报废了");
		printf("\t%d\t%d\t%d\t%s\n", p->capacity, p->busNum, p->route, p->modelNum);
		p = p->next;
	}
	printf("\n\t\t\t\t所有信息都在这里了哦~\n\n");
	//应该要释放内存
	if (!p) {
		free((void *)p);
	}
}

int addBusInfo(void) {
	int count, i;
	printf("\n\t\t\t\t你要录入几辆车的信息呢？");
	scanf("%d", &count);
	for (i = 0; i < count; i++) {
		bus *p = (bus *)malloc(sizeof(bus));
		if (!p) {
			printf("\a\t\t\t\t好像失败了哦\n");
			return 0;
		}
		printf("\t\t\t\t正在录入第%d辆车的信息~\n", i + 1);
		printf("\t\t\t\t请输入车牌号：");
		scanf_s("%s", p->plateNum, MAXPLATENUM);
		
		//判断车牌是否已存在
		if (searchBusList(p->plateNum)) {
			printf("\n\t\t\t\t车牌号%s的车已存在\n", p->plateNum);
			continue;
		}

		printf("\n\t\t\t\t请输入车况：");
		scanf_s("%d", &p->carRepairing);
		printf("\n\t\t\t\t请输入最大载客数量：");
		scanf_s("%d", &p->capacity);
		printf("\n\t\t\t\t是哪一路车呢？");
		scanf_s("%d", &p->busNum);
		printf("\n\t\t\t\t它要走几号线呢？");
		scanf_s("%d", &p->route);
		printf("\n\t\t\t\t请输入型号：");
		scanf_s("%s", p->modelNum, MAXMODELNUM);
		p->next = busList->next;
		busList->next = p;

		/*
		*这里是保存到文件
		*还没写……
		*/
		saveFile(1);
	}
	return 1;
}

int deleteBusInfo(char plateNum[]) {
	bus *p;
	bus *q;

	//判断车牌号是否存在、
	if (!searchBusList(plateNum)) {
		printf("\n\t\t\t\t不存在的\n");
		return 0;
	}
	
	p = busList->next;
	q = busList;

	//查找需要删除的信息
	while (strcmp(p->plateNum, plateNum) != 0) {
		q = p;
		p = p->next;
	}
	q->next = p->next;

	//文件保存
	saveFile(1);

	free(p);

	return 1;
}

int modifyBusInfo(char plateNum[]) {
	bus *p = searchBusList(plateNum);
	if (!searchBusList(plateNum)) {
		printf("\n\t\t\t\t没找到哦");
		return 0;
	}
	printf("\n\t\t\t\t你在修改车牌为%s的车辆信息哦\n", plateNum);

	printf("\n\t\t\t\t请输入车况：");
	scanf_s("%d", &p->carRepairing);
	printf("\n\t\t\t\t请输入最大载客数量：");
	scanf_s("%d", &p->capacity);
	printf("\n\t\t\t\t是哪一路车呢？");
	scanf_s("%d", &p->busNum);
	printf("\n\t\t\t\t它要走几号线呢？");
	scanf_s("%d", &p->route);
	printf("\n\t\t\t\t请输入型号：");
	scanf_s("%s", p->modelNum, MAXMODELNUM);

	//文件保存
	saveFile(1);

	printf("\n\t\t\t\t修改成功！ ");

	return 1; 
}

void searchByPlateNum(char plateNum[]){
	bus *p;
	p = busList->next;
	while (p && strcmp(p->plateNum, plateNum)) {
		p = p->next;
	}
	//展示
	if (p) {
		printf("\n\t\t车牌号\t车况\t载客数\tX路\tX号线\t型号\n");
		printf("\t\t%s\t", p->plateNum);
		if (!p->carRepairing)  printf("正常");
		else if (p->carRepairing == 1)  printf("需维修");
		else printf("报废了");
		printf("\t%d\t%d\t%d\t%s\n", p->capacity, p->busNum, p->route, p->modelNum);
	}
	else printf("\n\t\t\t\t您要查询的车辆不存在哦~\n\n");
}