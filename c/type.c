#include <stdio.h>
#include <stdlib.h>
#include "type.h"

TypeList *newTypeList ()
{
  TypeList *tl = (TypeList *) malloc (sizeof (TypeList));
  tl->count = 0;
  tl->allocated = 10;
  tl->types = (Type **) calloc (tl->allocated, sizeof (Type *));
  return tl;
}

void deleteTypeList (TypeList *tl)
{
  int i;
  for (i = 0; i < tl->count; i ++)  free (tl->types[i]);
  free (tl->types);
  free (tl);
}

Type *newType (TypeList *tl)
{
  if (tl->count >= tl->allocated)
  { tl->allocated *= 2;
    tl->types = (Type **) realloc (tl->types, tl->allocated * sizeof (Type *));
  }
  Type *t = (Type *) malloc (sizeof (Type));
  t->outgoing=0;
  t->count=0;
  t->fanout=0;
  tl->types[tl->count++] = t;
  return t;
}


void readTypeList (TypeList *tl, char *fileName)
{

  FILE *file = fopen (fileName, "r");
  if (file == NULL)  { perror (fileName);  exit (1); }
  int r, id;
  do
  {
    r = fscanf (file, "%d", &id);
    if (r != EOF)
    {
      Type *t = newType (tl);
      t->ID = id;
      r = fscanf (file, "%100s %d %d %lf", t->name, &t->inputPins, &t->outputPins, &t->delay);
    }
  }
  while (r != EOF);
  fclose (file);
  
  
  
}
Type *findType (TypeList *tl, int id)
{
  int i;
  for (i = 0; i < tl->count; i ++)
    if (tl->types[i]->ID == id)
      return (tl->types[i]);
  fprintf (stderr, "Type Id %d not found\n", id);
  exit (1);
}

void printType (Type *t)
{

  printf ("%d %s %d %d %lf, %d, %d, %lf\n", t->ID, t->name, t->inputPins, t->outputPins, t->delay,t->outgoing,t->count, t->fanout);
 
}

void printTypeList (TypeList *tl)
{
printf("id|name|inputPins|outputPins|delay|#outgoing|#gates|fanout");

	for(int i= 0;i<tl->count;i++)
	{
		printType(tl->types[i]);
		
	}
}
void sort(TypeList *tl)
{
	 qsort (tl->types, tl->count, sizeof (Type*), &typeOrder);
}

int typeOrder (const void *a, const void *b)
{
  
  Type *ta = *(Type **) a;
  Type *tb = *(Type **) b;
  if (a == b) return 0;
 
  if (ta->fanout < tb->fanout) return +1;
  if (ta->fanout > tb->fanout) return -1;

  return 0;
}





















