#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char *argv[]){
	char source[200];
	char line[100];
	char *str;
	struct stat sb;
	fstat(0, &sb);
	str = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, 0, 0);
	printf("source: %s",str);
}
