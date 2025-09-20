#!/usr/bin/env python3
# Descriptografa logs do Pistachio para análise offline

import os
from Crypto.Cipher import AES
import hashlib

def decrypt_log(file_path, key):
    with open(file_path, 'rb') as f:
        data = f.read()
    cipher = AES.new(key, AES.MODE_EAX, nonce=data[:16])
    decrypted = cipher.decrypt(data[16:])
    hash_check = hashlib.sha256(decrypted).hexdigest()
    return decrypted, hash_check

def main():
    key = b'minha_chave_AES_16bytes'
    logs_dir = './logs_encrypted/'
    for file in os.listdir(logs_dir):
        if file.endswith('.log'):
            decrypted, hash_check = decrypt_log(os.path.join(logs_dir, file), key)
            print(f'Arquivo: {file} | Hash: {hash_check}')
            # salvar ou processar o log

if __name__ == '__main__':
    main()