#include "connection.h"
#include <fstream>

ConnectionList::ConnectionList (char *fileName)
{
   ifstream s (fileName);
   try  { for (;;) connections.push_back (s); }
   catch (EOFException) {}
}
