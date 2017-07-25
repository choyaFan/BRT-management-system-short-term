#pragma once
#ifndef PASSWORD_H
#define PASSWORD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPASSLEN 15

void checkPass(void);

int pswd_check_counter;
int pswd_input_counter;
char pswd_char_tmp;
int pswd_input_check_counter;

#endif // !PASSWORD_H
