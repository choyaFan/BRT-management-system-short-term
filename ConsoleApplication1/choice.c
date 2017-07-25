#include "choice.h"

void passMenu(void) {
	printf("\t\t******************************************************************\n");
	printf("\t\t*                        快速公交管理系统                        *\n");
	printf("\t\t******************************************************************\n");
	printf("\t\t*                                                                *\n");
	printf("\t\t*                                                                *\n");
	printf("\t\t*                         欢迎！请登录！                         *\n");
	printf("\t\t*              请问您是： 1.乘客   2.管理员  哪一位呢？          *\n");
	printf("\t\t*                                                                *\n");
	printf("\t\t*                                                                *\n");
	printf("\t\t******************************************************************\n");
	printf("请输入你的选择:");
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

//主菜单！
void mainChoice(void) {
	printf("\n\t\t\t\t1:  车辆信息管理\n");
	printf("\t\t\t\t2:  司机信息管理\n");
	printf("\t\t\t\t3:  路线信息管理\n");
	printf("\t\t\t\t0:  退出程序\n");
	printf("\n\t\t\t\t请输入你的选择:");
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
		//车辆信息
		system("cls");
		readFile(1);
		busInfoChoice();
		break;
	}
	case 2: {
		//司机信息
		system("cls");
		readFile(2);
		driverInfoChoice();
		break;
	}
	case 3: {
		//路线信息
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
	printf("\n\t\t\t\t1:  添加车辆信息\n");
	printf("\t\t\t\t2:  删除车辆信息\n");
	printf("\t\t\t\t3:  修改车辆信息\n");
	printf("\t\t\t\t4:  展示车辆信息\n");
	printf("\t\t\t\t5:  查询车辆信息\n");
	printf("\t\t\t\t0:  返回上一级菜单\n");
	printf("\n\t\t\t\t请输入你的选择：");
	scanf_s("%d", &bus_InfoChoice);
	switch (bus_InfoChoice)
	{
	default:
	{
		system("cls");
		busInfoChoice();
		break;
	}
	case 1: {  //信息添加
		system("cls");
		addBusInfo();
		printf("添加成功！");
		busInfoChoice();
		break;
	}
	case 2: {  //信息删除
		system("cls");
		printf("\n\t\t\t\t请输入需要删除的车辆车牌号：");
		char plateNum[MAXPLATENUM];
		scanf_s("%s", plateNum, MAXPLATENUM);
		if(deleteBusInfo(plateNum))
		printf("\n\t\t\t\t删除成功！\n");
		else printf("\n\t\t\t\t失败了……怎么会呢……\n");
		busInfoChoice();
		break;
	}
	case 3: { //信息修改
		system("cls");
		printf("\n\t\t\t\t请输入需要修改的车辆车牌号：");
		char plateNum[MAXPLATENUM];
		scanf_s("%s", plateNum, MAXPLATENUM);
		if(modifyBusInfo(plateNum))
		printf("\n\t\t\t\t修改成功！\n");
		else printf("\n\t\t\t\t失败了……怎么会呢……\n");
		busInfoChoice();
		break;
	}
	case 4: { //信息展示
		system("cls");
		displayBusInfo();
		busInfoChoice();
		break;
	}
	case 5: { //查询信息
<<<<<<< HEAD
		system("cls");
=======
>>>>>>> f96b7377afbbc8671af6cc9b3dd1a00e2a4163fb
		printf("\n\t\t\t\t你要查询的是几路公交车呢：");
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
		break; //返回上一级
	}
	}
}

void driverInfoChoice(void) {
	printf("\n\t\t\t\t1:  添加司机信息\n");
	printf("\t\t\t\t2:  删除司机信息\n");
	printf("\t\t\t\t3:  修改司机信息\n");
	printf("\t\t\t\t4:  展示司机信息\n");
	printf("\t\t\t\t5:  查询司机信息\n");
	printf("\t\t\t\t0:  返回上一级菜单\n");
	printf("\n\t\t\t\t请输入你的选择：");
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
		printf("添加成功！");
		driverInfoChoice();
		break;
	}
	case 2: {
		system("cls");
		printf("\n\t\t\t\t请输入需要删除的司机名字：");
		char driverName[MAXNAMENUM];
		scanf_s("%s", driverName, MAXNAMENUM);
		if(deleteDriverInfo(driverName))
			printf("\n\t\t\t\t删除成功！\n");
		else printf("\n\t\t\t\t失败了……怎么会呢……\n");
		driverInfoChoice();
		break;
	}
	case 3: {
		system("cls");
		printf("\n\t\t\t\t请输入需要修改的司机名字：");
		char driverName[MAXNAMENUM];
		scanf_s("%s", driverName, MAXNAMENUM);
		if (modifyDriverInfo(driverName))
			printf("\n\t\t\t\t修改成功！\n");
		else printf("\n\t\t\t\t失败了……怎么会呢……\n");
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
		printf("\n\t\t\t\t请输入需要查询的司机名字：");
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
		break; //返回上一级
	}
	}
}

void routeInfoChoice(void) {
	printf("\n\t\t\t\t1:  添加路线信息\n");
	printf("\t\t\t\t2:  删除路线信息\n");
	printf("\t\t\t\t3:  修改路线信息\n");
	printf("\t\t\t\t4:  展示路线信息\n");
	printf("\t\t\t\t5:  查询路线信息\n");
	printf("\t\t\t\t0:  返回上一级菜单\n");
	printf("\n\t\t\t\t请输入你的选择：");
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
		printf("添加成功！");
		routeInfoChoice();
		break;
	}
	case 2: {
		system("cls");
		printf("\n\t\t\t\t请输入需要删除的路线名：");
		int routeName;
		scanf_s("%d", &routeName);
		if (deleteRouteInfo(routeName))
			printf("\n\t\t\t\t删除成功！\n");
		else printf("\n\t\t\t\t失败了……怎么会呢……\n");
		routeInfoChoice();
		break;
	}
	case 3: {
		system("cls");
		printf("\n\t\t\t\t请输入需要修改的路线名：");
		int routeName;
		scanf_s("%d", &routeName);
		if (modifyRouteInfo(routeName))
			printf("\n\t\t\t\t修改成功！\n");
		else printf("\n\t\t\t\t失败了……怎么会呢……\n");
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
		printf("\n\t\t\t\t请输入要查询的路线名：");
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