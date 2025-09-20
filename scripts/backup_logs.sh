#!/bin/bash
# Backup seguro de logs coletados do Pistachio

SRC_DIR="./logs_decrypted"
DEST_DIR="./backup_logs"

mkdir -p $DEST_DIR
cp -r $SRC_DIR/* $DEST_DIR
echo "Backup concluído para $DEST_DIR"