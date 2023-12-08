/**
 * Nume fisier: Bishop.h
 * Autor: Cucu Iulia-Maria
 * Data: 8/12/2023
 */

#ifndef OOP_BISHOP_H
#define OOP_BISHOP_H

#include "Piece.h"
#include "Board.h"

/**
 * @class Bishop
 * @brief Reprezintă o piesă de șah de tip Bishop.
 */

class Bishop : public Piece {
public:
    /**
     * @brief Constructor pentru clasa Bishop.
     * @param texture Textura pentru piesa Bishop.
     * @param position Poziția inițială a piesei Bishop pe tablă.
     * @param width Lățimea piesei Bishop.
     * @param height Înălțimea piesei Bishop.
     * @param color Culorea piesei Bishop (Albă sau Neagră).
     */
    Bishop(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color);

    /**
     * @brief Constructor de copiere pentru clasa Bishop.
     */
    explicit Bishop(const Piece& other);

    /**
     * @brief Creează o clonă a piesei Bishop.
     * @return O nouă instanță a piesei Bishop cu atribute identice.
     */
    Bishop* clone() const override;

    /**
     * @brief Verifică dacă o mutare este validă pentru piesa Bishop.
     * @param initialPosition Poziția inițială a piesei Bishop.
     * @param newPosition Noua poziție către care se mută piesa Bishop.
     * @param board Tabla de șah pe care se află piesa Bishop.
     * @return Adevărat dacă mutarea este validă, fals în caz contrar.
     */
    bool isValidMove(const sf::Vector2f& initialPosition, const sf::Vector2f& newPosition, const Board& board) const override;
};
#endif //OOP_BISHOP_H
