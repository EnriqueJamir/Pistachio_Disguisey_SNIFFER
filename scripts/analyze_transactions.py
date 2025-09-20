#!/usr/bin/env python3
# Reconstrói transações do Pistachio e gera relatório

import json
import os

def analyze_log(file_path):
    with open(file_path, 'r') as f:
        logs = json.load(f)
    for log in logs:
        print(f"Transação: {log['tipo_transacao']} | Valor: {log.get('valor', 'N/A')} | Timestamp: {log['timestamp']}")

def main():
    decrypted_dir = './logs_decrypted/'
    for file in os.listdir(decrypted_dir):
        if file.endswith('.json'):
            analyze_log(os.path.join(decrypted_dir, file))

if __name__ == '__main__':
    main()