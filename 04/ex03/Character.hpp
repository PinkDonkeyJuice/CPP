#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class Character
{
private:

public:
    Character();
    Character(const  Character &copy);
    ~Character();

    Character &operator=(const  Character &src);
};

#endif