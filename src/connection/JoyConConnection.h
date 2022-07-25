#pragma once
#include <string>
#include <unordered_map>
#include "Device.h"

using namespace std;

#define MAX_CONNECTIONS 10

class JoyConConnection {
public:
	// Attempts to connect to all available devices
	int connectAvailableDevices();

	// Gets the device ids of all currently connected devices
	// using the provided pointer to an array of given size.
	// Returns the actual number of devices found.
	int getAllConnectedDeviceIds(int* idArray, int size);

	// Gets a pointer to the device with the given device id
	Device* getDevice(int deviceId);

	// Disconnects all currently connected devices
	void disconnectAllDevices();

private:
	unordered_map<int, Device*> connectedDevices;
};