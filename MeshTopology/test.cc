/*
 * test.cc
 *
 *  Created on: Apr 29, 2019
 *      Author: Rakib
 */


#include<string.h>
#include<omnetpp.h>
using namespace omnetpp;
class pc :public cSimpleModule
{
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void forwardMessage(cMessage *msg);
};
Define_Module(pc);
void pc::initialize()
{
    if(strcmp("pc_1",getName()) ==0 )
    {
        cMessage *msg = new cMessage("checkMsg");
        forwardMessage(msg);

    }
   /* else if(strcmp("pc_2",getName()) ==0 )
        {
            cMessage *msg = new cMessage("checkMsg");
            send(msg, "out");

        }
    else if(strcmp("pc_3",getName()) ==0 )
        {
            cMessage *msg = new cMessage("checkMsg");
            send(msg, "out");

        }
    else
        {
            cMessage *msg = new cMessage("checkMsg");
            send(msg, "out");

        }*/
}
void pc::handleMessage(cMessage *msg)
{

    forwardMessage(msg);


}
void pc::forwardMessage(cMessage *msg)
{
    // In this example, we just pick a random gate to send it on.
    // We draw a random number between 0 and the size of gate `out[]'.
    int n = gateSize("out");
        int k = intuniform(0,n-1);

        EV << "Forwarding message " << msg << " on port out[" << k << "]\n";
        send(msg, "out", k);

    EV <<"n is  "<<n;


}

