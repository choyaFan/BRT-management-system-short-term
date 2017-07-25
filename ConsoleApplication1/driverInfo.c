#include "driverInfo.h"

int initDriverInfoList(void) {
	//��������
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

	printf("\n\t\t\t\t����˾����Ϣ��\n\n");
	printf("\n\t\t����\t����\t��ϵ��ʽ\t���ƺ�\n");
	while (p) {
		printf("\t\t%s\t%d\t%s\t\t%s\n", p->driverName, p->age, p->phone, p->currentPlate);
		p = p->next;
	}
	printf("\n\t\t\t\t������Ϣ����������Ŷ~\n\n");
	printf("\t\t************************************************************\n");
	//Ӧ��Ҫ�ͷ��ڴ�
	if (!p) {
		free((void *)p);
	}
}

int addDriverInfo(void) {
	int count, i;
	printf("\n\t\t\t\t��Ҫ¼�뼸λ˾������Ϣ�أ�");
	scanf("%d", &count);
	for (i = 0; i < count; i++) {
		driver *p = (driver *)malloc(sizeof(driver));
		if (!p) {
			printf("\a\t\t\t\t����ʧ����Ŷ\n");
			return 0;
		}
		printf("\t\t\t\t����¼���%d���˵���Ϣ~\n", i + 1);
		printf("\t\t\t\t������˾�����֣�");
		scanf_s("%s", p->driverName, MAXNAMENUM);

		//�жϴ����Ƿ��Ѵ���
		if (searchDriverList(p->driverName)) {
			printf("\n\t\t\t\t����Ϊ%s��˾���Ѵ���\n", p->driverName);
			continue;
		}

		printf("\n\t\t\t\t���������䣺");
		scanf_s("%d", &p->age);
		printf("\n\t\t\t\t��������ϵ��ʽ��");
		scanf_s("%s", p->phone, MAXPHONENUM);
		printf("\n\t\t\t\t������˾����ǰ����ʻ�ĳ������ƺţ�");
		scanf_s("%s", p->currentPlate, MAXPLATENUM);
		system("cls");
		p->next = driverList->next;
		driverList->next = p;
		
		saveFile(2);//����

	}
	return 1;
}

int deleteDriverInfo(char driverName[]) {
	driver *p, *q;

	if (!searchDriverList(driverName)) {
		printf("\n\t\t\t\tҪɾ������Ϣ������\n");
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
		printf("\n\t\t\t\tҪ�޸ĵ���Ϣ������\n");
		return 0;
	}

	printf("\n\t\t\t\t�����޸�����Ϊ%s��˾����ϢŶ\n", driverName);

	printf("\n\t\t\t\t���������䣺");
	scanf_s("%d", &p->age);
	printf("\n\t\t\t\t��������ϵ��ʽ��");
	scanf_s("%s", p->phone, MAXPHONENUM);
	printf("\n\t\t\t\t������˾����ǰ����ʻ�ĳ������ƺţ�");
	scanf_s("%s", p->currentPlate, MAXPLATENUM);
	system("cls");
	saveFile(2);

	return 1;
}

void searchByDriverName(char driverName[]) {
	driver *p;
	p = searchDriverList(driverName);

	if (p) {
		printf("\n\t\t����\t����\t��ϵ��ʽ\t���ƺ�\n");
		printf("\t\t%s\t%d\t%s\t\t%s\n", p->driverName, p->age, p->phone, p->currentPlate);
	}
	else printf("\n\t\t\t\t��Ҫ��ѯ��˾��������Ŷ~\n\n");
}