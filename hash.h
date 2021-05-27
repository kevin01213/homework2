#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

struct hash_node{
	
	struct hash_node *next;
	int number;
};

struct hash_node **build_hash(struct hash_node **,int);
struct hash_node **hash_init(struct hash_node **,int);
struct hash_node **hash_insert(struct hash_node **,int,int);
unsigned int hash65(int);
struct hash_node *node_insert(struct hash_node *,int);
void link_find(struct hash_node *,int);
void querry_hash(struct hash_node **,int);
