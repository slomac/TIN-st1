poprawne_haslo="admin123"
proby=3

while [ $proby -gt 0 ]; do
    read -sp "Podaj hasło: " haslo
    echo
    if [ "$haslo" == "$poprawne_haslo" ]; then
        echo "Zalogowano pomyślnie."
        while true; do
            read -p "Podaj nazwę podkatalogu: " katalog
            if [ -d "$katalog" ]; then
                echo "Ścieżka: $(realpath "$katalog")"
                echo "Zawartość:"
                ls -l "$katalog"
                break
            else
                echo "Katalog nie istnieje. Spróbuj ponownie."
            fi
        done
        exit 0
    else
        proby=$((proby - 1))
        echo "Błędny hasło. Pozostałe próby: $proby"
    fi
done

echo "Brak dostępu."
exit 1

