#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc !=2){
		printf("Command: %s filename\n", argv[0]);
		return 1;
	}

	FILE *file = fopen(argv[1], "rb");
	if (!file) {
		perror("Error opening file.");
		return 1;
	}

	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fclose(file);

	if (size == -1L) {
		perror("Error obtaining file size.");
		return 1;
	}

	printf("File size: %ld bytes\n", size);



	 return 0;
}
