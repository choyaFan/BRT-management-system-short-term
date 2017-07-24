#include "choice.h"

void passMenu(void) {
	printf("\n\t\t\t\t��ӭ�������ٹ�������ϵͳ\n");
	printf("\n\t\t\t\t�������ǣ� 1.�˿�   2.����Ա  ��һλ�أ�\n");
	int passChoice;
	scanf_s("%d", &passChoice);
	initBusInfoList();
	initDriverInfoList();
	initRouteInfoList();
	switch (passChoice)
	{
	case 1: {
		readFile(1);
		readFile(3);
		passengerChoice();
		break;
	}
	case 2: {
		checkPass();
		mainChoice();
		break;
	}
	default:
		break;
	}

}

//���˵���
void mainChoice(void) {
	printf("\n\t\t\t\t1:  ������Ϣ����\n");
	printf("\t\t\t\t2:  ˾����Ϣ����\n");
	printf("\t\t\t\t3:  ·����Ϣ����\n");
	printf("\t\t\t\t0:  �˳�����\n");
	printf("\n\t\t\t\t���������ѡ��:");
	scanf_s("%d", &main_choice);
	switch (main_choice)
	{
	default:
	{
		mainChoice();
		break;
	}
	case 1: {
		//������Ϣ
		readFile(1);
		busInfoChoice();
		break;
	}
	case 2: {
		//˾����Ϣ
		readFile(2);
		driverInfoChoice();
		break;
	}
	case 3: {
		//·����Ϣ
		readFile(3);
		routeInfoChoice();
		break;
	}
	case 0: exit(0);
	}
}

void busInfoChoice(void) {
	printf("\n\t\t\t\t1:  ��ӳ�����Ϣ\n");
	printf("\t\t\t\t2:  ɾ��������Ϣ\n");
	printf("\t\t\t\t3:  �޸ĳ�����Ϣ\n");
	printf("\t\t\t\t4:  չʾ������Ϣ\n");
	printf("\t\t\t\t5:  ��ѯ������Ϣ\n");
	printf("\t\t\t\t0:  ������һ���˵�\n");
	printf("\n\t\t\t\t���������ѡ��");
	scanf_s("%d", &bus_InfoChoice);
	switch (bus_InfoChoice)
	{
	default:
	{
		busInfoChoice();
		break;
	}
	case 1: {  //��Ϣ���
		addBusInfo();
		busInfoChoice();
		break;
	}
	case 2: {  //��Ϣɾ��
		printf("\n\t\t\t\t��������Ҫɾ���ĳ������ƺţ�");
		char plateNum[MAXPLATENUM];
		scanf_s("%s", plateNum, MAXPLATENUM);
		if(deleteBusInfo(plateNum))
		printf("\n\t\t\t\tɾ���ɹ���\n");
		else printf("\n\t\t\t\tʧ���ˡ�����ô���ء���\n");
		busInfoChoice();
		break;
	}
	case 3: { //��Ϣ�޸�
		printf("\n\t\t\t\t��������Ҫ�޸ĵĳ������ƺţ�");
		char plateNum[MAXPLATENUM];
		scanf_s("%s", plateNum, MAXPLATENUM);
		if(modifyBusInfo(plateNum))
		printf("\n\t\t\t\t�޸ĳɹ���\n");
		else printf("\n\t\t\t\tʧ���ˡ�����ô���ء���\n");
		busInfoChoice();
		break;
	}
	case 4: { //��Ϣչʾ
		displayBusInfo();
		busInfoChoice();
		break;
	}
	case 5: { //��ѯ��Ϣ
		printf("\n\t\t\t\t��Ҫ��ѯ���Ǽ�·�������أ�");
		int busNum;
		scanf_s("%d", &busNum);
		searchByBusNum(busNum);
		busInfoChoice();
		break;
	}
	case 0: mainChoice(); break; //������һ��
	}
}

