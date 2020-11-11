#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h> 

#include "linkedlist.h"
#include "library.h"

int main(){
    
    srand(time(NULL));
	struct song_node *head, *song1, *song2, *song3, *song4, *song5, *song6, *song7;
    song1 = new_node("Sandstorm", "Darude");
    song2 = new_node("Beat it", "Michael Jackson");
    song3 = new_node("Billie Jean", "Michael Jackson");
    song4 = new_node("Smooth Criminal", "Michael Jackson");
    song5 = new_node("Gangnam Style", "Psy");
    song6 = new_node("Gentlemen", "Psy"); 
    song7 = new_node("Congratulations", "Post Malone"); 

    head = insert_front(song3, song7); 
    head = insert_front(head, song1); 
    head = insert_front(head, song6); 
    head = insert_front(head, song2); 
    head = insert_front(head, song5);
    head = insert_front(head, song4); 
    
    printf("LINKED LIST TESTS\n"); 
    printf("=========================================\n\n"); 
    printf("Testing print_list:\n"); 
    print_list(head); 
    printf("=========================================\n\n"); 
    printf("Testing print_node:\n"); 
    print_node(song5); 
    printf("\n");
    printf("=========================================\n\n"); 
    printf("Testing find_node:\n"); 
    print_node(find_node(head, "Smooth Criminal", "Michael Jackson"));
    printf("\n"); 
    print_node(find_node(head, "Thriller", "Michael Jackson"));
    printf("\n");
    printf("=========================================\n\n"); 
    printf("Testing find_first_song:\n"); 
    print_node(find_first_song(head, "Psy")); 
    printf("\n");
    print_node(find_first_song(head, "Michael Jackson")); 
    printf("\n");
    print_node(find_first_song(head, "Taylor Swift")); 
    printf("\n");
    printf("=========================================\n\n"); 
    printf("Testing return_random:\n"); 
    print_node(return_random(head, rand() % list_length(head)));
	  printf("\n");
	  print_node(return_random(head, rand() % list_length(head)));
	  printf("\n");
	  print_node(return_random(head, rand() % list_length(head))); 
    printf("\n");
    printf("=========================================\n\n"); 
    printf("Testing remove_node:\n"); 
    head = remove_node(head, "Sandstorm", "Darude"); 
    print_list(head);
    head = remove_node(head, "Gangnam Style", "Psy"); 
    print_list(head);
    printf("=========================================\n\n"); 
    printf("Testing free_list\n"); 
    head = free_list(head);
    printf("list after free_list:\n");  
    print_list(head); 

    song1 = new_node("Sandstorm", "Darude");
    song2 = new_node("Beat it", "Michael Jackson");
    song3 = new_node("Billie Jean", "Michael Jackson");
    song4 = new_node("Smooth Criminal", "Michael Jackson");
    song5 = new_node("Gangnam Style", "Psy");
    song6 = new_node("Gentlemen", "Psy"); 
    song7 = new_node("Congratulations", "Post Malone"); 

    printf("=========================================\n\n");
    printf("MUSIC LIBRARY TESTS\n");
    printf("=========================================\n\n");
    
    struct alpha_node library[27];
    new_alpha(library); 
    add_node(library, song7);  
    add_node(library, song1);
    add_node(library, song4);
    add_node(library, song6); 
    add_node(library, song2); 
    add_node(library, song3); 
    add_node(library, song5); 
    
    printf("Testing print_library:\n");
    print_library(library);
    printf("=========================================\n\n");
    printf("Testing print_letter:\n");
    print_letter(library, 'M'); 
    printf("=========================================\n\n");
    printf("Testing search_song:\n");
    print_node(search_song(library, "Gentlemen", "Psy"));
    printf("\n");
    print_node(search_song(library, "Lemon", "Kenshi Yonezu"));
    printf("=========================================\n\n");
    printf("Testing search_artist:\n");
    print_list(search_artist(library, "Post Malone"));
    print_list(search_artist(library, "Panic! at the Disco"));
    printf("=========================================\n\n");
    printf("Testing delete_song:\n"); 
    delete_song(library, "Billie Jean", "Michael Jackson"); 
    print_library(library); 
    delete_song(library, "Congratulations", "Post Malone"); 
    print_library(library); 
    printf("=========================================\n\n");
    printf("Testing clear:\n");
    clear(library); 
    printf("Library after clear:\n"); 
    print_library(library); 
    printf("=========================================\n\n");

    song1 = new_node("Sandstorm", "Darude");
    song2 = new_node("Beat it", "Michael Jackson");
    song3 = new_node("Billie Jean", "Michael Jackson");
    song4 = new_node("Smooth Criminal", "Michael Jackson");
    song5 = new_node("Gangnam Style", "Psy");
    song6 = new_node("Gentlemen", "Psy"); 
    song7 = new_node("Congratulations", "Post Malone");

    printf("Adding songs to empty library:\n"); 
    add_node(library, song6);
    add_node(library, song2);
    add_node(library, song1);
    add_node(library, song5);
    add_node(library, song7);
    print_library(library); 
    printf("=========================================\n\n");
    printf("Testing print_artist_song:\n"); 
    print_artist_song(library, "Psy"); 
    printf("\n");
    print_artist_song(library, "Darude"); 
    printf("\n");
    printf("=========================================\n\n");
    printf("Testing shuffle:\n"); 
    shuffle(library);
    printf("=========================================\n\n");
    

    return 0; 
}
