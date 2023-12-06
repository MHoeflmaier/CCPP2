#ifndef TYPE_H
#define TYPE_H


typedef struct
{
  int ID;
  char name[101];
  int inputPins;
  int outputPins;
  double delay;
  int outgoing;
  int count;
  double fanout;
} Type;

typedef struct
{
  Type **types;
  int count;
  int allocated;
} TypeList;

TypeList *newTypeList ();
void deleteTypeList (TypeList *tl);
Type *newType (TypeList *tl);
void readTypeList (TypeList *tl, char *fileName);
Type *findType (TypeList *tl, int id);
void printType (Type *t);
void printTypeList (TypeList *tl);
Type *findType (TypeList *tl, int id);
void sort(TypeList *tl);
int typeOrder (const void *a, const void *b);

#endif
