#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	union{
		char IP[15];
		unsigned int oct[4];
		unsigned int hex[4];
	} IPAddress;
	unsigned int tempOct[4];
	
	fputs("\nEnter IP Address: ", stdout);
	fgets(IPAddress.IP, 15, stdin);
	IPAddress.IP[strcspn(IPAddress.IP, "\n")] = '\0';
	
	sscanf(IPAddress.IP, "%i.%i.%i.%i", &tempOct[0], &tempOct[1], &tempOct[2], &tempOct[3]);
	for(int i=0; i<4; i++) IPAddress.oct[i] = tempOct[i];
	
	printf("\n\nThe IP Address in octet form: %d.%d.%d.%d", IPAddress.oct[0], IPAddress.oct[1], IPAddress.oct[2], IPAddress.oct[3]);
	printf("\nThe IP Address in hexadecimal form: %X.%X.%X.%X", IPAddress.oct[0], IPAddress.oct[1], IPAddress.oct[2], IPAddress.oct[3]);
}