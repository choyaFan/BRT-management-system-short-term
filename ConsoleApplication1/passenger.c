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
			printf("\n\t\t\t\t������Ĺ�����·�����ڣ����������룺");
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
	if (count == 0) printf("\n\t\t\t\t·�߲�����");
}