#include "type.h"
#include "connection.h"
#include "gate.h"
#include "fanout.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
   if (argc < 5)
   {  cerr << "usage: programm <gate.dat> <connection.dat> <type.dat> <function.dat> [weitere parameter]";
      exit (1);
   }
   
   ConnectionList cl (argv[2]);
  
   TypeList tl (argv[3]);
   
   GateList gl (argv[1], tl);
   
   
   Fanout::computeFanout(cl,gl);
   
	//fanout, sort, print
	
   cout << tl;
   
}
