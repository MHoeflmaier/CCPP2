#include "type.h"
#include "connection.h"
#include "fanout.h"
#include <stdio.h>
#include <stdlib.h>


//lt Mail Hoermandinger und Hoeflmaier gemeinsame Abgabe

//Fanoutberechnung über alle Gates in der Connection.dat, //auch wenn es mehrere Schaltungen waren.

int main (int argc, char *argv[])
{
  if (argc < 5)
  { fputs ("usage: programm <gate.dat> <connection.dat> <type.dat> <function.dat> [weitere parameter]\n", stderr);
    exit (1);
  }

  
  ConnectionList *cl = newConnectionList ();
  readConnectionList (cl, argv[2]);
  
  //------------------------
  
  TypeList *tl = newTypeList ();
  readTypeList (tl, argv[3]);
 
  //------------------------
  
  GateList *gl = newGateList (tl);
  readGateList (gl, argv[1]);
//-----------------------
//printConnectionList(cl);
//printGateList(gl);	

	fanout(cl,gl);
	sort(tl);
  printTypeList(tl);
	//--------------------

	deleteGateList(gl);
	deleteTypeList(tl);
	deleteConnectionList(cl);
	
	

  return 0;
}


