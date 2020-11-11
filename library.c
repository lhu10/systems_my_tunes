#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "linkedlist.h"
#include "library.h"

void new_alpha(struct alpha_node *lib){
    int i; 
    char letter = 'A'; 
    for(i = 0; i < 27; i++){
        (lib+i)->c = letter; 
        (lib+i)->head = NULL;
        letter++; 
    }
} 

int find_index(char let){
    int result;
    result = let - 65;
    if(result < 0 || result > 25){
        result = 26; 
    }
    return result; 
}

void add_node(struct alpha_node *lib, struct song_node *node){
    int result; 
    result = find_index(node->artist[0]); 
    (lib+result)->head = insert_front((lib+result)->head, node);
}

struct song_node *search_song(struct alpha_node *lib, char *n, char *a){
    int temp;
    temp = find_index(a[0]);
    struct song_node *pointer_to_head = ((lib+temp)->head);
    return(find_node(pointer_to_head,n,a));
}

struct song_node *search_artist(struct alpha_node *lib, char *a){
    int temp;
    temp = find_index(a[0]);
    struct song_node *pointer_to_head = ((lib+temp)->head);
    return(find_first_song(pointer_to_head,a));
}

void print_letter(struct alpha_node *lib, char let){
    int result;
    result = find_index(let); 
    printf("%c list\n", (lib+result)->c);
    print_list((lib+result)->head);
}

void print_artist_song(struct alpha_node *lib, char *a){
    int result; 
    result = find_index(a[0]); 
    struct song_node *next_pointer = ((lib+result)->head); 
	printf("Printing [%s]\n", a);
    while(next_pointer != NULL){
        if(strcmp( next_pointer->artist, a) == 0){
            print_node(next_pointer); 
        }
        next_pointer = next_pointer->next; 
    }
}

void print_library(struct alpha_node *lib){
    int i; 
    for(i = 0; i < 27; i++){
        if((lib+i)->head != NULL){
            print_letter(lib, (lib+i)->c); 
        }
    }
}

int library_length(struct alpha_node *lib)
{
	int i = 0; //index of the library array
	int num = 0; //number of songs
	int len = 27; //length of array
	while (len)
	{
    	if ((lib + i)->head)
        	num += list_length((lib + i)->head);
    	i++;
    	len--;
	}
	return num;
}

void shuffle(struct alpha_node *lib)
{
	srand(time(NULL));
	int len = library_length(lib); //length of library
	int counter;
	struct song_node *random;
	int i = 0; //index of the array
	int loop = 3; //# of times to shuffle
	while (loop)
	{
    	counter = rand() % len + 1; //gets randomized
    	while (i < 27)
    	{
        	if ((lib + i)->head)
        	{
            	if (counter > list_length((lib + i)->head))
                	counter -= list_length((lib + i)->head);
            	else
                	break;
        	}
        	i++;
    	}
    	random = (lib + i)->head;
    	counter--;
    	while (counter)
    	{
        	random = random->next;
        	counter--;
    	}
    	printf("%s: %s\n", random->artist, random->name);
    	loop--;
    	i = 0; //reset array index
	}
}

void delete_song(struct alpha_node *lib, char *n, char *a)
{
	int result = find_index(a[0]);
	struct song_node *current = (lib + result)->head;
	(lib + result)->head = remove_node(current, n, a);
}

void clear(struct alpha_node *lib)
{
	int i = 0;
	while (i < 27)
	{
    	if ((lib + i)->head != NULL){
        	(lib + i)->head = free_list((lib + i)->head);
		}
    	i++;
	}
}
