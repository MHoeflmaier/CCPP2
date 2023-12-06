#include "fanout.h"

void fanout (ConnectionList *cl, GateList *gl)
{


	for(int i = 0;i<cl->count;i++)
	{
		Gate* g = findGate(gl,cl->connections[i]->fromGateID);
			
		g->isType->outgoing++;
		g->isType->fanout = (double) g->isType->outgoing / g->isType->count;
	

	}	



}
