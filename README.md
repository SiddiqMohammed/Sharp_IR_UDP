# Sharp IR UDP
Read Sharp IR sensor values and send them over UDP

The Analogue Values from the IR sensor are checked, and if the values are in a certain range (which can be specified as min and max distance in the code) then the values are sent over UDP.

## Setup
```arduino
#include <EthernetUdp2.h>
#include <SharpDistSensor.h>
```
Install the Ethernet2 and the SharpDistSensor Library.

The code can be used with multiple sensors, just change uncomment the arrays in setup and the loop.

Change the "max_distance" and the "min_distance" according to your needs. It is better to have a minimum of at least 50, as any lower will give inaccurate readings which may not be desirable for certain applications.


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
