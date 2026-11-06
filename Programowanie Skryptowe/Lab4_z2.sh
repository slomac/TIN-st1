oblicz_transmisje() {
	local rozmiar=$1
	local przepustowosc=$2
	local Mb=$(($rozmiar*8))
	local czas=$(($Mb/$przepustowosc))
	echo "przeslanie pliku o rozmiarze " $rozmiar " MB zajmie okolo" $czas "sekund"
}

read -p "Podaj rozmiar pliku w MB oraz przepustowosc w Mb/s: " rozmiar1 przepustowosc1
oblicz_transmisje $rozmiar1 $przepustowosc1
