read -p "Podaj plik i slowo: " plik slowo
if [ -f $plik ]; then
	if grep -q "$slowo" "$plik"; then 
		echo "znaleziono"
	else 
		echo "Nie Znaleziono"

fi

else 
	echo " $plik does not exist "
fi
