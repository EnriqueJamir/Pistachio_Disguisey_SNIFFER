===========================
         README.md
===========================

# Pistachio Disguisey, mais conhecido como "O Mestre Dos Disfarces", MITM Device


## Aviso Legal, Ético e Escopo de Uso

Este repositório contém material de pesquisa e design de *conceito* para análise de fluxos de comunicação entre dispositivos POS e sistemas de pagamento. **Em hipótese alguma este projeto deve ser usado para interceptar, fraudar ou coletar dados reais de cartões, contas ou usuários sem autorização explícita e documentada.**

O propósito deste repositório é **educacional** e **experimental** dentro de um ambiente de laboratório controlado, usando exclusivamente equipamentos e dados de teste fornecidos por bandeiras de cartão ou ambientes sandbox autorizados.

### Regras Obrigatórias Antes de Qualquer Experimento
1. **Autorização por escrito** — obtenha permissão explícita e documentada da organização dona do equipamento ou da infraestrutura onde o experimento ocorrerá.  
2. **Não use dados reais** — use apenas cartões de teste, números e credenciais fornecidas por ambientes/sandboxes oficiais (emuladores de adquirentes, números de cartão de teste das bandeiras).  
3. **Ambiente isolado** — execute experimentos somente em redes e dispositivos totalmente isolados do ambiente de produção e da Internet pública.  
4. **Conformidade legal** — verifique leis locais e políticas de privacidade antes de conduzir qualquer teste.  
5. **Proteção de dados** — trate todos os dados de teste com as mesmas práticas de segurança (criptografia em repouso e em trânsito, acesso restrito, logs mínimos).  
6. **Responsabilidade e divulgação** — se descobrir vulnerabilidades, adote políticas responsáveis de divulgação e remediação com os proprietários afetados.

### Diretrizes Seguras para Pesquisa (Alto Nível)
- **Objetivo do laboratório:** definir claramente hipóteses de pesquisa (ex.: estudar protocolos ISO 8583 em ambiente de teste, validar parsing de mensagens de teste, avaliar performance de buffer/armazenamento).
- **Hardware e software de teste:** utilizar apenas dispositivos de teste ou emulação; preferir simuladores de POS e adquirentes em sandbox.  
- **Dados de teste:** usar apenas PANs/números, CVV e credenciais de teste documentados publicamente pelas bandeiras (Visa, Mastercard, etc.).  
- **Rede isolada:** criar VLAN ou rede física dedicada sem rota para a Internet; documentar quem tem acesso.  
- **Procedimentos de experimento:** criar roteiros de teste, critérios de sucesso/falha e checklists de segurança antes de iniciar.  
- **Minimização de dados:** registre apenas o mínimo necessário para validar a hipótese; anonimizar ou descartar dados irrelevantes imediatamente.  
- **Auditoria e logs internos:** mantenha logs de quem realizou os testes, quando e com qual autorização; proteger esses logs com controles de acesso.  
- **Remoção segura:** ao finalizar experimentos, remova qualquer dado de teste e restaure configurações de rede/hardware para o estado seguro.

### Recursos e Leitura Recomendada
- Documentação oficial das bandeiras de pagamento (test card numbers / sandbox).  
- PCI DSS — requisitos aplicáveis à manipulação de dados de pagamento (para entender normas e limites).  
- Boas práticas de pesquisa em segurança: obtenção de consentimento, documentação de escopo, divulgação responsável.

### O que este repositório oferece (escopo real)
- **Arquitetura e modelos de software** (estruturas de módulos, buffers, formatação de logs) para fins educacionais.  
- **Simuladores e stubs** que permitem testar pipeline, compressão, criptografia e armazenamento sem tocar em dados reais.  
- **Documentação** sobre como montar um ambiente de testes seguro, planejar experimentos e cumprir requisitos legais e éticos.

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