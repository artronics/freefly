#ifndef FREEFLY_BLUETOOTH2_H
#define FREEFLY_BLUETOOTH2_H

#include <string>
#include <vector>
#include <array>

using namespace std;

struct BluetoothInfo {
    array<uint8_t, 6> address;
    string name;
};


class Bluetooth2 {
private:
    int devId;
    int socket;
    vector<BluetoothInfo> bluetoothDevices;
public:
    Bluetooth2();

    virtual ~Bluetooth2();

    void scan();
    void displayDevices();
};


#endif //FREEFLY_BLUETOOTH2_H
