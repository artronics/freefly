#ifndef FREEFLY_BLUETOOTHADDRESS_H
#define FREEFLY_BLUETOOTHADDRESS_H


#include <cstdint>


// Bluetooth address class
class BluetoothAddress {

    union {

        struct {

            uint8_t	b1;
            uint8_t	b2;
            uint8_t	b3;
            uint8_t	b4;
            uint8_t	b5;
            uint8_t	b6;

        };

        uint8_t	b[6];

    };


public:

    // C-tor
    BluetoothAddress();
    // C-tor
    BluetoothAddress(const char* _buffer, unsigned int _size);
    // D-tor
    ~BluetoothAddress();

    // Set BT address
    void		set(const uint8_t _b1, const uint8_t _b2, const uint8_t _b3, const uint8_t _b4, const uint8_t _b5, const uint8_t _b6);
    // Set BT address
    void		set(const char* _buffer, unsigned int _size);

    // Get BT address
    const char*	get(char* _buffer, unsigned int _size) const;


};



#endif //FREEFLY_BLUETOOTHADDRESS_H
