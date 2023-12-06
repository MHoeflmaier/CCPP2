#ifndef GATE_H
#define GATE_H
#include "type.h"

typedef struct
{
  int ID;
  int TypeID;
  Type *isType;
} Gate;

typedef struct
{
  Gate **gates;
  int count;
  int allocated;
  TypeList* types;
} GateList;

GateList *newGateList (TypeList *tl);
void deleteGateList (GateList *gl);
Gate *newGate (GateList *gl);
void readGateList (GateList *gl, char *fileName);
void printGate (Gate *g);
void printGateList (GateList *gl);
void makeTypePointers (GateList *gl);
Gate* findGate (GateList *gl, int id);

#endif
