// buffer.h
#pragma once
#include <queue>
#include "types.h"
#include "mutex.h"

class BufferCircular {
public:
    std::queue<Packet> fifo;
    Mutex lock;
    int maxSize;

    void enqueue(Packet p);
    Packet dequeue();
};