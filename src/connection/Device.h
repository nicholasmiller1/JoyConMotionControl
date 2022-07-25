#pragma once
#include <string>
#include <atomic>
#include "hidapi.h"

using namespace std;

#define JOYCON_VENDOR 0x057e
#define JOYCON_LEFT 0x2006
#define JOYCON_RIGHT 0x2007

class Device {
public:
	Device(struct hid_device_info* deviceInfo);
	int getId();
	string getType();
	string getDescription();

private:
	int deviceId;
	string type;
	string description;

	static atomic<int> _uniqueIdCounter;
};