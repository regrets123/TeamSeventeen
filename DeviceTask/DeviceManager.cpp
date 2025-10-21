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

    void findDevice(int id){
        for (int i = 0; i < devices.size(); i++)
        {
            if (devices[i].id == id)
            {
                cout << "Found device with name" << devices[i].name << '\n'
                     << " and value" << devices[i].value << '\n';
                return;
            }
        }
        cout << "Device not found!" << '\n';
    }

    void printAll() const {
        for (const auto& d : devices) {
            cout << d.id << " - " << d.name << " (" << d.value << ")" << endl;
        }
    }

    void updateValue() {
        float v;
        int id;
        bool check = false;
        std::cout << "Enter sensor ID :";
        std::cin >> id;
        for (auto& d : devices) {
            if (id == d.id) {
                std::cout << "Enter new sensor value :";
                std::cin >> v;
                d.value = v;
                check = true;
            }
        }
        if (check == false) {
            std::cout << "No such sensor.\n";
        }
    }
};
//testing
int main() {
    DeviceManager manager;
    Device d1 = {1, "TempSensor", 21.4};
    Device d2 = {2, "HeatSensor", 87.6};
    manager.addDevice(d1);
    manager.addDevice(d2);
    manager.findDevice(1);
    manager.printAll();
    //manager.updateValue();
    manager.printAll();
    // manager.removeDevice(1);
}
