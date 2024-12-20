#include <iostream>
#include <bitset>

class ARINC429 {
private:
    uint32_t data;

public:
    ARINC429(uint32_t input) : data(input) {}

    void parseMessage() {
        std::bitset<32> bits(data);
        std::cout << "Data bits: " << bits << std::endl;

        uint8_t label = (data >> 24) & 0xFF;
        uint8_t sdi = (data >> 22) & 0x03;
        uint8_t payload = (data >> 3) & 0x1FFFFF;
        uint8_t parity = data & 0x01;

        std::cout << "Label: " << (int)label << ", SDI: " << (int)sdi
                  << ", Payload: " << (int)payload << ", Parity: " << (int)parity << std::endl;
    }
};

int main() {
    ARINC429 message(0x1A5C789F);
    message.parseMessage();
    return 0;
}
