#!/bin/bash

KOD_KAT="$HOME/kopie"
mkdir -p "$KOD_KAT"

touch "$HOME/test1.txt" "$HOME/test2.txt" "$HOME/test3.txt"

cp "$HOME"/*.txt "$KOD_KAT"/ 2>/dev/null

LICZBA_PLIKOW=$(ls -1 "$KOD_KAT"/*.txt 2>/dev/null | wc -l)
AKTUALNA_DATA=$(date "+%Y-%m-%d %H:%M:%S")

echo "Data wykonania kopii: $AKTUALNA_DATA" > "$KOD_KAT/info.txt"
echo "Liczba skopiowanych plików: $((LICZBA_PLIKOW-1))" >> "$KOD_KAT/info.txt"