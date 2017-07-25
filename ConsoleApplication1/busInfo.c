#include "busInfo.h"

int initBusInfoList(void) {
	busList = (bus *)malloc(sizeof(bus)); //�����ڴ棡
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
	system("cls");
	printf("\n\t\t\t\t���г�����Ϣ��\n\n");
	printf("\n\t\t���ƺ�\t����\t�ؿ���\tX·\tX����\t�ͺ�\n");
	while (p) {
		printf("\t\t%s\t", p->plateNum);
		if (!p->carRepairing)  printf("����");
		else if (p->carRepairing == 1)  printf("��ά��");
		else printf("������");
		printf("\t%d\t%d\t%d\t%s\n", p->capacity, p->busNum, p->route, p->modelNum);
		p = p->next;
	}
	printf("\n\t\t\t\t������Ϣ����������Ŷ~\n\n");
	printf("\t\t************************************************************\n");
	//Ӧ��Ҫ�ͷ��ڴ�
	if (!p) {
		free((void *)p);
	}
}

int addBusInfo(void) {
	int count, i;
	system("cls");
	printf("\n\t\t\t\t��Ҫ¼�뼸��������Ϣ�أ�");
	scanf("%d", &count);
	for (i = 0; i < count; i++) {
		bus *p = (bus *)malloc(sizeof(bus));
		if (!p) {
			printf("\a\t\t\t\t����ʧ����Ŷ\n");
			return 0;
		}
		printf("\t\t\t\t����¼���%d��������Ϣ~\n", i + 1);
		printf("\t\t\t\t�����복�ƺţ�");
		scanf_s("%s", p->plateNum, MAXPLATENUM);
		
		//�жϳ����Ƿ��Ѵ���
		if (searchBusList(p->plateNum)) {
			printf("\n\t\t\t\t���ƺ�%s�ĳ��Ѵ���\n", p->plateNum);
			continue;
		}

		printf("\n\t\t\t\t�����복����0Ϊ������1Ϊ��ά�ޣ�2Ϊ���ϣ���");
		scanf_s("%d", &p->carRepairing);
		printf("\n\t\t\t\t����������ؿ�������");
		scanf_s("%d", &p->capacity);
		printf("\n\t\t\t\t����һ·���أ�");
		scanf_s("%d", &p->busNum);
		printf("\n\t\t\t\t��Ҫ�߼������أ�");
		scanf_s("%d", &p->route);
		printf("\n\t\t\t\t�������ͺţ�");
		scanf_s("%s", p->modelNum, MAXMODELNUM);
		system("cls");
		p->next = busList->next;
		busList->next = p;

		/*
		*�����Ǳ��浽�ļ�
		*��ûд����
		*/
		saveFile(1);
	}
	return 1;
}

int deleteBusInfo(char plateNum[]) {
	bus *p;
	bus *q;
	system("cls");
	//�жϳ��ƺ��Ƿ���ڡ�
	if (!searchBusList(plateNum)) {
		printf("\n\t\t\t\t�����ڵ�\n");
		return 0;
	}
	
	p = busList->next;
	q = busList;

	//������Ҫɾ������Ϣ
	while (strcmp(p->plateNum, plateNum) != 0) {
		q = p;
		p = p->next;
	}
	q->next = p->next;

	//�ļ�����
	saveFile(1);

	free(p);

	return 1;
}

int modifyBusInfo(char plateNum[]) {
	system("cls");
	bus *p = searchBusList(plateNum);
	if (!searchBusList(plateNum)) {
		printf("\n\t\t\t\tû�ҵ�Ŷ");
		return 0;
	}
	printf("\n\t\t\t\t�����޸ĳ���Ϊ%s�ĳ�����ϢŶ\n", plateNum);

	printf("\n\t\t\t\t�����복����");
	scanf_s("%d", &p->carRepairing);
	printf("\n\t\t\t\t����������ؿ�������");
	scanf_s("%d", &p->capacity);
	printf("\n\t\t\t\t����һ·���أ�");
	scanf_s("%d", &p->busNum);
	printf("\n\t\t\t\t��Ҫ�߼������أ�");
	scanf_s("%d", &p->route);
	printf("\n\t\t\t\t�������ͺţ�");
	scanf_s("%s", p->modelNum, MAXMODELNUM);
	system("cls");
	//�ļ�����
	saveFile(1);

	return 1; 
}

void deleteBusInfoByRouteName(int routeName) {
	bus* p=NULL;
	p = busList->next;
	while (p->next) {
		if (p->route==routeName)
		{
			p->route = 0;
		}
		p = p->next;
	}
}
void searchByBusNum(int BusNum) {
<<<<<<< HEAD
	system("cls");
=======
>>>>>>> f96b7377afbbc8671af6cc9b3dd1a00e2a4163fb
	bus *p;
	p = busList->next;
	while (p && p->busNum != BusNum) {
		p = p->next;
	}
	//չʾ
	if (p) {
		printf("\n\t\t���ƺ�\t����\t�ؿ���\tX·\tX����\t�ͺ�\n");
		printf("\t\t%s\t", p->plateNum);
		if (!p->carRepairing)  printf("����");
		else if (p->carRepairing == 1)  printf("��ά��");
		else printf("������");
		printf("\t%d\t%d\t%d\t%s\n", p->capacity, p->busNum, p->route, p->modelNum);
	}
	else printf("\n\t\t\t\t��Ҫ��ѯ�ĳ���������Ŷ~\n\n");
}