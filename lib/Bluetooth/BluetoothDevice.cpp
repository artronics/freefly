#include "../include/BluetoothDevice.h"

BluetoothDevice::BluetoothDevice() {}

BluetoothDevice::~BluetoothDevice() {

}

BluetoothDevice::BluetoothDevice(const BluetoothAddress &address, char *name, const unsigned int nameLen, unsigned int cod) : address(address),

                                                                                                   name(name),
                                                                                                  cod(cod) {}

const BluetoothAddress &BluetoothDevice::getAddress() const {
    return address;
}

char *BluetoothDevice::getName() const {
    return name;
}

unsigned int BluetoothDevice::getCod() const {
    return cod;
}
