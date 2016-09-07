#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	/* check arguments */
	if (argc != 3) {
		fprintf(stderr, "USAGE:\t\t%s, INPUT OUTPUT\n", argv[0]);
		return 1;
	}

	/* input */
	FILE *in;
	in = fopen(argv[1], "r");
	if (!in) {
		fprintf(stderr, "ERROR:\t\tunable to read input-file\n");
		return 1;
	}

	/* output */
	FILE *out;
	out = fopen(argv[2], "w");
	if (!out) {
		fprintf(stderr, "ERROR:\t\tunable to read output-file\n");
		fclose(in);
		return 1;
	}

	/* name of the object */
	char *obj = strdup(argv[1]);
	unsigned int i;
	for (i = 0; i < strlen(obj); ++i) {
		if (!isalnum(obj[i])) obj[i] = '_';
	}
	/* convert and write characters */
	unsigned int c;
	fprintf(out, "char %s[] = {\n", obj);
	while ((c = fgetc(in)) != EOF) {
		fprintf(out, "'\\x%X', ", (unsigned int) c);
	}
	fprintf(out, "'\\0'");
	fprintf(out, "};\n");

	/* free resources */
	free(obj);
	fclose(out);
	fclose(in);

	return 0;
}
