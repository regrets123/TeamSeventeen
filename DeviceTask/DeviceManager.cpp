#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Device {
    int id;
    string name;
    float value;
};

class DeviceManager {
private:
    vector<Device> devices;
public:
    void addDevice(Device d) {
        devices.push_back(d);
    }
    void removeDevice(int id) {
        for (int i = 0; i < devices.size(); i++) {
            if (devices[i].id == id) {
                devices.erase(devices.begin()+i);
            }
        }
    }
    void printAll() const {
        for (const auto& d : devices) {
            cout << d.id << " - " << d.name << " (" << d.value << ")" << endl;
        }
    }
};
//testing
int main() {
    DeviceManager manager;
    Device d1 = { 1, "TempSensor", 21.4 };
    manager.addDevice(d1);
    manager.printAll();
    // manager.removeDevice(1);
}
