#include "password.h"
void checkPass(void) {
	char password[MAXPASSLEN + 1] = "12345", input_passwd[MAXPASSLEN + 1] = "";
	pswd_check_counter = 3; //密码检查计数器初始化
	for (pswd_input_counter = 0; pswd_input_counter < 3; pswd_input_counter++) {
		pswd_input_check_counter = 0;  //初始化or重置密码位数检查器

		printf("\t\t\t\t请输入密码，您还有%d次机会哦：", pswd_check_counter--);
		while ((pswd_char_tmp = _getch()) != '\r') {        //传入临时变量
			if (pswd_input_check_counter < MAXPASSLEN) {
				input_passwd[pswd_input_check_counter++] = pswd_char_tmp;  //传进输入的密码里
				printf("*"); //打印星号
			}
		}
		input_passwd[pswd_input_check_counter] = '\0';  //添加结束符
		printf("\n");
		
		if (strcmp(input_passwd, password) == 0) {
			//显示管理员主菜单 && 还没写！
			printf("成功！\n");
			break;
		}
		else if (pswd_check_counter > 0) {
			printf("\t\t\t\t密码好像输错了哦，再试一次吧！\n");
			//不需要重置密码位数检查器了
			continue;
		}
		else if (pswd_input_counter == 2) {
			printf("\t\t\t\t没有机会了，拜拜~\n");
			exit(0);
		}
	}
}