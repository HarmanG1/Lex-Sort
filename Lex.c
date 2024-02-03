/********************************************************************************* 
* Harman Gidha
* Main File
* Lex.c 
*********************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "List.h"

#define MAX_LEN 300

int main(int argc, char * argv[]){

   int line_count;
   FILE *in, *out;
   char line[MAX_LEN];

   // check command line for correct number of arguments
   if( argc != 3 ){
      fprintf(stderr, "Error: two arguments needed. Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }

   // open files for reading and writing 
   in = fopen(argv[1], "r");
      if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }

   out = fopen(argv[2], "w");
   if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }

   // read each line of input file, then count and print tokens
   line_count = 0;
   while( fgets(line, MAX_LEN, in) != NULL)  
   {
      line_count++;
   }
    fseek(in, 0, SEEK_SET);
    char **linearr = (char **) calloc(line_count, sizeof(char*));
    int arrin = 0;
    while( fgets(line, MAX_LEN, in) != NULL)  
    {
        char *token = strtok(line, "\n");
        linearr[arrin] = malloc(strlen(token) * sizeof(char*));
        strcpy(linearr[arrin], token);
        arrin++;
    }
    
    List L = newList();
    for(int i = 1; i < arrin; i++)
    {
        if(length(L) == 0)
        {
            append(L, 0);
        }

        moveFront(L);
        bool inserted = false;
        while(!inserted)
        {
            if(index(L) == -1)
            {
                append(L, i);
                inserted = true;
            }
            else if(strcmp(linearr[get(L)], linearr[i]) > 0)
            {
                insertBefore(L, i);
                inserted = true;
            }
            else{
                moveNext(L);
            }
        }
        
    }
    moveFront(L);
    for(int i = 0; i < arrin; i++)
    {
        fprintf(out, "%s\n", linearr[get(L)]);
        moveNext(L);
    }

   // close files 
   fclose(in);
   fclose(out);
   freeList(&L);
   for(int i = 0; i < arrin; i++)
   {
        free(linearr[i]);
   }
   free(linearr);

   return(0);
}
