read -p "Podaj Wiek: " wiek
if (( wiek < 0 )); then 
	echo "blad"
elif (( wiek > 0 && wiek < 18 )); then 
	echo "niepelnoletni"
else
	echo "Dorosly"


fi
