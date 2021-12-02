template <typename ValueType, bool IsTrapped>
requires std::integral<ValueType> 
// nie wiem na razie, jak zrobić te skróty  
class Treasure()
{
    public:
        bool IsTrapped;
        Treasure(ValueType value):value(value)
        {
            isTrapped = IsTrapped;
        }

        ValueType evaluate()
        {
            return value;
        }

        ValueType getLoot()
        {
            ValueType former_value = value;
            value = 0;
            return former_value;
        }

    private: 
        ValueType value;
};

/* Skarby – treasure.h

Szablon klasy Treasure<ValueType, IsTrapped> powinien zależeć od dwóch parametrów:
ValueType – reprezentującego typ wartości skarbu, oraz IsTrapped – będącego
wartością logiczną wskazującą, czy skarb jest zabezpieczony pułapką. Nie powinno być
możliwe stworzenie instancji klasy Treasure z typem wartości innym niż typ
całkowitoliczbowy, czyli np. int , int16_t , unsigned short int itd.
Klasa powinna udostępniać:
Treasure(value) – konstruktor tworzący skarb o podanej wartości,
evaluate() – metoda zwracająca aktualną wartość skarbu,
getLoot() – metoda zwracająca aktualną wartość skarbu i opróżniająca go
(wartość skarbu staje się zerowa),
IsTrapped – pole będące wartością logiczną, mówiące, czy skarb zawiera
pułapkę.
Ponadto powinno być możliwe użycie skrótów:
SafeTreasure<ValueType> – reprezentuje skarb bez pułapki o typie wartości
ValueType ,
TrappedTreasure<ValueType> – reprezentuje skarb z pułapką o typie wartości
ValueType . */
