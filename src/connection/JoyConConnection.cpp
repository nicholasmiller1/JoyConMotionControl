#include "JoyConConnection.h"
#include <unordered_map>

int JoyConConnection::connectAvailableDevices() {
	if (connectedDevices.size() > 0) {
		disconnectAllDevices();
	}

	struct hid_device_info *devices, *current_device;

	int res = hid_init();

	devices = hid_enumerate(JOYCON_VENDOR, 0x0);
	current_device = devices;
	while (current_device) {
		if (current_device->vendor_id == JOYCON_VENDOR) {
			if (current_device->product_id == JOYCON_LEFT || current_device->product_id == JOYCON_RIGHT) {
				Device* newDevice = new Device(current_device);
				connectedDevices.emplace(newDevice->getId(), newDevice);
			}
		}

		current_device = current_device->next;
	}
	
	hid_free_enumeration(devices);

	return (int) connectedDevices.size();
}

int JoyConConnection::getAllConnectedDeviceIds(int* idArray, int size) {
	int i = 0;
	for (pair<int, Device*> deviceMapping : connectedDevices) {
		if (i >= size) {
			break;
		}

		idArray[i] = deviceMapping.first;
		i++;
	}
	return i;
}

Device* JoyConConnection::getDevice(int deviceId) {
	auto iter = connectedDevices.find(deviceId);
	if (iter != connectedDevices.end()) {
		return iter->second;
	}
	return nullptr;
}

void JoyConConnection::disconnectAllDevices() {
	for (pair<int, Device*> deviceMapping : connectedDevices) {
		delete deviceMapping.second;
	}

	connectedDevices.clear();

	int res = hid_exit();
}