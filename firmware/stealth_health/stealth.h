// Parte 4 – Thread 4: Stealth & Health Check
#ifndef STEALTH_H
#define STEALTH_H

#include <cstdint>

// Funções de monitoramento stealth
void verificar_memoria();
void verificar_buffers();
void verificar_consumo_energia();
void reiniciar_modulo_afetado();

// Loop principal stealth
void loop_stealth();

#endif // STEALTH_H