#include "choice.h"

void passMenu(void) {
	printf("\t\t******************************************************************\n");
	printf("\t\t*                        ���ٹ�������ϵͳ                        *\n");
	printf("\t\t******************************************************************\n");
	printf("\t\t*                                                                *\n");
	printf("\t\t*                                                                *\n");
	printf("\t\t*                         ��ӭ�����¼��                         *\n");
	printf("\t\t*              �������ǣ� 1.�˿�   2.����Ա  ��һλ�أ�          *\n");
	printf("\t\t*                                                                *\n");
	printf("\t\t*                                                                *\n");
	printf("\t\t******************************************************************\n");
	printf("���������ѡ��:");
	int passChoice;
	scanf_s("%d", &passChoice);
	initBusInfoList();
	initDriverInfoList();
	initRouteInfoList();
	switch (passChoice)
	{
	case 1: {
		system("cls");
		readFile(1);
		readFile(3);
		passengerChoice();
		break;
	}
	case 2: {
		system("cls");
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
		system("cls");
		mainChoice();
		break;
	}
	case 1: {
		//������Ϣ
		system("cls");
		readFile(1);
		busInfoChoice();
		break;
	}
	case 2: {
		//˾����Ϣ
		system("cls");
		readFile(2);
		driverInfoChoice();
		break;
	}
	case 3: {
		//·����Ϣ
		system("cls");
		readFile(3);
		routeInfoChoice();
		break;
	}
	case 0:
	{
		exit(0);
	}
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
		system("cls");
		busInfoChoice();
		break;
	}
	case 1: {  //��Ϣ���
		system("cls");
		addBusInfo();
		printf("��ӳɹ���");
		busInfoChoice();
		break;
	}
	case 2: {  //��Ϣɾ��
		system("cls");
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
		system("cls");
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
		system("cls");
		displayBusInfo();
		busInfoChoice();
		break;
	}
	case 5: { //��ѯ��Ϣ
<<<<<<< HEAD
		system("cls");
=======
>>>>>>> f96b7377afbbc8671af6cc9b3dd1a00e2a4163fb
		printf("\n\t\t\t\t��Ҫ��ѯ���Ǽ�·�������أ�");
		int busNum;
		scanf_s("%d", &busNum);
		searchByBusNum(busNum);
		busInfoChoice();
		break;
	}
	case 0:
	{ 
		system("cls");
		mainChoice();
		break; //������һ��
	}
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
		system("cls");
		driverInfoChoice();
		break;
	}
	case 1: {
		system("cls");
		addDriverInfo();
		printf("��ӳɹ���");
		driverInfoChoice();
		break;
	}
	case 2: {
		system("cls");
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
		system("cls");
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
		system("cls");
		displayDriverInfo();
		driverInfoChoice();
		break;
	}
	case 5: {
		system("cls");
		printf("\n\t\t\t\t��������Ҫ��ѯ��˾�����֣�");
		char driverName[MAXNAMENUM];
		scanf_s("%s", driverName, MAXNAMENUM);
		searchByDriverName(driverName);
		driverInfoChoice();
		break;
	}
	case 0:
	{
		system("cls");
		mainChoice();
		break; //������һ��
	}
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
		system("cls");
		routeInfoChoice();
		break;
	}
	case 1: {
		system("cls");
		addRouteInfo();
		printf("��ӳɹ���");
		routeInfoChoice();
		break;
	}
	case 2: {
		system("cls");
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
		system("cls");
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
		system("cls");
		displayRouteInfo();
		routeInfoChoice();
		break;
	}
	case 5: {
		system("cls");
		printf("\n\t\t\t\t������Ҫ��ѯ��·������");
		int routeName;
		scanf_s("%d", &routeName);
		searchByRouteName(routeName);
		routeInfoChoice();
		break;
	}
	case 0:
	{
		system("cls");
		mainChoice(); 
		break;
	}
	}
}