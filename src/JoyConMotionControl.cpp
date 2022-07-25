#include <iostream>
#include "connection/JoyConConnection.h"

int main() {
    std::cout << "Starting program..." << std::endl;

    JoyConConnection connectionManager;

    int numDevices = connectionManager.connectAvailableDevices();

    // TODO: convert to array for dynamic sizing
    int connectedIds[MAX_CONNECTIONS];
    connectionManager.getAllConnectedDeviceIds(connectedIds, MAX_CONNECTIONS);

    std::cout << "Connected device IDs: ";
    for (int i = 0; i < numDevices; i++) {
        std::cout << connectedIds[i] << ", ";
    }
    std::cout << std::endl;

    if (numDevices == 0) {
        std::cout << "No connected devices" << std::endl;
    }
    else {
        Device* firstDevice = connectionManager.getDevice(connectedIds[0]);
        std::cout << "First Connected Device: " << std::endl;
        std::cout << "Device Id: " << firstDevice->getId() << std::endl;
        std::cout << "Device Type: " << firstDevice->getType() << std::endl;
        std::cout << "Device Description: " << firstDevice->getDescription() << std::endl;
    }
}
