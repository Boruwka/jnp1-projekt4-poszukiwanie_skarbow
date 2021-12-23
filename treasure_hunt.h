#include "treasure.h"
#include "member.h"


template<typename T>
concept hasStrengthType = T::strengh_t;

template<typename T>
concept hasIsArmed = requires (T t) {t.isArmed; };

template<typename T>
concept hasFuncPay = requires(T t) {
      { t.pay() } -> integral;
  };

template<typename T, bool B, Treasure<integral auto, B> u>
concept hasFuncLoot = requires(T t) {
    { t.loot(u) };    
};



template<typename T, bool B, Treasure<integral auto, B> u >
concept Member = hasStrengthType<T> && hasIsArmed<T> && hasFuncPay<T> && hasFuncLoot<T, B, u>;

template<typename T, bool B, Treasure<integral auto, B> u, typename ValueType>
concept EncounterSide = Member<T, B, u> || std::same_as<T, Treasure<ValueType, B> >;


template Encounter<EncounterSide& sideA, EncounterSide& sideB>
class Encounter
{
    public:
        sideA a;
        sideB b;
};
 
void run(Encounter encounter)
{
    if (std::isSame(Treasure<>, encounter.a)
    {
        encounter.b.loot();
    }    
    else if (std::isSame(Treasure<>, encounter.b)
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



