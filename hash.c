#include "hash.h"



void link_find(struct hash_node *ptr,int key){
	struct hash_node *temp = ptr;
	while(temp->next != NULL && temp->number != key)temp = temp->next;
}
void querry_hash(struct hash_node **htab,int info){
	
	unsigned int hv;
	struct hash_node *ptr;
	struct timeval start;
	struct timeval end;
	unsigned long diff;
	int maxHash;
	if(info == 0)maxHash = 1000;
	if(info == 1)maxHash = 10000;
	if(info == 2)maxHash = 100000;
	FILE *fptr = fopen("dataset2.txt","r");
	int cnt = 0;
	int number;
	if(!fptr){
		fprintf(stderr,"file cannot open!\n");
		exit(1);
	}
	gettimeofday(&start,NULL);
	while(fscanf(fptr,"%d",&number)){
		if(cnt >= maxHash)break;
		hv = hash65(number) % maxHash;
		ptr = htab[hv];
		link_find(ptr,number);
		cnt++;
	}
	gettimeofday(&end,NULL);
	diff = 1000000 *(end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("querry time: %ld sec\n",diff);

}
struct hash_node **build_hash(struct hash_node **htab,int info){
	int number;
	switch(info){
		case 0:
			number = 10000;
			break;
		case 1:
			number = 100000;
			break;
		case 2:
			number = 100000;
			break;
	}
	
	struct timeval start;
	struct timeval end;
	unsigned long diff;
	FILE *fptr = fopen("dataset1.txt","r");
	if(!fptr){
		fprintf(stderr,"file cannot open!\n");
		exit(1);
	}
	int cnt = 0;
	int temp;
	gettimeofday(&start,NULL);
	htab = hash_init(htab,number);
	while(fscanf(fptr,"%d",&temp)){
		if(cnt >= number)break;
		htab = hash_insert(htab,number,temp);
		cnt++;
	}
	gettimeofday(&end,NULL);
	
	diff = 1000000 *(end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("hash\n");
	printf("building time: %ld sec\n",diff);

}
struct hash_node **hash_init(struct hash_node **htab,int maxHash){
	
	htab = malloc(sizeof(struct hash_node *) * maxHash);
	for(int i = 0;i < maxHash;i++){
		htab[i] = NULL;
	}
	return htab;
}

struct hash_node *node_insert(struct hash_node *link,int number){
 
          struct hash_node *temp;
          temp = malloc(sizeof(struct hash_node));
          temp->number = number;
          temp->next = link;
          return temp;
 
  }

struct hash_node **hash_insert(struct hash_node **htab,int maxHash,int key){

	unsigned int hv;
	struct hash_node *ptr;
	hv = hash65(key) % maxHash;
	ptr = htab[hv];
	htab[hv] = node_insert(ptr,key);
	return htab;
}

unsigned int hash65(int number){
	
	unsigned int hv;
	int a;
	while(number != 0){
		a = number % 10;
		number /= 10;
		hv = hv * 65 + a;
	}
	return hv;

}



