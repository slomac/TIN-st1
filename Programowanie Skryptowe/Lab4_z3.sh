read -p "Podaj slowo do wyszukania: " slowo

laczna_liczba=0

for plik in *.txt; do
	if [ -f $plik ]; then 
		liczba_wierszy=$(grep -c "$slowo" "$plik")
	
		laczna_liczba=$((laczna_liczba + liczba_wierszy))
	fi

done 


echo "Laczna liczba wierszy zawierajacych slowo '$slowo' we wszystkich plikach: " $laczna_liczba
