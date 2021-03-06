#include "routeInfo.h"

int initRouteInfoList(void) {
	//创建链表
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

	printf("\n\t\t\t\t所有路线信息：\n\n");
	printf("\n\t\t路线名\t");
	while (p) { //寻找最大站点数
		if (p->stationNum >= count) count = p->stationNum;
		p = p->next;
	}
	p = routeList->next;
	for (i = 0; i < count; i++) { //根据站点数进行展示
		printf("站点%d\t", i + 1);
	}
	printf("\n");//手动换行

	while (p) {
		printf("\t\t%d\t", p->routeName);
		for (i = 0; i < p->stationNum; i++) { //根据站点数进行展示
			printf("%s\t", p->station[i]);
		}
		printf("\n"); //手动换行
		p = p->next;
	}
	printf("\n\t\t\t\t所有信息都在这里了哦~\n\n");
	printf("\t\t************************************************************\n");
	//应该要释放内存
	if (!p) {
		free((void *)p);
	}
	return 1;
}

int addRouteInfo(void) {
	int count, i;
	printf("\n\t\t\t\t你要录入几条路线的信息呢？");
	scanf_s("%d", &count);
	
	for (i = 0; i < count; i++) {
		route *p = (route *)malloc(sizeof(route));
		if (!p) {
			printf("\a\t\t\t\t好像失败了哦\n");
			return 0;
		}
		printf("\t\t\t\t正在录入第%d条路线的信息~\n", i + 1);
		printf("\t\t\t\t请输入路线名：");
		scanf_s("%d", &p->routeName);
		
		//判断此路线是否存在
		if (searchRouteList(p->routeName)) {
			printf("\n\t\t\t\t名字为%d的路线已存在\n", p->routeName);
			continue;
		}

		printf("\n\t\t\t\t这条线路有几个站点呢？（最多30站）");
		scanf_s("%d", &p->stationNum);
		for (i = 0; i < p->stationNum; i++) {
			printf("\n\t\t\t\t请输入第%d站：", i + 1);
			scanf_s("%s", p->station[i], MAXSTATIONNAME);
		}
		system("cls");
		p->next = routeList->next;
		routeList->next = p;

		//保存
		saveFile(3);
	}
	return 1;
}

int deleteRouteInfo(int routeName) {
	route *p, *q;

	if (!searchRouteList(routeName)) {
		printf("\n\t\t\t\t要删除的信息不存在\n");
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
		printf("\n\t\t\t\t要修改的信息不存在\n");
		return 0;
	}

	printf("\n\t\t\t\t你在修改%d号路线的信息哦\n", routeName);

	printf("\n\t\t\t\t请输入站点数目：");
	scanf_s("%d", &p->stationNum);
	
	for (i = 0; i < p->stationNum; i++) {
		printf("\n\t\t\t\t请输入第%d站：", i + 1);
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
		printf("\n\t\t路线名\t");
		for (i = 0; i < p->stationNum; i++) { //根据站点数进行展示
			printf("站点%d\t", i + 1);
		}
		printf("\n");//手动换行
		printf("\t\t%d\t", p->routeName);
		for (i = 0; i < p->stationNum; i++) { //根据站点数进行展示
			printf("%s\t", p->station[i]);
		}
		printf("\n"); //手动换行
	}
	else printf("\n\t\t\t\t您要查询的路线不存在哦~\n\n");
}