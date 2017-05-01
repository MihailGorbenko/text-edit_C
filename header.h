#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <clocale>
#define INPUT 100
#define MFILE "Input.txt"
#define SESSION "Session.txt"

//---------------
int get_valid_choise(void);
void get_text(FILE * file);
void write_session(FILE * readFrom, FILE * sesFile, bool lat, bool cyr, bool punct, bool dig);
void read_file(FILE * file);