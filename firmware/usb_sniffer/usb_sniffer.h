// usb_sniffer.h
#pragma once
#include "buffer.h"
#include "types.h"

Packet captureUSB(Device src, Device dst);
bool detectErrorUSB(Packet p);
void resetStealth();
unsigned long getCurrentTime();