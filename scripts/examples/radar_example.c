#include <iostream>
#include <vector>
using namespace std;

class Radar {
private:
    float frequency;
    float range;

public:
    Radar(float freq, float rng) : frequency(freq), range(rng) {}

    void displayInfo() {
        cout << "Radar Frequency: " << frequency << " GHz" << endl;
        cout << "Radar Range: " << range << " km" << endl;
    }
};

int main() {
    Radar radarSystem(9.4, 120);
    radarSystem.displayInfo();
    return 0;
}
