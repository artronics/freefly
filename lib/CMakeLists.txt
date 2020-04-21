include_directories(include)
include_directories(/usr/local/include/linux) # This is workaround for include not found in remote. this dir contains files from rpi
add_library(bdev Bt2/Bluetooth2.cpp ../include/Bluetooth2.h)
add_library(Bluetooth
        Bluetooth/Bluetooth.cpp
        ../include/Bluetooth.h
        Bluetooth/BluetoothDevice.cpp
        include/BluetoothDevice.h
        Bluetooth/BluetoothAddress.cpp
        include/BluetoothAddress.h
        )
#target_link_libraries(Bluetooth bluetooth)
