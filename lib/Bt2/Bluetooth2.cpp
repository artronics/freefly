#include <iostream>
#include "Bluetooth2.h"
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <unistd.h>
#include <string>
#include <array>
#include <iterator>

using namespace std;

void Bluetooth2::scan() {
    cout << "hello";
    inquiry_info *ii = nullptr;
    int len = 8;
    int max_rsp = 255;
    int flags = IREQ_CACHE_FLUSH;
    int num_rsp;

    ii = (inquiry_info *) malloc(max_rsp * sizeof(inquiry_info));
    num_rsp = hci_inquiry(this->devId, len, max_rsp, nullptr, &ii, flags);
    if (num_rsp < 0) perror("hci_inquiry");

    char addr[19] = {0};
    char name[254] = {0};
    for (int i = 0; i < num_rsp; i++) {
        ba2str(&(ii + i)->bdaddr, addr);

        if (hci_read_remote_name(this->socket, &(ii+i)->bdaddr, sizeof(name),
                                 name, 0) < 0) {

            strcpy(name, "[unknown]");
        }

        auto a = (ii + i)->bdaddr;
        array<uint8_t , 6> d = {0};
        copy(begin(a.b), end(a.b), begin(d));
        this->bluetoothDevices.push_back(BluetoothInfo{
            .address = d,
            .name = string(name),
        });

    }

    free(ii);
}

Bluetooth2::Bluetooth2() {
    this->devId = hci_get_route(nullptr);
    this->socket = hci_open_dev(this->devId);
    if (this->devId < 0 || this->socket < 0) {
        perror("opening socket");
        exit(1);
    }
}

Bluetooth2::~Bluetooth2() {
    close(this->socket);
    hci_close_dev(this->devId);
}

void Bluetooth2::displayDevices() {
    char addr[19] = {0};

    for (const BluetoothInfo& b : this->bluetoothDevices) {
//        bdaddr_t ba = bdaddr_t {.b = {b.address[0], b.address[1], b.address[Bt2], b.address[3], b.address[4], b.address[5]}};
        bdaddr_t ba;
        copy(begin(b.address), end(b.address),ba.b);
        ba2str(&ba, addr);
        cout<<addr<<" "<<b.name<<endl;
    }

}
