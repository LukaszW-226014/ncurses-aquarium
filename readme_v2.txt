Akwarium w ncurses - opis projektu

Cel:

Symulacja akwarium w terminalu. Wyświetlanie na ekranie zadanej ilość ryb, 
które będą poruszać się po akwarium.

Kluczowe informacje:

-Ryby będą należeć do różnych gatunków. Każdy gatunek dziedziczy po klasie głównej Ryba, 
rozszerzając o swoje charakterystyczne elementy (kształt, predkosć, prawdopodobieństwo zmiany kierunku).

-Akwarium będzie stanowić całą wielkość okna terminala.

-Ryby przy zetknięciu będą odbijać się od siebie - nie mogą się przenikać, a także będą odbijać się od ścianek akwarium.

Dodatkowe plany rozwoju:

-implementacja zdarzeń losowych (prawdopodobieństwo zależne od gatunku ryby) podczas zderzeń ryb:
	-rozmnażanie - wygenerowanie nowej ryby
	-śmierć - możliwość uśmiercenia jednej lub wszystkich zderzających się. 
	(*)zjadanie - jedna ryba zjada drugą i się powiększa

Mechanizmy synchronizacji:
1.Najpierw następuje ruch ryb(1 ryba = 1 wątek) - mutex + zmienna_warunkowa(czekanie na notyfikację) + atomic(licznik ryb)
2.Uruchomienie wątków wykrywaczy kolizji przez wątek sprawdzający liczbę ryb.
3.Skok do punktu 1 przez notyfikację ryb przez wątek sprawdzający liczbę wykonanych wątków wykrywaczy kolizji.

Synchronizacja wątków w akwarium będzię zaimplementowana w oparciu o mechanizmy:
	-std::mutex
	-std::condition_variable
	-std::atomic

 
 
