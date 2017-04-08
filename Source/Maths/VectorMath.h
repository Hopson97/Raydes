#ifndef VECTORMATH_H_INCLUDED
#define VECTORMATH_H_INCLUDED

#include <SFML/System/Vector2.hpp>

namespace Maths
{
    template<typename T>
    float getLength (const sf::Vector2<T>& vect)
    {
        return std::sqrt(vect.x * vect.x +
                         vect.y * vect.y);
    }

    template<typename T>
    void normalise  (sf::Vector2<T>& vect)
    {
        auto length = getLength(vect);
        vect.x /= length;
        vect.y /= length;
    }
}

#endif // VECTORMATH_H_INCLUDED
