#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
//using namespace placeholders;

class EOFException {};

class Connection
{
public:
	Connection (istream &s)
		{
			s >> vonGateId >> vonPin >> nachGateId >> nachPin;
			if (!s)  throw EOFException ();  // abort constructor!
		
		
		}
		/*bool operator< (const Connection &c) const  
		{ return vonGateId < c.vonGateId && vonPin < c.vonPin && nachGateId < c.nachGateId && nachPin < c.nachPin; }*/
		//Eindeutigkeit der Werte und auch die Ordnung sind uns egal, da wir sie nur zum 	iterieren benötigen.
		
		unsigned getvonGateId() const {return vonGateId;}
		

private:

	unsigned vonGateId, vonPin, nachGateId, nachPin;
  
};




class ConnectionList
{
public:
   ConnectionList (char *fileName);
   const vector<Connection>& getConnections() const { return connections; }

private:
   vector<Connection> connections;


};







#endif
