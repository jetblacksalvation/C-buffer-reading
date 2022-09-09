#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//DATA segment
enum MyEnum
{
	CONDITIONAL_TYPE = 0,
	VARIABLE_TYPE    = 1 , 
	OPERATOR_TYPE    = 2,//posibly add more enum types 
	IDENTIFIER_TYPE  = 3,
	SEPERATOR_TYPE_START   = 4, //this one will be used for function calls and code segments 
	SEPERATOR_TYPE_END= 5 

};
//int max is maximum length of arrays
char *condit[] = { "if", "else", "for", "while"};//condit type
int con_int_max = 4;
char *types[] = {"int", "bool", "float" };//variable type
int type_int_max = 3;
char oper[] = { "+-/*^%=?" };//operations that will essentially be a function call
int oper_int_max = 8;
char seperator[] = { ",.{}[]()<>|\\" };
int seperator_int_max = 12;
char buffer[255];//will read 255 characters per line
char word_buff[124];
//FUNCTION segment

//these functions will iterate through all types, if none match given string, return 0

int con_type_ret(char* str[]) {//returns int type of 1 -- call when you want to check if str is conditional type

	return 1;
};


//EXCECUTION segment  ----- all of the above functions and data will be used in this "main" function
//  memset(members, 0, sizeof members);

void read_file(FILE* f_ptr, char * str) {
	fopen_s(&f_ptr, str, "r");
	if (f_ptr == NULL) {
		printf("error!");
		exit(0);//close program because error
	}

	while (fgets(buffer, sizeof(buffer), f_ptr)) {
		/* note that fgets don't strip the terminating \n, checking its
		   presence would allow to handle lines longer that sizeof(line) */
		printf("%s", buffer);
	}


	fclose(f_ptr);//close the file
};


