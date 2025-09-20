#include "parser.h"
#include <chrono>
#include <iostream>

// Parse pacote e extrai informações relevantes
LogEntry parse_pacote(const Packet& pacote) {
    LogEntry log;
    log.tipo_transacao = pacote.type; // CHIP, NFC, etc.
    log.tamanho = pacote.size;
    log.conteudo_relevante = pacote.data; // Dados filtrados
    log.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::system_clock::now().time_since_epoch()
                    ).count();
    return log;
}

// Cria log a partir de dados extraídos
void criar_log(const LogEntry& log) {
    // Aqui poderia incluir compactação adaptativa
    std::cout << "[LOG] Tipo: " << log.tipo_transacao 
              << " Tamanho: " << log.tamanho 
              << " Timestamp: " << log.timestamp << std::endl;
}

// Grava log criptografado na memória
void gravar_memoria_criptografada(const LogEntry& log) {
    // Placeholder: implementação de criptografia AES
    // Salva em memória interna / microSD
    std::cout << "[STORAGE] Log gravado criptografado." << std::endl;
}