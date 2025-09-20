// Parte 1 – Thread 1: USB Sniffer Core
#ifndef USB_SNIFFER_H
#define USB_SNIFFER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t *data;
    uint16_t length;
    uint64_t timestamp;
} Packet;

// Inicializa o módulo USB Sniffer
void initUSBSniffer();

// Captura pacotes USB M3 <-> M4
Packet captureUSB();

// Watchdog: detecta falhas no USB e reinicia se necessário
void resetStealthIfError(Packet p);

#endif // USB_SNIFFER_H