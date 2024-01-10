#ifndef FANOUT_H
#define FANOUT_H
#include "connection.h"
#include "gate.h"


class Fanout
{
public:


static void computeFanout (const ConnectionList &cl, const GateList &gl);

};




#endif
