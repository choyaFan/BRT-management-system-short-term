#include "passenger.h"

void passengerChoice() {
	int busNum;
	bus* p;
	printf("\n\t\t\t\t�������빫����·��(����0�˳���:");
	while (1) {
		scanf("%d", &busNum);
		if (busNum==0)
		{
			exit(0);//����0�˳��˿Ͷ�
		}
		p = searchBusNum(busNum);
		if (p==NULL)//�����·�����ھ�Ҫ���û�����������·��������һ��ѭ��
		{
			printf("\n\t\t\t\t���������·�������ڣ����������룺");
			continue;
		}
		else
		{
			displayRouteInfo2(busNum);//�����·���ھʹ�ӡһ����·�ϵ�ÿ��վ��
		}
		printf("\n\t\t\t\t�������빫����·��(����0�˳���:");
	}
}
bus *searchBusNum(int busNum) {
	bus *p = NULL;//����ΪNULL��ֹ��·������
	p = busList->next;
	while (p && p->busNum != busNum && p->route != 0) {//���������ҵ����
		p = p->next;
	}
	return p;
}
void displayRouteInfo2(int busNum) {
	route* p = NULL;
	bus *t = searchBusNum(busNum);
	p = routeList->next;
	while (p && p->routeName != t->route)
	{
		p = p->next;
	}
	printf("%s-->", p->station1);
	printf("%s-->", p->station2);
	printf("%s-->", p->station3);
	printf("%s-->", p->station4);
	printf("%s", p->station5);
}