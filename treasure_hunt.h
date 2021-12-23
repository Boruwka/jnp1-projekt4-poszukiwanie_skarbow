#include "treasure.h"
#include "member.h"

/* SKOPIOWANE OD KOGOŚ!!! */
template<typename T>
struct IsTreasure : std::false_type {
};

template<std::integral ValueType, bool IsTrapped>
struct IsTreasure<Treasure<ValueType, IsTrapped>> : std::true_type {
};
template<typename T>
concept TreasureType = IsTreasure<T>::value;

template<typename T>
concept MemberType = requires(T t) {
    typename T::strength_t;
    { []() constexpr { return T::isArmed; }() };
    { t.isArmed } -> std::convertible_to<bool>;
    { t.pay() } -> std::integral;
    t.loot(std::declval<Treasure<decltype(t.pay()), true>>());
    t.loot(std::declval<Treasure<decltype(t.pay()), false>>());
};

template<typename T>
concept EncounterSide = TreasureType<T> || MemberType<T>;


template<EncounterSide sideA, EncounterSide sideB>
class Encounter {
    public: 
        sideA &a;
        sideB &b;
        
};


/* KONIEC SKOPIOWANEGO */
 
void run(Encounter encounter)
{
    if (std::is_same(Treasure<>, encounter.a)
    {
        encounter.b.loot();
    }    
    else if (std::is_same(Treasure<>, encounter.b)
    {
        encounter.a.loot();
    }
    else
    {
        if constexpr(!encounter.a::isArmed && !encounter.b::isArmed)
        {
            return;
        }
        else if constexpr(!encounter.a::isArmed)
        {
            encounter.a.wealth += encounter.b.pay();
        }
        else if constexpr(!encounter.b::isArmed)
        {
            encounter.b.wealth += encounter.a.pay();
        }
        else 
        {
            if (encounter.a.getStrength > encounter.b.getStrength)
            {
                encounter.a.wealth += encounter.b.pay();
            }
            else if (encounter.a.getStrength < encounter.b.getStrength)
            {
                encounter.b.wealth += encounter.a.pay();
            }
        }
    }
}




void expedition()
{
    return;
}
 
template <typename... Types>
void expedition(Encounter e1, Types... e2)
{
    run(e1);
    expedition(var2...);
}



