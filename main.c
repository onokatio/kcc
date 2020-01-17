#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

void source2symbol(char *source);

int main(int argc, char *argv[]){
	char *source;
	struct stat sb;
	fstat(0, &sb);
	source = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, 0, 0);

	source2symbol(source);
}

void source2symbol(char *source){
	printf("source: %s",source);
}
