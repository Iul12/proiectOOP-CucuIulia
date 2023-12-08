//
// Created by Iulia on 12/7/2023.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#ifndef OOP_BOARD_H
#define OOP_BOARD_H

/**
 * @class Board
 * @brief Reprezintă o tablă de șah și piesele pe care aceasta le conține.
 */

class Piece;
class Board {
private:
    unsigned int boardSize; /// Dimensiunea totală a tablei de șah.
    unsigned int squareSize; /// Dimensiunea unei pătrățele pe tablă.
    sf::RectangleShape** squares; /// Matrice de dreptunghiuri reprezentând pătrățelele tablei.
    sf::Color white = sf::Color(255, 206, 160); /// Culoarea pătrățelelor albe.
    sf::Color black = sf::Color(140, 90, 40); /// Culoarea pătrățelelor negre.
    std::vector<std::unique_ptr<Piece>> pieces; /// Vector de pointeri la obiecte Piece, reprezentând piesele de pe tablă.


public:
    /**
     * @brief Constructor pentru clasa Board.
     * @param boardSize Dimensiunea totală a tablei de șah.
     * @param squareSize Dimensiunea unei pătrățele pe tablă.
     */
    explicit Board(int boardSize, int squareSize);

    /**
     * @brief Constructor de copiere pentru clasa Board.
     * @param board Obiectul Board care va fi copiat.
     */
    Board(const Board& board);

    /**
     * @brief Operator de atribuire pentru clasa Board.
     * @param board Obiectul Board de la care se copiază.
     * @return O referință la obiectul Board curent.
     */
    Board& operator=(const Board& board);

    /**
     * @brief Destructor pentru clasa Board.
     */
    ~Board();

    /**
     * @brief Desenează tabla de șah și piesele pe fereastra dată.
     * @param window Fereastra SFML pe care se desenează.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Obține dimensiunea unei pătrățele pe tablă.
     * @return Dimensiunea unei pătrățele pe tablă.
     */
    [[nodiscard]] int getSquareSize() const;
    ///const std::vector<Piece*>& getPieces() const [[nodiscard]];

    /**
     * @brief Suprascrie operatorul << pentru a afișa informații despre obiectul Board.
     * @param os Fluxul de ieșire în care se afișează informațiile.
     * @param board Obiectul Board care se afișează.
     * @return O referință la fluxul de ieșire.
     */
    friend std::ostream& operator<<(std::ostream& os, const Board& board);
};

#endif //OOP_BOARD_H
