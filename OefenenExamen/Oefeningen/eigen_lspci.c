#include <stdio.h>
#include <sys/io.h>
#include <errno.h>

int printbin(int getal) {
	int filter = 1<<31;
	for(int i = 0; i < 32; i++) {
		printf("%u", getal&filter);
	}
	printf("\n");
}

int main() {
	if(!ioperm(0xcf8, 0, 1)) {
		perror("Failed to give privilege");
		return 0;
	}
	int getal = 0;
	for(int busnummer = 0; busnummer < 256; busnummer++) {
		for(int devicenummer = 0; devicenummer < 32; devicenummer++) {
			for(int functienummer = 0; functienummer < 8; functienummer++) {
				getal = (1<<31)|(busnummer<<16)|(devicenummer<<11)|(functienummer<<8);
				outl(getal, 0xcf8);
				int antwoord = inl(0xcfc);
				if(antwoord != 0xffffffff) {
					int deviceID = antwoord>>16;
					int vendorID = antwoord&0xffff;
					printf("%d:%d\n", deviceID, vendorID);
				}
			}
		}
	}
	return 0;
}