void driverInfoChoice(void) {
	printf("\n\t\t\t\t1:  ���˾����Ϣ\n");
	printf("\t\t\t\t2:  ɾ��˾����Ϣ\n");
	printf("\t\t\t\t3:  �޸�˾����Ϣ\n");
	printf("\t\t\t\t4:  չʾ˾����Ϣ\n");
	printf("\t\t\t\t5:  ��ѯ˾����Ϣ\n");
	printf("\t\t\t\t0:  ������һ���˵�\n");
	printf("\n\t\t\t\t���������ѡ��");
	scanf_s("%d", &bus_InfoChoice);
	switch (bus_InfoChoice)
	{
	default: {
		driverInfoChoice();
		break;
	}
	case 1: {
		addDriverInfo();
		driverInfoChoice();
		break;
	}
	case 2: {
		printf("\n\t\t\t\t��������Ҫɾ����˾�����֣�");
		char driverName[MAXNAMENUM];
		scanf_s("%s", driverName, MAXNAMENUM);
		if(deleteDriverInfo(driverName))
			printf("\n\t\t\t\tɾ���ɹ���\n");
		else printf("\n\t\t\t\tʧ���ˡ�����ô���ء���\n");
		driverInfoChoice();
		break;
	}
	case 3: {
		printf("\n\t\t\t\t��������Ҫ�޸ĵ�˾�����֣�");
		char driverName[MAXNAMENUM];
		scanf_s("%s", driverName, MAXNAMENUM);
		if (modifyDriverInfo(driverName))
			printf("\n\t\t\t\t�޸ĳɹ���\n");
		else printf("\n\t\t\t\tʧ���ˡ�����ô���ء���\n");
		driverInfoChoice();
		break;
	}
	case 4: {
		displayDriverInfo();
		driverInfoChoice();
		break;
	}
	case 5: {
		printf("\n\t\t\t\t��������Ҫ��ѯ��˾�����֣�");
		char driverName[MAXNAMENUM];
		scanf_s("%s", driverName, MAXNAMENUM);
		searchByDriverName(driverName);
		driverInfoChoice();
		break;
	}
	case 0: mainChoice(); break; //������һ��
	}
}

void routeInfoChoice(void) {
	printf("\n\t\t\t\t1:  ���·����Ϣ\n");
	printf("\t\t\t\t2:  ɾ��·����Ϣ\n");
	printf("\t\t\t\t3:  �޸�·����Ϣ\n");
	printf("\t\t\t\t4:  չʾ·����Ϣ\n");
	printf("\t\t\t\t5:  ��ѯ·����Ϣ\n");
	printf("\t\t\t\t0:  ������һ���˵�\n");
	printf("\n\t\t\t\t���������ѡ��");
	scanf_s("%d", &bus_InfoChoice);
	switch (bus_InfoChoice)
	{
	default: {
		routeInfoChoice();
		break;
	}
	case 1: {
		addRouteInfo();
		routeInfoChoice();
		break;
	}
	case 2: {
		printf("\n\t\t\t\t��������Ҫɾ����·������");
		int routeName;
		scanf_s("%d", &routeName);
		if (deleteRouteInfo(routeName))
			printf("\n\t\t\t\tɾ���ɹ���\n");
		else printf("\n\t\t\t\tʧ���ˡ�����ô���ء���\n");
		routeInfoChoice();
		break;
	}
	case 3: {
		printf("\n\t\t\t\t��������Ҫ�޸ĵ�·������");
		int routeName;
		scanf_s("%d", &routeName);
		if (modifyRouteInfo(routeName))
			printf("\n\t\t\t\t�޸ĳɹ���\n");
		else printf("\n\t\t\t\tʧ���ˡ�����ô���ء���\n");
		routeInfoChoice();
		break;
	}
	case 4:{
		displayRouteInfo();
		routeInfoChoice();
		break;
	}
	case 5: {
		printf("\n\t\t\t\t������Ҫ��ѯ��·������");
		int routeName;
		scanf_s("%d", &routeName);
		searchByRouteName(routeName);
		routeInfoChoice();
		break;
	}
	case 0: mainChoice(); break;
	}
}