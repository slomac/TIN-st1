data=$(date +"%d-%m-%Y") 
read -p "podaj nazwe katalogu: " katalog
if [ -d $katalog ]; then
	echo "katalog o nazwie $katalog istnieje"
else
	mkdir "$katalog"
	touch "$katalog/info.txt"
	echo "utworzono katalog $katalog dnia $data" > $katalog/info.txt 
	
fi
