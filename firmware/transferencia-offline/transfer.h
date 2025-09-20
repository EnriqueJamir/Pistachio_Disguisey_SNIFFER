// Parte 5 – Thread 5: Transferência Offline / M1
#ifndef TRANSFER_H
#define TRANSFER_H

#include <string>

// Conecta ao M1 para coletar logs
void conectar_usb(const std::string& dispositivo);

// Descriptografa logs antes da transferência
void descriptografar_logs();

// Transfere logs para M1
void transferir_para_M1();

// Mantém backup local dos logs
void manter_backup_local();

// Loop principal para coleta offline
void loop_transfer_offline();

#endif // TRANSFER_H