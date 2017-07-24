#include "choice.h"

void passMenu(void) {
	printf("\n\t\t\t\t欢迎来到快速公交管理系统\n");
	printf("\n\t\t\t\t请问您是： 1.乘客   2.管理员  哪一位呢？\n");
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
		mainChoice();
		break;
	}
	case 1: {
		//车辆信息
		readFile(1);
		busInfoChoice();
		break;
	}
	case 2: {
		//司机信息
		readFile(2);
		driverInfoChoice();
		break;
	}
	case 3: {
		//路线信息
		readFile(3);
		routeInfoChoice();
		break;
	}
	case 0: exit(0);
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
		busInfoChoice();
		break;
	}
	case 1: {  //信息添加
		addBusInfo();
		busInfoChoice();
		break;
	}
	case 2: {  //信息删除
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
		displayBusInfo();
		busInfoChoice();
		break;
	}
	case 5: { //查询信息
		printf("\n\t\t\t\t请输入你要查询的车辆车牌号：");
		char plateNum[MAXPLATENUM];
		scanf_s("%s", plateNum, MAXPLATENUM);
		searchByPlateNum(plateNum);
		busInfoChoice();
		break;
	}
	case 0: mainChoice(); break; //返回上一级
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
		driverInfoChoice();
		break;
	}
	case 1: {
		addDriverInfo();
		driverInfoChoice();
		break;
	}
	case 2: {
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
		displayDriverInfo();
		driverInfoChoice();
		break;
	}
	case 5: {
		printf("\n\t\t\t\t请输入需要查询的司机名字：");
		char driverName[MAXNAMENUM];
		scanf_s("%s", driverName, MAXNAMENUM);
		searchByDriverName(driverName);
		driverInfoChoice();
		break;
	}
	case 0: mainChoice(); break; //返回上一级
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
		routeInfoChoice();
		break;
	}
	case 1: {
		addRouteInfo();
		routeInfoChoice();
		break;
	}
	case 2: {
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
		displayRouteInfo();
		routeInfoChoice();
		break;
	}
	case 5: {
		printf("\n\t\t\t\t请输入要查询的路线名：");
		int routeName;
		scanf_s("%d", &routeName);
		searchByRouteName(routeName);
		routeInfoChoice();
		break;
	}
	case 0: mainChoice(); break;
	}
}