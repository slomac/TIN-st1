tablica=("plik1.txt" "plik2.txt" "plik3.txt" "plik4.txt" "plik5.txt")
touch raporty.txt
for plik in "${tablica[@]}"; do 
    echo "$plik" >> raporty.txt
done
echo "Raport zostal utworzony dnia: $(date)" >> raporty.txt
