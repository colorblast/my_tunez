#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include <string.h>

//main method
int main(){
  struct song_node *s2 = (struct song_node *)malloc(sizeof(struct song_node));
  struct song_node *s4 = (struct song_node *)malloc(sizeof(struct song_node));
  
  strcpy(s2->name,"Girl on Fire");
  strcpy(s2->artist,"Alicia Keys");
  s2->next = s4;
  strcpy(s4->name,"Scars to Your Beautiful");
  strcpy(s4->artist,"Alessia Cara");
  s4->next = NULL;


  printf("s2: {%s, %s, s4}\n", s2->name, s2->artist);
  printf("s4: {%s, %s, NULL}\n\n", s4->name, s4->artist);

  printf("Testing print_list(s1):\n");
  print_list(s2);

  printf("\nTesting insert_front(s1, \"Airplanes\", \"B.o.B\"):\n");
  struct song_node *s1 = insert_front(s2, "Airplanes", "B.o.B");
  print_list(s1);


  printf("\nTesting insert_ordered(s1, \"I Gotta Feeling\", \"The Black Eyed Peas\"):\n");
  struct song_node *s3 = insert_ordered(s1, "I Gotta Feeling", "The Black Eyed Peas");
  print_list(s1);

  printf("\nTesting find_song(s1, \"I Gotta Feeling\", \"The Black Eyed Peas\"):\n");
  printf("correct: %p\n", s3);
  printf("mine: %p\n", find_song(s1, "I Gotta Feeling", "The Black Eyed Peas"));
  printf("Testing find_song(s1, \"testsong\", \"testartist\"):\n");
  printf("correct: (nil)\n");
  printf("mine: %p\n", find_song(s1, "testsong", "testartist"));

  struct song_node *imyours = insert_ordered(s1, "I'm Yours", "Alessia Cara");
  print_list(s1);
  printf("\nTesting first_song(s1, \"Alessia Cara\"):\n");
  printf("first song: %s\n", first_song(s1, "Alessia Cara")->name);
  printf("Testing first_song(s1, \"test\"):\n");
  printf("first song: %s\n", first_song(s1, "test")->name);
  
  printf("\nTesting random_song(s1):\n");
  printf("%s\n", random_song(s1)->name);

  printf("\nTesting remove_song(s1, \"I'm Yours\", \"Alessia Cara\"):\n");
  printf("old list:\n");
  print_list(s1);
  printf("=====================================\n");
  printf("code %d: 1 = removed, -1 = not found\n", remove_song(s1, "I'm Yours", "Alessia Cara"));
  printf("=====================================\n");
  printf("new list:\n");
  print_list(s1);
  printf("Testing remove_song(s1, \"testsong\", \"testartist\"):\n");
  printf("old list:\n");
  print_list(s1);
  printf("=====================================\n");
  printf("code %d: 1 = removed, -1 = not found\n", remove_song(s1, "testsong", "testartist"));
  printf("=====================================\n");
  printf("new list:\n");
  print_list(s1);
  
  printf("\nTesting free_list(s1):\n");
  printf("list = %p\n", free_list(s1));
  
  return 0;
}