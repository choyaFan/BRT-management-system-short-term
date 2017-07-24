#include "driverInfo.h"

int initDriverInfoList(void) {
	//创建链表
	driverList = (driver *)malloc(sizeof(driver));
	if (!driverList) return 0;
	driverList->next = NULL;
	return 1;
}

int checkDriverListEmpty(void) {
	return driverList->next == NULL;
}

driver *searchDriverList(char driverName[]) {
	driver *p;
	p = driverList->next;
	while (p && strcmp(p->driverName, driverName) != 0) {
		p = p->next;
	}
	return p;
}

void displayDriverInfo(void) {
	driver *p;
	p = driverList->next;

	printf("\n\t\t\t\t所有司机信息：\n\n");
	printf("\n\t\t姓名\t年龄\t联系方式\t车牌号\n");
	while (p) {
		printf("\t\t%s\t%d\t%s\t\t%s\n", p->driverName, p->age, p->phone, p->currentPlate);
		p = p->next;
	}
	printf("\n\t\t\t\t所有信息都在这里了哦~\n\n");
	//应该要释放内存
	if (!p) {
		free((void *)p);
	}
}

int addDriverInfo(void) {
	int count, i;
	printf("\n\t\t\t\t你要录入几位司机的信息呢？");
	scanf("%d", &count);
	for (i = 0; i < count; i++) {
		driver *p = (driver *)malloc(sizeof(driver));
		if (!p) {
			printf("\a\t\t\t\t好像失败了哦\n");
			return 0;
		}
		printf("\t\t\t\t正在录入第%d个人的信息~\n", i + 1);
		printf("\t\t\t\t请输入司机名字：");
		scanf_s("%s", p->driverName, MAXNAMENUM);

		//判断此人是否已存在
		if (searchDriverList(p->driverName)) {
			printf("\n\t\t\t\t名字为%s的司机已存在\n", p->driverName);
			continue;
		}

		printf("\n\t\t\t\t请输入年龄：");
		scanf_s("%d", &p->age);
		printf("\n\t\t\t\t请输入联系方式：");
		scanf_s("%s", p->phone, MAXPHONENUM);
		printf("\n\t\t\t\t请输入司机当前所驾驶的车辆车牌号：");
		scanf_s("%s", p->currentPlate, MAXPLATENUM);
		p->next = driverList->next;
		driverList->next = p;
		
		saveFile(2);//保存

	}
	return 1;
}

int deleteDriverInfo(char driverName[]) {
	driver *p, *q;

	if (!searchDriverList(driverName)) {
		printf("\n\t\t\t\t要删除的信息不存在\n");
		return 0;
	}

	p = driverList->next;
	q = driverList;

	while (strcmp(p->driverName, driverName) != 0) {
		q = p;
		p = p->next;
	}
	q->next = p->next;

	saveFile(2);

	free((void *)p);
	return 1;
}

int modifyDriverInfo(char driverName[]) {
	driver *p = searchDriverList(driverName);

	if (!searchDriverList(driverName)) {
		printf("\n\t\t\t\t要修改的信息不存在\n");
		return 0;
	}

	printf("\n\t\t\t\t你在修改名字为%s的司机信息哦\n", driverName);

	printf("\n\t\t\t\t请输入年龄：");
	scanf_s("%d", &p->age);
	printf("\n\t\t\t\t请输入联系方式：");
	scanf_s("%s", p->phone, MAXPHONENUM);
	printf("\n\t\t\t\t请输入司机当前所驾驶的车辆车牌号：");
	scanf_s("%s", p->currentPlate, MAXPLATENUM);

	saveFile(2);

	printf("\n\t\t\t\t修改成功！ ");

	return 1;
}

void searchByDriverName(char driverName[]) {
	driver *p;
	p = searchDriverList(driverName);

	if (p) {
		printf("\n\t\t姓名\t年龄\t联系方式\t车牌号\n");
		printf("\t\t%s\t%d\t%s\t\t%s\n", p->driverName, p->age, p->phone, p->currentPlate);
	}
	else printf("\n\t\t\t\t您要查询的司机不存在哦~\n\n");
}