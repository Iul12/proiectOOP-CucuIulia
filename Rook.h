//
// Created by Iulia on 12/7/2023.
//

#ifndef OOP_ROOK_H
#define OOP_ROOK_H

#include "Piece.h"
#include "Board.h"  // Assuming you have a Board class

/**
 * @class Rook
 * @brief Reprezintă o piesă de șah de tip Rook.
 */

class Rook : public Piece {
public:
    /**
     * @brief Constructor pentru clasa Rook.
     * @param texture Textura pentru piesa Rook.
     * @param position Poziția inițială a piesei Rook pe tablă.
     * @param width Lățimea piesei Rook.
     * @param height Înălțimea piesei Rook.
     * @param color Culorea piesei Rook (Albă sau Neagră).
     */
    Rook(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color);

    /**
     * @brief Constructor de conversie pentru clasa Rook.
     * @param other Obiectul Piece care va fi convertit la Rook.
     */
    explicit Rook(const Piece& other);

    /**
     * @brief Creează o clonă a piesei Rook.
     * @return O nouă instanță a piesei Rook cu atribute identice.
     */
    Rook* clone() const override;

    /**
     * @brief Verifică dacă o mutare este validă pentru piesa Rook.
     * @param initialPosition Poziția inițială a piesei Rook.
     * @param newPosition Noua poziție către care se mută piesa Rook.
     * @param board Tabla de șah pe care se află piesa Rook.
     * @return True dacă mutarea este validă, false altfel.
     */
    bool isValidMove(const sf::Vector2f& initialPosition, const sf::Vector2f& newPosition, const Board& board) const override;
};

#endif //OOP_ROOK_H
