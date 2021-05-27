#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX 1000000
struct link_list{
	
	int number;
	struct link_list *next;
};
struct Tree_node{
	
	struct Tree_node *right;
	struct Tree_node *left;
	int number;
};

struct link_list *insert_list(struct link_list *,int);
struct link_list *init_list(int);
void build_array(int *,int);
struct link_list *build_link_list(struct link_list *,int);
struct Tree_node *build_bst(struct Tree_node *,int);
struct Tree_node *init(int);
void usage(void);
void swap(int *,int *);
void build_bs_array(int *,int);
void selection_sort(int *,int);
void querry_array(int *,int);
void querry_bs(int *,int);
void binary_search(int *,int,int);
void querry_link_list(struct link_list *,int);
void querry_bst(struct Tree_node *,int);
void search_bst(struct Tree_node *,int);
