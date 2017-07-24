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
	route *p = routeList->next;

	printf("\n\t\t\t\t����·����Ϣ��\n\n");
	printf("\n\t\t·����\tվ��1\tվ��2\tվ��3\tվ��4\tվ��5\n");

	while (p) {
		printf("\t\t%d\t%s\t%s\t%s\t%s\t%s\n", p->routeName, p->station1, p->station2, p->station3, p->station4, p->station5);
		p = p->next;
	}
	printf("\n\t\t\t\t������Ϣ����������Ŷ~\n\n");
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

		printf("\n\t\t\t\t�������һվ��");
		scanf_s("%s", p->station1, MAXSTATIONNAME);
		printf("\n\t\t\t\t������ڶ�վ��");
		scanf_s("%s", p->station2, MAXSTATIONNAME);
		printf("\n\t\t\t\t���������վ��");
		scanf_s("%s", p->station3, MAXSTATIONNAME);
		printf("\n\t\t\t\t���������վ��");
		scanf_s("%s", p->station4, MAXSTATIONNAME);
		printf("\n\t\t\t\t���������վ��");
		scanf_s("%s", p->station5, MAXSTATIONNAME);

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
	
	if (!searchRouteList(routeName)) {
		printf("\n\t\t\t\tҪ�޸ĵ���Ϣ������\n");
		return 0;
	}

	printf("\n\t\t\t\t�����޸ĵ�%d��·�ߵ���ϢŶ\n", routeName);
	
	printf("\n\t\t\t\t�������һվ��");
	scanf_s("%s", p->station1, MAXSTATIONNAME);
	printf("\n\t\t\t\t������ڶ�վ��");
	scanf_s("%s", p->station2, MAXSTATIONNAME);
	printf("\n\t\t\t\t���������վ��");
	scanf_s("%s", p->station3, MAXSTATIONNAME);
	printf("\n\t\t\t\t���������վ��");
	scanf_s("%s", p->station4, MAXSTATIONNAME);
	printf("\n\t\t\t\t���������վ��");
	scanf_s("%s", p->station5, MAXSTATIONNAME);

	saveFile(3);

	printf("\n\t\t\t\t�޸ĳɹ��� ");

	return 1;
}

void searchByRouteName(int routeName) {
	route *p = searchRouteList(routeName);

	if (p) {
		printf("\n\t\t·����\tվ��1\tվ��2\tվ��3\tվ��4\tվ��5\n");
		printf("\t\t%d\t%s\t%s\t%s\t%s\t%s\n", p->routeName, p->station1, p->station2, p->station3, p->station4, p->station5);
	}
	else printf("\n\t\t\t\t��Ҫ��ѯ��·�߲�����Ŷ~\n\n");
}