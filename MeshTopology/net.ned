
simple pc
{
    gates:
        input in[3];
        output out[3];


}

//
// TODO documentation
//
network Network
{
    @display("bgb=797,412");
    submodules:
        pc_1: pc {
            @display("p=67,173");

        }
        pc_2: pc {
            @display("p=383,42");
        }
        pc_3: pc {
            @display("p=722,180");
        }
        pc_4: pc {
            @display("p=383,345");
        }
    connections:

        pc_1.out[0] --> pc_2.in[0];
        pc_2.out[0] --> pc_1.in[0];
        pc_1.out[1] --> pc_3.in[1];
        pc_3.out[1] --> pc_1.in[1];
        pc_3.out[0] --> pc_2.in[1];
        pc_2.out[1] --> pc_3.in[0];
        pc_1.out[2] --> pc_4.in[0];
        pc_4.out[0] --> pc_1.in[2];
        pc_4.out[1] --> pc_3.in[2];
        pc_3.out[2] --> pc_4.in[1];
        pc_2.out[2] --> pc_4.in[2];
        pc_4.out[2] --> pc_2.in[2];
}

