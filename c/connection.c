#include <stdio.h>
#include <stdlib.h>
#include "connection.h"

ConnectionList *newConnectionList ()
{
  ConnectionList *cl = (ConnectionList *) malloc (sizeof (ConnectionList));
  cl->count = 0;
  cl->allocated = 10;
  cl->connections = (Connection **) calloc (cl->allocated, sizeof (Connection *));
  return cl;
}

void deleteConnectionList (ConnectionList *cl)
{
  int i;
  for (i = 0; i < cl->count; i ++)  free (cl->connections[i]);
  free (cl->connections);
  free (cl);
}

Connection *newConnection (ConnectionList *cl)
{
  if (cl->count >= cl->allocated)
  { cl->allocated *= 2;
    cl->connections = (Connection **) realloc (cl->connections, cl->allocated * sizeof (Connection *));
  }
  Connection *c = (Connection *) malloc (sizeof (Connection));
  cl->connections[cl->count++] = c;
  return c;
}


void readConnectionList (ConnectionList *cl, char *fileName)
{

  FILE *file = fopen (fileName, "r");
  if (file == NULL)  { perror (fileName);  exit (1); }
  int r, id;
  do
  {
    r = fscanf (file, "%d", &id);
    if (r != EOF)
    {
      Connection *c = newConnection (cl);
      c->fromGateID = id;
      r = fscanf (file, "%d %d %d", &c->fromPin, &c->toGateID, &c->toPin);
    }
  }
  while (r != EOF);
  fclose (file);
  
  
}


void printConnection (Connection *c)
{
  printf ("%d %d, %d %d\n", c->fromGateID, c->fromPin, c->toGateID, c->toPin);
}

void printConnectionList (ConnectionList *cl)
{

	for(int i= 0;i<cl->count;i++)
	{
		printConnection(cl->connections[i]);
		
	}
}



















