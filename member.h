#include <concepts>
#include <cstdint>


template <typename ValueType, bool IsArmed>
requires std::integral<ValueType>
class Adventurer
{
    public:
        using strength_t = uint32_t;
        bool isArmed = IsArmed;

        Adventurer()
        {
            static_assert(IsArmed == false);
            strength = 0;
            wealth = 0; 
        }

        Adventurer(int strength):strength(strength)
        {
            static_assert(IsArmed);
            wealth = 0;
        }

        
        strength_t getStrength()
        {
            static_assert(IsArmed);
            return strength;
        }

        template <ValueType, bool IsTrapped>
        void loot(Treasure<ValueType, IsTrapped>&& t)
        {
            if (t.isArmed())
            {
                if (strength == 0)
                {
                    return;
                }
                else
                {
                    strength /= 2;
                }
            }
            ValueType value = getLoot(t);
            wealth += value;
        }

        ValueType pay()
        {
            ValueType wealth_value = wealth;
            wealth = 0;
            return wealth_value;
        }

    private:
        strength_t strength; 
        ValueType wealth;
};

template <typename T> 
using Explorer = Adventurer<T, false>; 




template <typename ValueType, std::size_t CompletedExpeditions>
requires std::integral<ValueType>
class Veteran
{
    using strength_t = uint32_t;
    public:
        Veteran()
        {
            static_assert(CompletedExpeditions < 25);
            completedExpeditions = CompletedExpeditions;
            if (completedExpeditions == 0)
            {
                strength = 0;
            }
            else if (completedExpeditions == 1)
            {
                strength = 1;
            }
            else
            {
                int f[completedExpeditions + 1];
                f[0] = 0;
                f[1] = 1;
                for (int i = 2; i <= completedExpeditions; i++)
                {
                    f[i] = f[i-1] + f[i-2];
                }
                strength = f[completedExpeditions];
            }
            
            isArmed = true;
            wealth = 0;
        }

        template <ValueType, bool IsTrapped>
        void loot(Treasure<ValueType, IsTrapped>&& t)
        {
            if (t.isTrapped && strength == 0)
            {
                return;
            }
            ValueType value = getLoot(t);
            wealth += value;
        }
        bool isArmed;

        ValueType pay()
        {
            ValueType wealth_value = wealth;
            wealth = 0;
            return wealth_value;
        }

        strength_t getStrength()
        {
            return strength;
        }

    private:
        std::size_t completedExpeditions;
        strength_t strength;
        ValueType wealth;
        
};




