#include "buffer.h"

// Construtor
BufferCircular::BufferCircular(size_t size) : maxSize(size) {}

// Adiciona pacote ao buffer
void BufferCircular::enqueue(Packet p) {
    std::lock_guard<std::mutex> guard(lock);
    if(fifo.size() >= maxSize) {
        descartar_antigo();
    }
    fifo.push(p);
}

// Remove e retorna o pacote mais antigo
Packet BufferCircular::dequeue() {
    std::lock_guard<std::mutex> guard(lock);
    Packet p = fifo.front();
    fifo.pop();
    return p;
}

// Verifica se o buffer está cheio
bool BufferCircular::overflow() {
    std::lock_guard<std::mutex> guard(lock);
    return fifo.size() >= maxSize;
}

// Descarta pacotes antigos para evitar overflow
void BufferCircular::descartar_antigo() {
    if(!fifo.empty()) {
        fifo.pop();
    }
}