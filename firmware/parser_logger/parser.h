// Parte 3 – Thread 3: Parser & Logger
#ifndef PARSER_H
#define PARSER_H

#include "../buffer_inteligente/buffer.h"
#include <string>
#include <vector>

// Estrutura de log
struct LogEntry {
    std::string tipo_transacao;
    size_t tamanho;
    std::string conteudo_relevante;
    uint64_t timestamp;
};

// Funções principais
LogEntry parse_pacote(const Packet& pacote);
void criar_log(const LogEntry& log);
void gravar_memoria_criptografada(const LogEntry& log);

#endif // PARSER_H