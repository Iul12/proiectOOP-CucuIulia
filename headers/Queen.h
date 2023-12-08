/**
 * Nume fisier: Queen.h
 * Autor: Cucu Iulia-Maria
 * Data: 8/12/2023
 */

#ifndef OOP_QUEEN_H
#define OOP_QUEEN_H

#include "Piece.h"
#include "Board.h"  // Assuming you have a Board class

/**
 * @class Queen
 * @brief Reprezintă o piesă de șah de tip Queen.
 */

class Queen : public Piece {
public:
    /**
     * @brief Constructor pentru clasa Queen.
     * @param texture Textura pentru piesa Queen.
     * @param position Poziția inițială a piesei Queen pe tablă.
     * @param width Lățimea piesei Queen.
     * @param height Înălțimea piesei Queen.
     * @param color Culorea piesei Queen (Albă sau Neagră).
     */
    Queen(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color);

    /**
     * @brief Constructor de conversie pentru clasa Queen.
     * @param other Obiectul Piece care va fi convertit la Queen.
     */
    explicit Queen(const Piece& other);

    /**
     * @brief Creează o clonă a piesei Queen.
     * @return O nouă instanță a piesei Queen cu atribute identice.
     */
    Queen* clone() const override;

    /**
     * @brief Verifică dacă o mutare este validă pentru piesa Queen.
     * @param initialPosition Poziția inițială a piesei Queen.
     * @param newPosition Noua poziție către care se mută piesa Queen.
     * @param board Tabla de șah pe care se află piesa Queen.
     * @return True dacă mutarea este validă, false altfel.
     */
    bool isValidMove(const sf::Vector2f& initialPosition, const sf::Vector2f& newPosition, const Board& board) const override;
};



#endif //OOP_QUEEN_H
