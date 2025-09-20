// usb_sniffer.cpp
// Thread 1: USB Sniffer Core
#include "usb_sniffer.h"

void Thread_MCU_USB() {
    while(true) {
        Packet usbPacket = captureUSB(M3, M4);          // Captura pacotes USB M3 <-> M4
        usbPacket.timestamp = getCurrentTime();         // Timestamp inicial
        if(detectErrorUSB(usbPacket)) resetStealth();  // Watchdog de falha
        BufferCircular.enqueue(usbPacket);              // Passa para Thread 2
    }
}