#ifndef GATE_H
#define GATE_H

#include "type.h"
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;
//using namespace placeholders;


class Gate
{
public:
	Gate (istream &s)
		{
			s >> gateId >> typeId;
			if (!s)  throw EOFException ();  // abort constructor!
		
		
		}
		bool operator< (const Gate &g) const  
		{ return gateId < g.gateId;}
		
		TypeInfo* lookUpType(TypeList &tl)
		{
			TypeInfo* isType = tl.findTypeInfo(typeId);
			isType->count++; // incCount();
			return isType;
		}
		
		void print (ostream &o = cout) const
   { o << "  " << setw (2) << setfill ('0') << gateId << ' ' << typeId << endl; }
   	Gate(unsigned Id) {gateId=Id;}
   	
   	 

private:

	unsigned gateId, typeId;
	
};

inline ostream &operator<< (ostream &o, const Gate &g)
{ g.print (o);  return o; }

class GateList
{
public:
   GateList (char *fileName, TypeList &tl);
   void print (ostream &o = cout) const;
   
   TypeInfo *lookUpGate(unsigned id) const
		{
			Gate g (id);
			auto it = gates.find(g);
		
			/*
			if (it == gates.end()) {
			    throw EOFException();
			}
			*/
			
			return it->second;
		}
private:
   map<Gate, TypeInfo*> gates;
     
};

inline ostream &operator<< (ostream &o, const GateList &gl)
{ gl.print (o);  return o; }





#endif
