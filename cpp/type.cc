#include "type.h"
#include <fstream>

TypeList::TypeList (char *fileName)
{
   ifstream s (fileName);
   try  { for (;;) types.insert (make_pair(Type(s), TypeInfo())); }
   catch (EOFException) {}
}

struct TypeInfoOrder
{  bool operator() (const pair<const Type, TypeInfo> *a, const pair<const Type, TypeInfo> *b) const
   { 
   	if(!(a->second < b->second) && !(b->second < a->second))
   	   return b->first < a->first;
   	
   	return b->second < a->second;
   
   }
};


void TypeList::print (ostream &o) const
{
   set<const pair<const Type, TypeInfo> *, TypeInfoOrder> ts;
   for (const pair<const Type, TypeInfo> &TypePair: types)  ts.insert (&TypePair);

   
   for ( const pair<const Type, TypeInfo> * const &t: ts)
   {  
   	o<<t->first << " " << t->second.count << " " << t->second.outgoing << " " << t->second.fanout << " " << endl;
   	
   	//o<< t.first << " " << t.second.count << " " << t.second.outgoing << " " << t.second.fanout << " "  << endl;
   
   
   }
}
