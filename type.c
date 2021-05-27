#include "type.h"


void usage(void){
	fprintf(stderr,"./a.out -d 1e4 -q 1e3 -bst -arr\n");
}

int get_data_number(int info){
	int number = -1;
	switch(info){
                  case 0: 
                          number = 10000;
                          break;
                  case 1: 
                          number = 100000;
                          break;
                  case 2: 
                          number = 1000000;
                          break;
                  default:
                          usage();
                          break;
                  } 
		return number;
}

struct link_list *init_list(int number){

	struct link_list *temp = malloc(sizeof(struct link_list));
	temp->number = number;
	temp->next = NULL;
	return temp;
}
struct link_list *insert_list(struct link_list *head,int number){
	
	FILE *fptr = fopen("dataset1.txt","r");
	if(!fptr){
		fprintf(stderr,"file open failed");
	}

	struct link_list *current = head;
	int cnt = 0;
	int tmp;
	struct link_list *temp;
	
	while(fscanf(fptr,"%d",&tmp)){
		
		if(head == NULL){
			temp = init_list(tmp);
			head = temp;
			current = head;
			cnt++;
			continue;
		}
		else{
			temp = init_list(tmp);
			current->next = temp;
			current = current->next;
			cnt++;
		}
		if(cnt >= number)break;
	}
	return head;
			
}
void build_array(int *a,int info){
	
	int number = get_data_number(info);
	
	int cnt = 0;
	FILE *fptr = fopen("dataset1.txt","r");
	if(!fptr){
		fprintf(stderr,"file open failed");
	}
	struct timeval start;
   	struct timeval end;
    	unsigned long diff;

    	gettimeofday(&start,NULL);
    	while(cnt < number){
		if(fscanf(fptr,"%d",&a[cnt++]));
	}
    	gettimeofday(&end,NULL);
	diff = MAX * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("arr\n");
	printf("building time: %ld sec\n",diff);
}

