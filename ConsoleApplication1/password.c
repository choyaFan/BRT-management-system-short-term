#include "password.h"
void checkPass(void) {
	char password[MAXPASSLEN + 1] = "12345", input_passwd[MAXPASSLEN + 1] = "";
	pswd_check_counter = 3; //�������������ʼ��
	for (pswd_input_counter = 0; pswd_input_counter < 3; pswd_input_counter++) {
		pswd_input_check_counter = 0;  //��ʼ��or��������λ�������

		printf("\t\t\t\t���������룬������%d�λ���Ŷ��", pswd_check_counter--);
		while ((pswd_char_tmp = _getch()) != '\r') {        //������ʱ����
			if (pswd_input_check_counter < MAXPASSLEN) {
				input_passwd[pswd_input_check_counter++] = pswd_char_tmp;  //���������������
				printf("*"); //��ӡ�Ǻ�
			}
		}
		input_passwd[pswd_input_check_counter] = '\0';  //��ӽ�����
		printf("\n");
		
		if (strcmp(input_passwd, password) == 0) {
			//��ʾ����Ա���˵� && ��ûд��
			system("cls");
			printf("�ɹ���\n");
			break;
		}
		else if (pswd_check_counter > 0) { //������л���
			system("cls");
			printf("\t\t\t\t������������Ŷ������һ�ΰɣ�\n");
			//����Ҫ��������λ���������
			continue;
		}
		else if (pswd_input_counter == 2) {//û�л����ˣ��˳�ϵͳ
			system("cls");
			printf("\t\t\t\tû�л����ˣ��ݰ�~\n");
			exit(0);
		}
	}
}