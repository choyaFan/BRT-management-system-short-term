#include "passenger.h"

void passengerChoice() {
	int busNum;
	bus* p;
	printf("\n\t\t\t\t请您输入公交线路名(输入0退出）:");
	while (1) {
		scanf("%d", &busNum);
		if (busNum==0)
		{
			exit(0);//输入0退出乘客端
		}
		p = searchBusNum(busNum);
		if (p==NULL)//如果线路不存在就要求用户重新输入线路名进行下一次循环
		{
			printf("\n\t\t\t\t您输入的公交线路不存在，请重新输入：");
			continue;
		}
		else
		{
			displayRouteInfo2(busNum);//如果线路存在就打印一条线路上的每个站点
		}
		printf("\n\t\t\t\t请您输入公交线路名(输入0退出）:");
	}
}
bus *searchBusNum(int busNum) {
	bus *p = NULL;//设置为NULL防止线路不存在
	p = busList->next;
	while (p && p->busNum != busNum && p->route != 0) {//便利链表找到结点
		p = p->next;
	}
	return p;
}
void displayRouteInfo2(int busNum) {
	int count = 0;
	route* p = NULL;
	bus *t = searchBusNum(busNum);
	p = routeList->next;
	while (p)
	{
		if (p->routeName == t->route) {
			printf("%s", p->station[0]);
			for (int i = 1; i < p->stationNum; i++) {
				printf("-->%s", p->station[i]);
			}
			count++;
		}
		p = p->next;
	}
	if (count == 0) printf("\n\t\t\t\t路线不存在");
}