#include "Device.h"
#include <string>
#include <atomic>
#include "hidapi.h"

using namespace std;

atomic<int> Device::_uniqueIdCounter = 0;

Device::Device(struct hid_device_info* deviceInfo) {
	if (deviceInfo->product_id == JOYCON_LEFT) {
		this->type = string("NintendoJoyCon");
		this->description = string("Left");
	}
	else if (deviceInfo->product_id == JOYCON_LEFT) {
		this->type = string("NintendoJoyCon");
		this->description = string("Right");
	}

	this->deviceId = _uniqueIdCounter++;
}

int Device::getId() {
	return deviceId;
}

string Device::getType() {
	return type;
}

string Device::getDescription() {
	return description;
}