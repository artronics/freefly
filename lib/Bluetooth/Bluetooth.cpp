#include "Bluetooth.h"
#include <iostream>
#include <list>
#include <unistd.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/sdp.h>
#include <bluetooth/sdp_lib.h>
#include <bluetooth/l2cap.h>

using namespace std;

Bluetooth::Bluetooth() {
    devId = hci_get_route(nullptr);
    devices = new std::list<BluetoothDevice>;
}

Bluetooth::~Bluetooth() {
    hci_close_dev(devId);

    if(devices) {
        delete devices;
        devices = nullptr;
    }
}

bool Bluetooth::setup() {
    std::cout << "setup.. Nothing to do!!!" << endl;
    return false;
}

std::list<BluetoothDevice>* Bluetooth::inquiry(const int time) {
    int max_rsp = 255;

    devices->clear();
    auto ii = new inquiry_info[max_rsp * sizeof(inquiry_info)];

    int sk = hci_open_dev(devId);
    if(sk < 0) {
        cerr << "Error opening device:\t\t" << strerror(errno) << endl;
    }

    int flags = IREQ_CACHE_FLUSH;
    int num_rsp = hci_inquiry(devId, time, max_rsp, nullptr, &ii, flags);
    if (num_rsp < 0) {
        cerr << "Error inquiry:\t\t" << strerror(errno) << endl;
    }

    char addr[19] = {0};
    char name[248] = {0};
    uint8_t cod[3] = {0};
    for (int i = 0; i < num_rsp; ++i) {
        ba2str(&ii[i].bdaddr, addr);
        memset(name, 0, sizeof(name));

        if (hci_read_remote_name(sk, &ii[i].bdaddr, sizeof(name), name, 0) < 0) {
            strcpy(name, "[unknown]");
        }

        hci_read_class_of_dev(sk, cod, 0);

        devices->emplace_back(BluetoothAddress(addr, 18), name, strlen(name), (cod[2] << 16) | (cod[1]) << 8u | (cod[0]));
    }

    close(sk);
    delete [] ii;
    ii = nullptr;

    return devices;
}

bool Bluetooth::connect(const BluetoothAddress address) {

}
