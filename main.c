#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>

void source2symbol(char *source);

int main(int argc, char *argv[]){
	char *source;
	struct stat sb;
	fstat(0, &sb);
	source = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, 0, 0);

	source2symbol(source);
}

typedef struct {
	int type;
	char typename[20];
} SYMBOL;

void source2symbol(char *source){
	SYMBOL *symbol_list = (SYMBOL *)malloc(sizeof(SYMBOL) * 1000);

	for(int index = 0; source[index] != '\0'; index++){
		if(source[index] == '\n'){
			continue;
		} else if(source[index] == '+'){
			printf("SYMBOL_PLUS\n");
		} else if(source[index] == '-'){
			printf("SYMBOL_MINUS\n");
		} else if(source[index] >= '0' && source[index] <= '9'){
			while(source[index] >= '0' && source[index] <= '9'){
				printf("SYMBOL_NUM\n");
				index++;
			}
			index--;
		}
	}
}
