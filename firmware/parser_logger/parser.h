// parser.h
#pragma once
#include "types.h"
#include "buffer.h"

LogEntry parseTransaction(Packet packet);
int calculatePriority(Packet packet);
LogEntry compressLogAdaptive(LogEntry log);