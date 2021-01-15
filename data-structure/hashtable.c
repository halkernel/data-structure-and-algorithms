#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define TABLE_SIZE 10000 //the max number of items before collision
#define ln printf("\n");

typedef struct hash_entry{
  char * key;
  char * val;
  struct hash_entry * next;
}HASH_ENTRY;


typedef struct hash_table{
  HASH_ENTRY ** entries; 
}HASH_TABLE;


HASH_TABLE * create_hash_table(){
  
  int i = 0;

  //allocating table
  HASH_TABLE * hashtable = malloc(sizeof(HASH_TABLE) * 1);  

  //allocating entries
  (*hashtable).entries = malloc(sizeof(HASH_ENTRY*) * TABLE_SIZE);
  
  for(i = 0; i < TABLE_SIZE; i++){
    (*hashtable).entries[i] = NULL;
  }
  
return hashtable;
}


unsigned int hash(const char * key){
  unsigned long int val = 0, i;
  unsigned int key_len = strlen(key);

  for(i = 0; i < key_len; i++){
    val = val * 73 + key[i];
  }

  val %= TABLE_SIZE;
  return val;

}

HASH_ENTRY * pair(const char * key, const char *value){
  
  HASH_ENTRY * tmp = malloc (sizeof ( HASH_ENTRY ) * 1);

  (*tmp).key = malloc(strlen(key) * 1);
  (*tmp).val = malloc(strlen(value) * 1);

  strcpy((*tmp).key, key);
  strcpy((*tmp).val, value);

  (*tmp).next = NULL;
  
  return tmp;

}


void set_hash(HASH_TABLE * ht, const char * key, const char * value){
  unsigned int slot = hash(key);

  HASH_ENTRY  * entry = (*ht).entries[slot];

  if(entry == NULL){
    (*ht).entries[slot] = pair(key, value);
    return;
  }

  HASH_ENTRY * prev;

  while (entry != NULL){
    if(strcmp((*entry).key, key) == 0){

        free((*entry).val);
        (*entry).val = malloc(strlen(value) + 1);
        strcpy((*entry).val, value);
        return;
    }

    prev = entry;
    entry = (*entry).next;
  }

  (*prev).next = pair(key, value);
  
}


char * get_hash(HASH_TABLE * ht, const char *key){
  unsigned int slot = hash(key);

  HASH_ENTRY  * entry = (*ht).entries[slot];

  if(entry == NULL){
   return NULL;
  }

  while (entry != NULL){
    if(strcmp((*entry).key, key) == 0){
      return (*entry).val;
    }    
    entry = (*entry).next;
  }

  return NULL;
}


void print_table(HASH_TABLE * ht){
  int i = 0;
  for(i = 0; i < TABLE_SIZE; i++){
    HASH_ENTRY * entry = (*ht).entries[i];

    if(entry == NULL){
      continue;
    }

    printf("slot[%d] ", i);

    while(entry != NULL){
      printf("[key=%s, value=%s] ", (*entry).key, (*entry).val);
      entry = (*entry).next;
    }

    ln
    
  }
}

int main(){

  HASH_TABLE * ht = create_hash_table();

  set_hash(ht, "key1", "katyusha");  
  set_hash(ht, "key2", "kalinka");  
  set_hash(ht, "key3", "minsk");  
  set_hash(ht, "key4", "kasparov");  
  set_hash(ht, "key5", "mikhail");  

  print_table(ht);
  return 0;
}