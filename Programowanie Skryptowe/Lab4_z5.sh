#poprawiony skrypt( z opisanymi poprawionymi bledami ) 
suma() {
	#dodano local przy deklaracji zmiennych w funkcji
    local n=$1
    local wynik=1
    
    # Poprawiono składnię pętli oraz zakres (<= n)
    for ((i=1; i<=n; i++)); do
        wynik=$((wynik + i))
    done

    echo "$wynik"
}

read -p "podaj n: " n

# Poprawiono przekazanie zmiennej ($n zamiast n)
wynik=$(suma $n)

if [ "$wynik" -gt 0 ]; then
    echo "Suma: $wynik"
else
    echo "Błąd obliczeń"
fi
#Wyniki dla: n=1 => 2, n=4 => 11, n=10 => 56
