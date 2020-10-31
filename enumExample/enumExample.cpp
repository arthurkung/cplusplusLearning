#include <iostream>
/* 
Enum types comparisons are deprecated in C++20
so we are running this in C++17
*/
// enum type fruit
enum Fruit
{
    fruit_apple = -1,
    fruit_orange,
    fruit_banana // fruit_banana is placed in the same scope as Fruit
};

// enum type player
enum Player
{
    player_one = 1,
    player_two = -1
};

auto switchPlayer(Player player) {
    return static_cast<Player>(player * -1);
}

void printPlayer(Player player) {
    switch (player)
    {
    case player_one:
        std::cout << "player one\n";
        break;
    case player_two:
        std::cout << "player two\n";
        break;
    default:
        std::cout << "undefined player\n";
        break;

    }
}
// enum class color
enum class Color // "enum class" defines this as a scoped enumeration instead of a standard enumeration
{
    black =-1, // black is inside the scope of Color
    white = 1
};

auto switchColor(Color color) {
    int color_id;
    color_id = static_cast<int>(color);
    return static_cast<Color>(color_id * -1);
}

void printColor(Color color) {
    switch (color)
    {
        case Color::black:
            std::cout << "black\n";
            break;
        case Color::white:
            std::cout << "white\n";
            break;
        default:
            std::cout << "undefined color\n";
            break;

    }
}

int main()
{
    /*enum types*/
    Player player{ player_one }; // Player and player_one can be accessed in the same scope (no prefix needed)
    Fruit fruit{ fruit_banana }; // Fruit and fruit_banana can be accessed in the same scope (no prefix needed)

    /*enum types can be compared*/
    if (player == fruit) // The compiler will compare a and b as integers
        std::cout << "player and fruit are equal\n"; // and find they are equal!
    else
        std::cout << "player and fruit are not equal\n";

    /*print player */
    std::cout << "player is now: ";
    printPlayer(player);

    // perfrom player switch
    player = switchPlayer(player);
    std::cout << "after the switch, the player is now: "; 
    printPlayer(player);

    /*enum classes*/
    Color color{ Color::black };
    std::cout << "the color is now: ";
    printColor(color);

    // perfrom color switch
    color = switchColor(color);
    std::cout << "after the color switch, the color is now: ";
    printColor(color);


    return 0;
}