#include "gate.h"
#include <fstream>

GateList::GateList (char *fileName, TypeList &tl)
{
   ifstream s (fileName);
   try  { 
   	for (;;) {
   		Gate gate(s);
   		gates.insert (make_pair(gate, gate.lookUpType(tl)));
   		
   		
   		}
   }
   catch (EOFException) {}
   
   
}
void GateList::print (ostream &o) const
{
   //set<const Track *, TrackOrder> ts;
   //for (const Gate &gate: tracks)  ts.insert (&track);

   for (const pair<const Gate, TypeInfo*> &g: gates)
   {  
   	o<<g.first;
   
   
   }
}
