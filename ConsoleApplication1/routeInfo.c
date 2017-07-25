#include "routeInfo.h"

int initRouteInfoList(void) {
	//��������
	routeList = (route *)malloc(sizeof(route));
	if (!routeList) return 0;
	routeList->next = NULL;
	return 1;
}

int checkRouteListEmpty(void) {
	return routeList->next == NULL;
}

route *searchRouteList(int routeName) {
	route *p;
	p = routeList->next;
	while (p && p->routeName != routeName) {
		p = p->next;
	}
	return p;
}

void displayRouteInfo(void) {
	int i, count = 0;
	route *p = routeList->next;

	printf("\n\t\t\t\t����·����Ϣ��\n\n");
	printf("\n\t\t·����\t");
	while (p) { //Ѱ�����վ����
		if (p->stationNum >= count) count = p->stationNum;
		p = p->next;
	}
	p = routeList->next;
	for (i = 0; i < count; i++) { //����վ��������չʾ
		printf("վ��%d\t", i + 1);
	}
	printf("\n");//�ֶ�����

	while (p) {
		printf("\t\t%d\t", p->routeName);
		for (i = 0; i < p->stationNum; i++) { //����վ��������չʾ
			printf("%s\t", p->station[i]);
		}
		printf("\n"); //�ֶ�����
		p = p->next;
	}
	printf("\n\t\t\t\t������Ϣ����������Ŷ~\n\n");
	printf("\t\t************************************************************\n");
	//Ӧ��Ҫ�ͷ��ڴ�
	if (!p) {
		free((void *)p);
	}
	return 1;
}

int addRouteInfo(void) {
	int count, i;
	printf("\n\t\t\t\t��Ҫ¼�뼸��·�ߵ���Ϣ�أ�");
	scanf_s("%d", &count);
	
	for (i = 0; i < count; i++) {
		route *p = (route *)malloc(sizeof(route));
		if (!p) {
			printf("\a\t\t\t\t����ʧ����Ŷ\n");
			return 0;
		}
		printf("\t\t\t\t����¼���%d��·�ߵ���Ϣ~\n", i + 1);
		printf("\t\t\t\t������·������");
		scanf_s("%d", &p->routeName);
		
		//�жϴ�·���Ƿ����
		if (searchRouteList(p->routeName)) {
			printf("\n\t\t\t\t����Ϊ%d��·���Ѵ���\n", p->routeName);
			continue;
		}

		printf("\n\t\t\t\t������·�м���վ���أ������30վ��");
		scanf_s("%d", &p->stationNum);
		for (i = 0; i < p->stationNum; i++) {
			printf("\n\t\t\t\t�������%dվ��", i + 1);
			scanf_s("%s", p->station[i], MAXSTATIONNAME);
		}
		system("cls");
		p->next = routeList->next;
		routeList->next = p;

		//����
		saveFile(3);
	}
	return 1;
}

int deleteRouteInfo(int routeName) {
	route *p, *q;

	if (!searchRouteList(routeName)) {
		printf("\n\t\t\t\tҪɾ������Ϣ������\n");
		return 0;
	}

	p = routeList->next;
	q = routeList;
	while (p->routeName != routeName) {
		q = p;
		p = p->next;
	}
	q->next = p->next;
	deleteBusInfoByRouteName(routeName);
	saveFile(1);
	saveFile(3);

	free((void *)p);

	return 1;
}

int modifyRouteInfo(int routeName) {
	route *p = searchRouteList(routeName);
	int i;
	
	if (!searchRouteList(routeName)) {
		printf("\n\t\t\t\tҪ�޸ĵ���Ϣ������\n");
		return 0;
	}

	printf("\n\t\t\t\t�����޸�%d��·�ߵ���ϢŶ\n", routeName);

	printf("\n\t\t\t\t������վ����Ŀ��");
	scanf_s("%d", &p->stationNum);
	
	for (i = 0; i < p->stationNum; i++) {
		printf("\n\t\t\t\t�������%dվ��", i + 1);
		scanf_s("%s", p->station[i], MAXSTATIONNAME);
	}
	system("cls");
	saveFile(3);
	return 1;
}

void searchByRouteName(int routeName) {
	route *p = searchRouteList(routeName);
	int i;

	if (p) {
		printf("\n\t\t·����\t");
		for (i = 0; i < p->stationNum; i++) { //����վ��������չʾ
			printf("վ��%d\t", i + 1);
		}
		printf("\n");//�ֶ�����
		printf("\t\t%d\t", p->routeName);
		for (i = 0; i < p->stationNum; i++) { //����վ��������չʾ
			printf("%s\t", p->station[i]);
		}
		printf("\n"); //�ֶ�����
	}
	else printf("\n\t\t\t\t��Ҫ��ѯ��·�߲�����Ŷ~\n\n");
}