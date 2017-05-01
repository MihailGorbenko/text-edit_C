#include "header.h"

//-------------------------
int get_valid_choise(void){

	int choise = 0;
	printf(" $> ");
	scanf("%d", &choise);
	while (getchar() != '\n') continue;
	while( choise > 5 || choise < 1 || choise == 0 ){
		puts("Ошибка ввода, попробуйте еще раз");
		printf(" $> ");
		scanf("%d", &choise);
		while (getchar() != '\n') continue;
	}

	return choise;
}
///---------------------
void get_text(FILE * file){
	
	char bufer[INPUT];
	puts("$> Введите текст для преобразования:::(для завершения вода дыважды нажмите [ENTER]");
	fgets(bufer, INPUT, stdin);
	while (bufer[0] != '\n' && bufer[1] != '\n'){
		fputs(bufer,file);
		fgets(bufer, INPUT, stdin);

	}

}
///---------------------
void write_session(FILE * readFrom, FILE * sesFile, bool lat, bool cyr, bool punct, bool dig){
	rewind(sesFile);
	char bufer[INPUT] ;
	///--------lat layer
	while (fgets(bufer, INPUT, readFrom) != NULL){
		if (lat){
			for (int i = 0; i < INPUT; i++){
				if ((int)bufer[i] >= 65 && (int)bufer[i] <=90 || (int)bufer[i] >= 97 && (int)bufer[i] <=122){
					bufer[i] = ' ';
				}
			}
		}
		///-------cyr layer
		if (cyr){
			for (int i = 0; i < INPUT; i++){
				if ((int)bufer[i] < 0 ){
					bufer[i] = ' ';
				}
			}
		}
		///-------punct layer
		if (punct){
			for (int i = 0; i < INPUT; i++){
				if ((int)bufer[i] >= 33 && (int)bufer[i] <48 || (int)bufer[i] >57 && (int)bufer[i] <=64){
					bufer[i] = ' ';
				}
			}
		}
		///-------dig layer
		if (dig){
			for (int i = 0; i < INPUT; i++){
				if ((int)bufer[i] >= 48 && (int)bufer[i] <=57 ){
					bufer[i] = ' ';
				}
			}
		}
		//--------
		fputs(bufer, sesFile);
	}
	
}

///---------------------
void read_file(FILE * file){
	char buffer[INPUT];
	while (fgets(buffer, INPUT, file) != NULL){
		puts(buffer);
	}
}