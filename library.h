struct alpha_node{
    char c; 
    struct song_node *head;
};

void new_alpha(struct alpha_node *lib); 

void add_node(struct alpha_node *lib, struct song_node *node); 

struct song_node *search_song(struct alpha_node *lib, char *n, char *a);

struct song_node *search_artist(struct alpha_node *lib, char *a);

void print_letter(struct alpha_node *lib, char let);

void print_artist_song(struct alpha_node *lib, char *a);

void print_library(struct alpha_node *lib);

void shuffle(struct alpha_node *lib);

void delete_song(struct alpha_node *lib, char *n, char *a);

void clear(struct alpha_node *lib);

