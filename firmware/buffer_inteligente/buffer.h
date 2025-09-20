// Parte 2 – Thread 2: Buffer Inteligente
#ifndef BUFFER_H
#define BUFFER_H

#include "usb_sniffer.h"
#include <queue>
#include <mutex>

// Classe Buffer Circular Inteligente
class BufferCircular {
private:
    std::queue<Packet> fifo;
    std::mutex lock;
    size_t maxSize;

public:
    BufferCircular(size_t size);
    void enqueue(Packet p);
    Packet dequeue();
    bool overflow();
    void descartar_antigo(); // Remove pacotes antigos se necessário
};

#endif // BUFFER_H