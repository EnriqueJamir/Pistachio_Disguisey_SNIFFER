// buffer.cpp
#include "buffer.h"

void BufferCircular::enqueue(Packet p) {
    lock.acquire();
    if(fifo.size() >= maxSize) fifo.pop_front();
    fifo.push_back(p);
    lock.release();
}

Packet BufferCircular::dequeue() {
    lock.acquire();
    Packet p = fifo.front();
    fifo.pop_front();
    lock.release();
    return p;
}