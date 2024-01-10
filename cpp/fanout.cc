#include "fanout.h"
#include <cstdio>

using namespace std;

void Fanout::computeFanout(const ConnectionList &cl,const GateList &gl)
{
	for(const Connection &con: cl.getConnections())
	{
		TypeInfo *type = gl.lookUpGate(con.getvonGateId());			
		type->outgoing++; // incOutgoing();
		type->fanout = static_cast<double>(type->outgoing) / type->count; // setFanout((double) type->getOutgoing() / type->getCount());
	}	
}
