#ifndef TYPE_H
#define TYPE_H

#include "connection.h"
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;
//using namespace placeholders;


class Type
{
public:
	Type (istream &s)
		{
			s >> typeId >> name >> anzahlInputPins >> anzahlOutputPins >> delay;
			if (!s)  throw EOFException ();  // abort constructor!
		
		
		}
		Type(unsigned Id) {typeId=Id;}
		
		bool operator< (const Type &t) const  
		{ return typeId < t.typeId;}
		void print (ostream &o = cout) const
   		{ o << setw (2) << setfill ('0') << typeId << ' ' << name; }
		
		/*
		void incCount()
		{count++;}
		
		unsigned getCount()
		{return count;}
		
		void incOutgoing()
		{outgoing++;}
		
		unsigned getOutgoing()
		{return outgoing;}
		
		void setFanout(double val)
		{fanout=val;}
		*/
		
private:

	unsigned typeId, anzahlInputPins, anzahlOutputPins;
  	string name;
  	double delay;
};

inline ostream &operator<< (ostream &o, const Type &t)
{ t.print (o);  return o; }

class TypeInfo {

public:
    TypeInfo() : count(0), outgoing(0), fanout(0.0) {}
    
    unsigned count, outgoing;
    double fanout;
    
    bool operator< (const TypeInfo &t) const  
		{ return fanout < t.fanout;}
};

class TypeList
{
public:
   TypeList (char *fileName);
   void print (ostream &o = cout) const;
   TypeInfo *findTypeInfo(int typeId)
	{
		Type t (typeId);
		auto it = types.find(t);
		
		/*
		if (it == types.end()) {
		    throw EOFException();
		}
		*/
		
		return &it->second;
	}
	


private:
   map<Type, TypeInfo> types;
   
};


inline ostream &operator<< (ostream &o, const TypeList &tl)
{ tl.print (o);  return o; }





#endif
