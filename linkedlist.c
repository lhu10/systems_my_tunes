#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "linkedlist.h"

struct song_node *new_node(char *n, char *a){
    struct song_node *ns; 
    ns = malloc(sizeof(struct song_node)); 
    
    strncpy(ns->name, n, sizeof(ns->name)-1); 
    strncpy(ns->artist, a, sizeof(ns->artist)-1); 
    
    ns->next = NULL; 

    return ns; 
}

struct song_node *free_node(struct song_node *Bob){
	free(Bob);
	return NULL;
}

struct song_node *insert_front(struct song_node *Current, struct song_node *newNode){
    struct song_node* previous = NULL;
    struct song_node* orig = Current;
    if(Current==NULL){
        return(newNode);
    } 
    //dealing with head of list
    if(strcmp(newNode->artist,Current->artist)<0){
        newNode->next=Current;
        return(newNode);
    }
    if(strcmp(newNode->artist,Current->artist)==0){
        if(strcmp(newNode->name,Current->name)<0){
            newNode->next=Current;
            return(newNode);
        }
    }
    previous=Current;
    Current=Current->next;
    while(Current){
        if(strcmp(newNode->artist,Current->artist)<0){
            newNode->next=previous->next;
            previous->next=newNode;
            return(orig);
        }
        if(strcmp(newNode->artist,Current->artist)==0){
            if(strcmp(newNode->name,Current->name)<0){
                newNode->next=previous->next;
                previous->next=newNode;
                return(orig);
            }
        }
        previous=Current;
        Current=Current->next;
    }
    previous->next=newNode;
    return(orig);
}

void print_node(struct song_node *Bob){
    if(Bob == NULL){
        printf(" ");  
    }
    else{
        printf(" %s: %s ", Bob->artist, Bob->name);
    }
}

void print_list(struct song_node *Bob){
    printf("[");
    while (Bob != NULL)
    {
        print_node(Bob);
        printf("|");
        Bob = Bob->next;
    }
    printf("]\n\n");
}

struct song_node *find_node(struct song_node *Bob, char *n, char *a){
    printf("looking for [%s: %s]\n", a, n); 
    while(Bob != NULL){
        if(strcmp(n, Bob->name) == 0 && strcmp(a, Bob->artist) == 0){
            printf("Node found!\n"); 
            return Bob; 
        }
        Bob = Bob -> next; 
    }
    printf("Node not found\n"); 
    return Bob;
}

struct song_node *find_first_song(struct song_node *Bob, char *a){
    printf("looking for first song from [%s]\n", a)
    ;
    while(Bob != NULL){
        if(strcmp(a, Bob->artist) == 0){
            printf("Artist found!\n");
            return Bob; 
        }
        Bob = Bob -> next; 
    }
    printf("Artist not found\n"); 
    return Bob; 
}

int list_length(struct song_node *Bob)
{
	int items = 1;
	while(Bob->next){
    	Bob = Bob->next;
    	items++;
	}
	return items;
}

struct song_node *return_random(struct song_node *Bob, int random)
{
	struct song_node *p = Bob;
	while (random)
	{
    	p = p->next;
    	random--;
	}
	return p;
}


struct song_node *remove_node(struct song_node *Bob, char *n, char *a)
{
    printf("Removing [%s: %s]\n", a, n);
    struct song_node *p = Bob->next;
	if (strcmp(n, Bob->name) == 0 && strcmp(a, Bob->artist) == 0) //remove 0th node
	{
    	Bob = p;
    	return Bob;
	}
	struct song_node *x = Bob;
	p = Bob->next;
	while (p) //remove [1,n-1] node
	{
    	if (strcmp(n, p->name) == 0 && strcmp(a, p->artist) == 0)
    	{
        	Bob->next = p->next;
        	free_node(p);
        	return x;
    	}
    	Bob = p;
    	p = p->next;
	}
	if (strcmp(n, Bob->name) == 0 && strcmp(a, Bob->artist) == 0) //remove n node
	{
    	Bob = p;
    	return x;
	}
	return x;
}

struct song_node *free_list(struct song_node *Bob)
{
	struct song_node *s = Bob;
	while(s)
	{
    	s = Bob->next;
    	Bob = free_node(Bob);
    	Bob = s;
	}
	return Bob;
}

