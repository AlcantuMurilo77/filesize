#include <stdio.h>

/* TODO: Add proper documentation for this utility */

int main(int argc, char *argv[]) {
	// Check for correct number of arguments
	if (argc != 2) {
		printf("Usage: %s filename\n", argv[0]);
		return 1;
	}

	// Open the file in binary read mode
	FILE *file = fopen(argv[1], "rb");
	if (!file) {
		perror("Error opening file.");
		return 1;
	}

	// Seek to the end of the file
	fseek(file, 0, SEEK_END);

	// Get the current byte offset (i.e., file size)
	long size = ftell(file);

	// Close the file as we no longer need it
	fclose(file);

	// Check if ftell failed
	if (size == -1L) {
		perror("Error obtaining file size.");
		return 1;
	}

	// Print the size in bytes
	printf("File size: %ld bytes\n", size);

	return 0;
}

/*
------------------------------------------
Notes & Future Goals for This Project
------------------------------------------

- [ ] Add support for human-readable sizes (KB, MB, GB).
- [ ] Handle large files (consider using fseeko/ftello for 64-bit support).
- [ ] Add support for directories: skip or warn if target is not a regular file.
- [ ] Implement a verbose mode (-v flag) for extra debugging/info.
- [ ] Consider error codes for different failure scenarios.
- [ ] Add unit tests or CLI tests for robustness.
- [ ] Package as a proper CLI tool with man page/help option.

This tool is meant to be a lightweight CLI utility to quickly check file sizes.
Might eventually expand to a file metadata inspector.

*/
