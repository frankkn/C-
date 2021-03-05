#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char * id = new char[11];
	scanf("%s",id);

	int result = 1; //預設結果為正確格式的身分證字號
	if(strlen(id) != 10){
		result = 0;
	}else if(id[0] < 'A' || id[0] > 'Z'){
		result = 0;
	}else if(id[1] != '1' && id[1] != '2'){ //第二位數需為1or2指示性別
		result = 0;
	}else {
		for(size_t i = 2; i < strlen(id); i++){ //第三位數到最後必須為數字
			if(id[i] < '0' || id[i] > '9'){
				result = 0;
				break;
			}
		}
	}

	if(result){
		char words[] = "ABCDEFGHJKLMNPQRSTUVXYWZIO";
		int index = 0;
		for(size_t i = 0; i < strlen(words); i++){ //要找第一個英文對應的index
			if(id[0] == words[i]){
				index = i;
				break;
			}
		}
		index += 10;

		char temp[3];
		//int sprintf ( char * str, const char * format, ... );
		sprintf(temp, "%d", index);//把index放到temp int轉成字串，所以原本10位數會轉成11位數

		char * newId = new char[12];
		strcpy(newId,temp);
		strcat(newId,id+1);

		int total = 0;
		total = (newId[0] - 48) * 1; // -48 是字元碼轉成數字 1 => 字元碼49
		for(int i = 1; i <= 9; i++){
			total += (newId[i] - 48) * (10 - i);
		}
		total += (newId[10] - 48) * 1;

		if(total % 10 != 0){
			result = 0;
		}
	}
	if(result){
		printf("Correct Format");
	}else{
		printf("Wrong Format");
	}
	return 0;
}




