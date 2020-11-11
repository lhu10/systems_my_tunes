struct song_node{
    char name[100];
    char artist[100];
    struct song_node *next;
};


struct song_node *new_node(char *n, char *a);

struct song_node *insert_front(struct song_node *Current, struct song_node *newNode);

void print_node(struct song_node *Bob);

void print_list(struct song_node *Bob);

struct song_node *find_node(struct song_node *Bob, char *n, char*a); 

struct song_node *find_first_song(struct song_node *Bob, char *a);

int list_length(struct song_node *Bob);

struct song_node *return_random(struct song_node *Bob, int random);

struct song_node *remove_node(struct song_node *Bob, char *n, char *a);

struct song_node *free_list(struct song_node *Bob); 


