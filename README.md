# Sharp_IR_UDP
Read Sharp IR sensor values and send them over UDP

The Analogue Values from the IR sensor are checked, and if the values are in a certain range (which can be specified as min and max distance in the code) then the over UDP packets are sent.

Install the Ethernet2 and the SharpDistSensor Library.

The code can be used with multiple sensors, just change uncomment the arrays in setup and the loop.

Change the "max_distance" and the "min_distance" according to your needs. Its better to have a minimum of at least 50, as any lower will give inaccurate readings which may not be desirable for certain applications.
