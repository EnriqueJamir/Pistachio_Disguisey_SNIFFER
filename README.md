===========================
         README.md
===========================

# Pistachio Disguisey, mais conhecido como "O Mestre Dos Disfarces", MITM Device

**Visão Geral**
Pistachio Disguisey é um dispositivo MITM USB/NFC modular e stealth, projetado para interceptar pacotes entre POS (que chamarei de M3) e computadores (M4) e armazenar logs criptografados para análise offline em M1 (Kali).

**Estrutura do Repositório**

- `firmware/` – Código do microcontrolador, modularizado por threads:
  1. `usb_sniffer/` – Captura pacotes vi USB entre POS e PC, com watchdog.
  2. `buffer_inteligente/` – FIFO thread-safe, prioriza pacotes críticos.
  3. `parser_logger/` – Analisa pacotes, extrai informações, compressão adaptativa.
  4. `stealth_health/` – Monitoramento stealth do dispositivo e reset automático.
  5. `transferencia_offline/` – Coleta logs de forma segura para M1 (máquina de "comando" - Kali)
  6. `main.cpp` – Integra todos os módulos e inicia as threads.

- `hardware/` – Blueprint físico, PCB, componentes, conexões entre M2, M3, M4.
- `docs/` – Documentação detalhada do fluxo de dados, buffers, criptografia, logs stealth.
- `scripts/` – Scripts auxiliares para análise offline, descriptografia e backup de logs.

**Funcionalidades GOD MODE**
- Stealth completo: sem LEDs, zero interferência na POS, pois aqui a intencao é passar despercebido!
- Multi-threaded pipeline: captura contínua de dados.
- Buffer inteligente: evita perda de pacotes críticos.
- Criptografia avançada: AES dinâmico por transação, hash SHA256, opcional RSA.
- Redundância: logs gravados em microSD + memória interna.
- Timestamp sub-milisegundo: análise detalhada de transações.
- Modularidade total: cada módulo independente, atualizável e testável.

**Uso**
1. Flashar firmware no microcontrolador (ESP32, STM32 ou Teensy) seguindo instruções no `firmware/`.
2. Conectar Pistachio entre POS (M3) e PC (M4).
3. Coletar logs periodicamente via scripts `scripts/` conectando M2 ao M1.
4. Analisar transações no Kali ou outro ambiente seguro.

**Notas**
- Dispositivo projetado para aprendizado e demonstração de MITM físico.
- Todos os fluxos, buffers e criptografia estão documentados para referência e testes.
- Estrutura do repositório segue padrões de modularidade e testes unitários para cada módulo.
- CONTEÚDO TOTALMENTE DESENVOLVIDO PARA FINS EDUCACIONAIS! Não me responsabilizo por atos cometidos por terceiros!
- AVISO:
- A PRATICA DE SNIFFING EM MÁQUINAS E/OU REDES DE TERCEIROS SEM AUTORIZAÇÃO É CRIME!