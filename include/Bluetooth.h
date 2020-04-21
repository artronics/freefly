#ifndef FREEFLY_BLUETOOTH_H
#define FREEFLY_BLUETOOTH_H

#include <list>
#include "../lib/include/BluetoothDevice.h"

class Bluetooth {
private:
    int devId;
    std::list<BluetoothDevice>* devices;

public:
    Bluetooth();

    virtual ~Bluetooth();

    bool setup();

    std::list<BluetoothDevice> *inquiry(int time = 8);

    bool connect(const BluetoothAddress address);
};


#endif //FREEFLY_BLUETOOTH_H
