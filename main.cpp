#include <iostream>
#include <assert.h>
using namespace std;

    char nibble_to_hex(uint8_t i)
    {
        assert(0x0 <= i && i <= 0xf);
        char symbols[17]= "0123456789abcdef";
        return symbols[i];
    }


     void print_in_hex(uint8_t byte)
    {
        cout<<nibble_to_hex(byte>>4)
        <<nibble_to_hex(byte & 0x0f);
    }


    const uint8_t*
    as_bytes(const void* data)
    {
    return reinterpret_cast<const uint8_t*>(data);
    }


    void print_in_hex(const void* data, size_t size)
    {
        const uint8_t* bytes = as_bytes(data);
        for (size_t i = 0; i < size; i++) {
        print_in_hex(bytes[i]);
        if ((i + 1) % 16 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
    }

    char
    bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}

    void
    print_in_binary(uint8_t byte) {
    for (uint8_t bit = 7; bit > 0; bit--) {
        cout << bit_digit(byte, bit);
        if (bit==0)
            return;
    }
}

    void
    print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);
        if ((i + 1) % 4 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}

    calc (uint16_t op1, char operat, uint16_t op2)
    {
            print_in_hex(&op1, sizeof(op1));
            cout<<operat ;
            print_in_hex(&op2, sizeof(op2));
            cout<<'=';
            uint16_t res;
            if (res== '&' )
            {
                res=op1 & op2;
            }
            if (res== '|' )
            {
                res=op1 | op2;
            }
            if (res== '^' )
            {
                res=op1 ^ op2;
            }
            print_in_hex(res);

            print_in_binary(&op1, sizeof(op1));
            cout<<operat ;
            print_in_binary(&op2, sizeof(op2));
            cout<<'=';

            if (res== '&' )
            {
                res=op1 & op2;
            }
            if (res== '|' )
            {
                res=op1 | op2;
            }
            if (res== '^' )
            {
                res=op1 ^ op2;
            }
            print_in_binary(res);
    }


int main()
{
    assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '9');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    assert(nibble_to_hex(0xf) == 'f');
    uint8_t u8 = 0x42;
    cout << "u8 bytes: ";
    print_in_hex(&u8, sizeof(u8));
    cout << '\n';
    uint16_t u16 = 0x42;
    cout << "u16 bytes: ";
    print_in_hex(&u16, sizeof(u16));
    cout << '\n';
    uint32_t u32 = 0x42;
    cout << "u32 bytes: ";
    print_in_hex(&u32, sizeof(u32));
    cout << '\n';
    print_in_binary(15);
    calc(1025,'&',127);
}
