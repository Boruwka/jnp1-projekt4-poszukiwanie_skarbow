/* Zdarzenia i ekspedycja – treasure_hunt.h
Każda ekspedycja składa się z szeregu zdarzeń. Dopuszczamy ich dwa rodzaje:
1. Uczestnik znajduje skarb. Wtedy uczestnik pozyskuje zawartość skarbu za pomocą
swojej metody loot() .
2. Spotkanie dwóch uczestników. Rezultat spotkania zależy od tego, czy są
uzbrojeni.
Jeśli żaden z nich nie jest uzbrojony, to rozchodzą się w swoje strony i
nic się nie dzieje.
Jeśli obaj są uzbrojeni to dochodzi do pojedynku. Wygrywa go uczestnik o
większej sile i zabiera on cały zebrany skarb przegranemu. W przypadku
remisu, gdy uczestnicy mają równe siły, nic się nie dzieje.
Jeśli tylko jeden z nich jest uzbrojony, to ten drugi się poddaje.
Uzbrojony uczestnik zabiera mu wówczas cały zebrany skarb.
Koncept strony spotkania
Należy zdefiniować koncept EncounterSide<T> . Spełnienie go przez typ T powinno
oznaczać jedno z poniższych:
Typ T reprezentuje poprawną instancję szablonu Treasure .
Typ T reprezentuje poprawnego uczestnika ekspedycji. Za taki przyjmujemy typ,
który spełnia wszystkie poniższe kryteria:
typ T udostępnia typ o nazwie strength_t ,
typ T ma statyczne pole isArmed , którego typ jest konwertowalny do
typu logicznego bool ,
typ T definiuje metodę pay() , która zwraca obiekt, będący poprawnym
typem wartości skarbu,
typ T definiuje metodę loot(treasure) , gdzie treasure jest obiektem
typu Treasure<V, B> dla V zgodnego z typem zwracanym przez metodę
pay() i B będącego dowolną wartością logiczną.
Zdarzenia
Zdarzenia powinny być reprezentowane poprzez typ Encounter<sideA, sideB> , zawierający
parę referencji na obiekty odpowiednio typu sideA i sideB . Oba typy powinny
spełniać koncept EncounterSide .
Ponadto należy udostępnić metodę run(encounter) , gdzie encounter jest obiektem typu
Encounter<A, B> , która implementuje przebiegi wszystkich możliwych spotkań opisanych
wyżej. Nie powinno być możliwe przeprowadzenie przy użyciu tej metody żadnego innego
rodzaju spotkania.
Ekspedycja
Należy zaimplementować funkcję expedition(e1, e2, ...) , która przyjmuje dowolną
liczbę zdarzeń i przeprowadza je po kolei (w kolejności występowania argumentów). */
