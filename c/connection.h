#ifndef CONNECTION_H
#define CONNECTION_H
#include "gate.h"

typedef struct
{
  int fromGateID;
  int fromPin;
  int toGateID;
  int toPin;
} Connection;

typedef struct
{
  Connection **connections;
  int count;
  int allocated;
} ConnectionList;

ConnectionList *newConnectionList ();
void deleteConnectionList (ConnectionList *cl);
Connection *newConnection (ConnectionList *cl);
void readConnectionList (ConnectionList *cl, char *fileName);
void printConnectionList (ConnectionList *cl);
void printConnection (Connection *c);
#endif
