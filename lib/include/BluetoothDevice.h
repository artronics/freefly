#ifndef FREEFLY_BLUETOOTH_DEVICE_H
#define FREEFLY_BLUETOOTH_DEVICE_H

#include "BluetoothAddress.h"

class BluetoothDevice {
private:
    BluetoothAddress address;
    char* name;
    unsigned int cod; // Device COD: Class Of Device

public:
    BluetoothDevice();

    BluetoothDevice(const BluetoothAddress &address, char *name, unsigned int nameLen, unsigned int cod);

    virtual ~BluetoothDevice();

    const BluetoothAddress &getAddress() const;

    char *getName() const;

    unsigned int getCod() const;

};


#endif //FREEFLY_BLUETOOTH_DEVICE_H
