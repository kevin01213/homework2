#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000
int main(void){

	
	FILE *fptr = fopen("dataset2.txt","w");
	if(!fptr){
		fprintf(stderr,"file cannot open\n");
		exit(1);
	}

	for(int i = 0;i < MAX;i++){
		fprintf(fptr,"%d\n",i);
	}


	return 0;
}