void querry_array(int *a,int info){
	
	FILE *fptr = fopen("dataset2.txt","r");
	if(!fptr){
		fprintf(stderr,"file dataset2 cannot open\n");
	}
	int number;
	if(info == 0)number = 1000;
	if(info == 1)number = 10000;
	if(info == 2)number = 100000;
	int b[MAX];
	int cnt = 0;

						
	struct timeval start;
	struct timeval end;
	unsigned long diff;

	gettimeofday(&start,NULL);
	
        while(fscanf(fptr,"%d",&b[cnt])){
		if(cnt == number)break;
		else{
			for(int i = 0;i < MAX;i++){
				if(a[i] == b[cnt])break;
			}
		}
		cnt++;
	}
	gettimeofday(&end,NULL);
	diff = MAX *(end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("querry time: %ld sec\n",diff);
}
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selection_sort(int *a,int number){
	
	int max;
	int idx;
	for(int i = 0;i < number;i++){
		
		max = 0;
		idx = 0;
		for(int j = i;j < number;j++){
			
			if(a[j] > max){
				max = a[j];
				idx = j;
			}
		swap(&a[i],&a[idx]);
		}
	}
}

void build_bs_array(int *a,int info){
	int number = get_data_number(info);
	
	FILE *fptr = fopen("dataset1.txt","r");
	if(!fptr){
		fprintf(stderr,"file cannot open");
		exit(1);
	}
	struct timeval start;
	struct timeval end;
	unsigned long diff;
	int cnt = 0;
	gettimeofday(&start,NULL);
	while(cnt < number){
		if(fscanf(fptr,"%d",&a[cnt++]));
	}
	
	selection_sort(a,number);
	gettimeofday(&end,NULL);
	diff = MAX * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("bs\n");
	printf("building time: %ld sec\n",diff);
	fclose(fptr);
}
void binary_search(int *a,int n,int number){
	
	int start = 0;
	int end = number;
	int mid = (start + end)/2;
	for(int i = 0;i < (number/2);i++){
		if(a[mid] == n)break;
		if(a[mid] < n){
			start = mid + 1;
			mid = (start + end)/2;
		}
		if(a[mid] > n){
			end = mid - 1;
			mid = (start + end)/2;
		}
	}	
}

void querry_bs(int *a,int info){
	
	int b[MAX];
	struct timeval start;
	struct timeval end;
	unsigned long diff;
	int cnt = 0;
	int number;
	if(info == 0)number = 1000;
	if(info == 1)number = 10000;
	if(info == 2)number = 100000;
	FILE *fptr = fopen("dataset2.txt","w");
	
	gettimeofday(&start,NULL);
	
	while(fscanf(fptr,"%d",&b[cnt])){
		if(cnt == number)break;
		binary_search(a,b[cnt],number);
	}
	gettimeofday(&end,NULL);

	diff = MAX * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("bs\n");
	printf("querry time: %ld sec\n",diff);
	fclose(fptr);
}
struct link_list *build_link_list(struct link_list *head,int info){
	
	
	int number = get_data_number(info);
		
	struct timeval start;
	struct timeval end;
	unsigned long diff;

	gettimeofday(&start,NULL);
	head = insert_list(head,number);
	gettimeofday(&end,NULL);
	diff = MAX * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("ll\n");
        printf("building time: %ld sec\n",diff);
	return head;
}
void querry_link_list(struct link_list *head,int info){
	
	int number;
	FILE *fptr = fopen("dataset2.txt","r");
	if(!fptr){
		fprintf(stderr,"file dataset2 cannot open!\n");
		exit(1);
	}
	if(info == 0)number =1000;
	if(info == 1)number =10000;
	if(info == 2)number =100000;
	struct link_list *cur;
	int cnt = 0;
	int b[MAX];
	struct timeval start;
	struct timeval end;
	unsigned long diff;
	
	gettimeofday(&start,NULL);
	while(fscanf(fptr,"%d",&b[cnt])){
	     cur = head;
	     while(cur->number != b[cnt] && cur ->next == NULL){
	     	cur = cur->next;
		}
	     cnt++;	
	     if(cnt == number)break;
	}
	gettimeofday(&end,NULL);

	diff = MAX * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("querry time: %ld sec\n",diff);
	fclose(fptr);
}

struct Tree_node *init(int number){
	
	struct Tree_node *temp = malloc(sizeof(struct Tree_node));
	temp->right = NULL;
	temp->left = NULL;
	temp->number = number;
	return temp;
}
struct Tree_node *insert_bst(struct Tree_node *root,int number){
	
	FILE *fptr = fopen("dataset1.txt","r");
	if(!fptr){
		fprintf(stderr,"file cannot open");
	}

	int n;
	int count = 0;
	while(fscanf(fptr,"%d",&n)){
		if(count == number)break;
		
		struct Tree_node *temp = init(n);

		if(root == NULL){
			root = temp;
		}
		else{
			struct Tree_node *current = root;
			struct Tree_node *prev = NULL;
			while(1){
				prev = current;

				if(current->number > n){
					current = current->right;
					if(current == NULL){
						prev->right = temp;
						break;
					}
				}
				else if(current->number < n){
					current = current->left;
					if(current == NULL){
						prev->left = temp;
						break;
					}
				}
				else if(current->number == n){
					printf("have repeated number!\n");
					number++;
					break;
				}
			}
			
		}
		count++;
	}
	return root;
}
struct Tree_node *build_bst(struct Tree_node *root,int info){

	
	int number = get_data_number(info);

	struct timeval start;
	struct timeval end;
	unsigned long diff;
	gettimeofday(&start,NULL);

	root = insert_bst(root,number);
	gettimeofday(&end,NULL);
	diff = MAX * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("bst\n");
	printf("building time: %ld sec\n",diff);
	return root;
}
void querry_bst(struct Tree_node *root,int info){
	
	int number;
	if(info == 0)number = 1000;
	if(info == 1)number = 10000;
	if(info == 2)number = 100000;

	FILE *fptr = fopen("dataset2.txt","r");
	if(!fptr){
		fprintf(stderr,"file dataset2.txt cannot open\b");
	}

	int cnt = 0;
	int b[MAX];
	struct timeval start;
	struct timeval end;
	unsigned long diff;

	gettimeofday(&start,NULL);
	while(fscanf(fptr,"%d",&b[cnt])){
		
		search_bst(root,b[cnt]);
		cnt++;
		if(cnt >= number)break;
	
	}
	gettimeofday(&end,NULL);	
	diff = MAX * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("querry time: %ld sec\n",diff);
}

void search_bst(struct Tree_node *root,int n){
	
	struct Tree_node *cuv = root;
	if(cuv->number == n)return;
	else{
		while(cuv != NULL){
			if(cuv->number > n){
				cuv = cuv->right;
			}
			if(cuv->number < n){
				cuv = cuv->left;
			}
		}
	}
}
