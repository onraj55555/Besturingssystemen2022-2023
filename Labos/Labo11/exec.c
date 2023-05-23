#include <unistd.h>
#include <sys/wait.h>

// Gebruik om andere programmas uit te voeren buiten hoofdprogramma

int main() {
	char *args[]={"ps", "-ef", (char *)0}; // AFSLUITEN MET 0 ZOALS BIJ CSTRING
	execvp("ps", args); // VANAF HIER WORDT NIETS VERDER MEER GEDAAN, DUS return 0 WORDT NIET UITGEVOED
	//execlp("ps", "ps", "-ef", (char*)0);
	return 0;
}

