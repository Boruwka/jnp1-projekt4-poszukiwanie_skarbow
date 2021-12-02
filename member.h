/* Poszukiwacze przygód
Szablon klasy Adventurer<ValueType, IsArmed> powinien zależeć od dwóch parametrów:
ValueType – będącego typem wartości zbieranego skarbu, oraz IsArmed – będącego
wartością logiczną decydującą, czy poszukiwacz przygód jest uzbrojony. Utworzenie
instancji klasy Adventurer powinno być możliwe tylko dla tych ValueType , które są
poprawnymi typami wartości w szablonie Treasure .
Klasa Adventurer powinna udostępniać:
Adventurer() – konstruktor bezparametrowy, tylko dla nieuzbrojonego
poszukiwacza przygód;
Adventurer(strength) – konstruktor tworzący poszukiwacza przygód o podanej
sile, tylko dla uzbrojonego poszukiwacza przygód;
getStrength() – metoda zwracająca siłę poszukiwacza przygód, tylko dla
uzbrojonego poszukiwacza przygód;
isArmed – pole będące wartością logiczną, mówiące, czy poszukiwacz przygód
jest uzbrojony;
loot(&&treasure) – powoduje przejęcie danego skarbu przez poszukiwacza
przygód, zwiększa odpowiednio stan jego posiadania i opróżnia podany skarb;
skarby zawierające pułapkę mogą być przejęte tylko przez uzbrojonych
poszukiwaczy przygód i o niezerowej sile; przejęcie takiego skarbu zmniejsza
dwukrotnie siłę poszukiwacza przygód;
pay() – powoduje oddanie zebranych skarbów, czyli zwraca ich wartość i zeruje
stan posiadania poszukiwacza przygód.
Ponadto powinno być możliwe użycie skrótu Explorer<ValueType> oznaczającego
nieuzbrojonego poszukiwacza przygód o typie wartości ValueType .
Weterani
Szablon klasy Veteran<ValueType, CompletedExpeditions> powinien zależeć od dwóch
parametrów: ValueType – będącego typem wartości zbieranego skarbu, oraz
CompletedExpeditions – reprezentującego liczbę ukończonych ekspedycji w swojej
karierze (wartość ta powinna być typu std::size_t ). Utworzenie instancji klasy
Veteran powinno być możliwe tylko dla tych ValueType , które są poprawnymi typami
wartości w szablonie Treasure oraz tylko dla liczby ekspedycji mniejszej od 25 – na
ukończenie większej liczby ekspedycji nie starczyłoby nikomu czasu.
Klasa Veteran powinna udostępniać:
Veteran() – konstruktor bezparametrowy,
isArmed – analogicznie jak u poszukiwacza przygód, ale weterani, znając
niebezpieczeństwa ekspedycji, zawsze są uzbrojeni,
loot(&&treasure) – analogicznie jak u poszukiwacza przygód, ale doświadczenie
weteranów w rozbrajaniu pułapek chroni ich przed utratą siły,
pay() – analogicznie jak u poszukiwacza przygód,
getStrength() – analogicznie jak u poszukiwacza przygód.
Siła weterana zależy od liczby ukończonych przez niego ekspedycji – jeśli ukończył ich
n to jego siła równa jest n -tej liczbie Fibonacciego (dla n = 0 siła wynosi 0 , a
dla n = 1 siła wynosi 1 ).
Pozostałe wymagania
Siła powinna być 32-bitową liczbą całkowitą bez znaku i być dostępna jako składowa
publiczna strength_t każdej z powyższych klas.
Każdy uczestnik rozpoczyna ekspedycję bez żadnych skarbów. */
