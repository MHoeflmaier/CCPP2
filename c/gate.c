#include <stdio.h>
#include <stdlib.h>
#include "gate.h"


GateList *newGateList (TypeList *tl)
{
  GateList *gl = (GateList *) malloc (sizeof (GateList));
  gl->count = 0;
  gl->allocated = 10;
  gl->gates = (Gate **) calloc (gl->allocated, sizeof (Gate *));
  gl->types=tl;
  return gl;
}

void deleteGateList (GateList *gl)
{
  int i;
  for (i = 0; i < gl->count; i ++)  free (gl->gates[i]);
  free (gl->gates);
  free (gl);
}

Gate *newGate (GateList *gl)
{
  if (gl->count >= gl->allocated)
  { gl->allocated *= 2;
    gl->gates = (Gate **) realloc (gl->gates, gl->allocated * sizeof (Gate *));
  }
  Gate *g = (Gate *) malloc (sizeof (Gate));
  gl->gates[gl->count++] = g;
  return g;
}

void makeTypePointers (GateList *gl)
{
	int i;
  	for (i = 0; i < gl->count; i ++)
  	{
  	
    	gl->gates[i]->isType = findType (gl->types, gl->gates[i]->TypeID);
    	
    	gl->gates[i]->isType->count++;
    }

}

Gate *findGate (GateList *gl, int id)
{
  int i;
  for (i = 0; i < gl->count; i ++)
    if (gl->gates[i]->ID == id)
      return (gl->gates[i]);
  fprintf (stderr, "Gates Id %d not found\n", id);
  exit (1);
}


void readGateList (GateList *gl, char *fileName)
{

  FILE *file = fopen (fileName, "r");
  if (file == NULL)  { perror (fileName);  exit (1); }
  int r, id;
  do
  {
    r = fscanf (file, "%d", &id);
    if (r != EOF)
    {
      Gate *g = newGate (gl);
      g->ID = id;
      r = fscanf (file, "%d", &g->TypeID);
    }
  }
  while (r != EOF);
  fclose (file);
  makeTypePointers(gl);
 
}

void printGate (Gate *g)
{
  printf ("%d %d\n", g->ID, g->TypeID);
   
}

void printGateList (GateList *gl)
{

	for(int i= 0;i<gl->count;i++)
	{
		printGate(gl->gates[i]);
		
	}
}



















