#include <Bluetooth.h>
#include <iostream>

extern "C" {
#include "lcd1602.h"
}

using namespace std;

int main(int argc, char **argv)
{
    Bluetooth bt;
    bt.setup();
    auto devices = bt.inquiry();
    for (auto dev: *devices) {
        cout << dev.getName() << endl;
    }

    return 0;
}

