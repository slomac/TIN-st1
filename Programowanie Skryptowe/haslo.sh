read -p "Podaj login oraz haslo: " login haslo
if [[ $login = "admin" && $haslo = "1234" ]]; then 
	echo "Zalogowano" 
else 
	echo "Bledny Login lub Haslo"

fi

