#include "type.h"
#include "hash.h"

int main(int argc,char **argv){
	
	
	int a[MAX] = {0};
	struct link_list *head = NULL;
	struct Tree_node *root = NULL;
	struct hash_node **htab = NULL;
	 
	int build_data = -1; // -1:nope 0: 1e4 1: 1e5 2: 1e6
	int querry_data = -1; //-1:nope 0: 1e3 1: 1e4 2: 1e5
	
	int flag_ll = 0;
	int flag_array = 0;
	int flag_bst = 0;
	int flag_bs = 0;
	int flag_hash = 0;
	
	if(strcmp(argv[1],"-d") == 0){
		 
		 if(strcmp(argv[2],"1e4") == 0){
			build_data = 0;
		 }
		 if(strcmp(argv[2], "1e5") == 0){
			build_data = 1;
		 }
		 if(strcmp(argv[2],"1e6") == 0){
			build_data = 2;
		 }
		
	}
	
	else{
		usage();
	}

	
	if(strcmp(argv[3],"-q") == 0){
		
		if(strcmp(argv[4],"1e3") == 0){
			querry_data = 0;
		}
		if(strcmp(argv[4],"1e4") == 0){
			querry_data = 1;
		}
		if(strcmp(argv[4],"1e5") == 0){
			querry_data = 2;
		}
		
	}
	
	else{
		usage();
	}
	
	int cnt = 5;
	
	while(cnt < argc){
		
		if(strcmp(argv[cnt],"-arr") == 0){
			flag_array = 1;
			cnt++;
			continue;
		}
		if(strcmp(argv[cnt],"-ll") == 0){
			flag_ll = 1;
			cnt++;
			continue;
		}
		if(strcmp(argv[cnt],"-bst") == 0){
			flag_bst = 1;
			cnt++;
			continue;
		}
		if(strcmp(argv[cnt],"-bs") == 0){
			flag_bs = 1;
			cnt++;
			continue;
		}
		if(strcmp(argv[cnt],"-hash") == 0){
			flag_hash = 1;
			cnt++;
			continue;
		}
		else{
			usage();
			break;
		}
	}
	if(flag_array){
		build_array(a,build_data);
		querry_array(a,querry_data);
		printf("\n");
	}
	if(flag_bs){
		build_bs_array(a,build_data);
		querry_bs(a,querry_data);
		printf("\n");
	}
	if(flag_ll){
		head = build_link_list(head,build_data);
		querry_link_list(head,querry_data);
		printf("\n");
	}
	if(flag_bst){
		
		root = build_bst(root,build_data);
		querry_bst(root,querry_data);
		printf("\n");
	}
	if(flag_hash){
		htab = build_hash(htab,build_data);
		querry_hash(htab,querry_data);
		printf("\n");
		
	}

	return 0;
}
