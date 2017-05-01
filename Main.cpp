#include "header.h"

int main(){
	//---session flags---
	bool lat_symb_layer = false;
	bool cyr_symb_layer = false;
	bool punct_symb_layer = false;
	bool digit_layer = false;
	///----------
	///-----setup
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int action = 0;
	FILE * mFile, *session_file;
	mFile = fopen(MFILE, "w+");
	session_file = fopen(SESSION, "w+");
	if (mFile == NULL){
		puts("Error,can't open file!");
		exit(1);
	}
	if (session_file == NULL)
	{
		puts("Error,can't open file!");
		exit(1);
	}
	
		//--------------
		puts("          <<< ��������� �� �������� �������� ������ >>>");
		
		//--------------
		get_text(mFile);
		
		
		
		while(action != 5){
			puts(" $> �������� ������� ��� ����������(������� ��������������� �����):");
			puts("             (1)-������� ���������� ��������;       (2)-������� ��������; ");
			puts("             (3)-������� ����������;               (4)-�����;");
			puts("             (5)-�����;");
		action = get_valid_choise();
	
		switch (action){

		case 1:
		{
			if (lat_symb_layer == false){
				lat_symb_layer = true;
			}
			else{
				lat_symb_layer = false;
			}
			rewind(mFile);
				write_session(mFile,session_file, lat_symb_layer, cyr_symb_layer, punct_symb_layer, digit_layer);
				rewind(session_file);
				read_file(session_file);
			
			break;
		}
		case 2:
		{
			if (cyr_symb_layer == false){
				cyr_symb_layer = true;
			}
			else{
				cyr_symb_layer = false;
			}
			rewind(mFile);
			write_session(mFile, session_file, lat_symb_layer, cyr_symb_layer, punct_symb_layer, digit_layer);
			rewind(session_file);
			read_file(session_file);
			break;
		}
		case 3:
		{

			if (punct_symb_layer == false){
				punct_symb_layer = true;
			}
			else{
				punct_symb_layer = false;
			}
			rewind(mFile);
				write_session(mFile, session_file, lat_symb_layer, cyr_symb_layer, punct_symb_layer, digit_layer);
				rewind(session_file);
				read_file(session_file);
			break;
		}
		case 4:
		{
			if (digit_layer == false){
				digit_layer = true;
			}
			else{
				digit_layer = false;
			}
			rewind(mFile);
			write_session(mFile, session_file, lat_symb_layer, cyr_symb_layer, punct_symb_layer, digit_layer);
			rewind(session_file);
			read_file(session_file);
			break;
		}
		default:{
			puts("Goodbye!");
			break;
		}
		}

	} 
	if(fclose(mFile) != 0)puts("Can't close file");
	if (fclose(session_file) != 0)puts("Can't close file");
	return 0;
}
