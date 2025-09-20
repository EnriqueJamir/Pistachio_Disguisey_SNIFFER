// parser.cpp
#include "parser.h"
#include "buffer.h"

void Thread_Sniffer_Parser() {
    while(true) {
        Packet packet = BufferCircular.dequeue();
        if(packet.type == CHIP || packet.type == NFC) {
            LogEntry log = parseTransaction(packet);
            log.timestampProcess = getCurrentTime();
            log.priority = calculatePriority(packet);
            log = compressLogAdaptive(log);
            BufferCircularLogs.enqueue(log);
        }
    }
}

LogEntry parseTransaction(Packet packet) {
    LogEntry log;
    // lógica de parsing Track1/2, CVV, Banco, Nome
    return log;
}