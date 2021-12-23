#include <concepts>

template<typename T>
concept integral = std::is_integral<T>::value;


template <integral ValueType, bool IsTrapped>
class Treasure
{
    public:
        bool isTrapped;
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

template <typename T> 
using SafeTreasure = Treasure<T, false>;

template<typename T>
using TrappedTreasure = Treasure<T, true>;

