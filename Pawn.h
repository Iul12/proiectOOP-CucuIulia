//
// Created by Iulia on 12/7/2023.
//

#ifndef OOP_PAWN_H
#define OOP_PAWN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Piece.h"

/**
 * @class Pawn
 * @brief Reprezintă o piesă de șah de tip Pawn.
 */

class Pawn : public Piece {
public:
    /**
     * @brief Constructor pentru clasa Pawn.
     * @param texture Textura pentru piesa Pawn.
     * @param position Poziția inițială a piesei Pawn pe tablă.
     * @param width Lățimea piesei Pawn.
     * @param height Înălțimea piesei Pawn.
     * @param color Culorea piesei Pawn (Albă sau Neagră).
     */
    Pawn(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color);

    /**
     * @brief Constructor de conversie pentru clasa Pawn.
     * @param other Obiectul Piece care va fi convertit la Pawn.
     */
    explicit Pawn(const Piece& other);

    /**
     * @brief Creează o clonă a piesei Pawn.
     * @return O nouă instanță a piesei Pawn cu atribute identice.
     */
    Pawn* clone() const override;

    /**
    * @brief Verifică dacă o mutare este validă pentru piesa Pawn.
    * @param initialPosition Poziția inițială a piesei Pawn.
    * @param newPosition Noua poziție către care se mută piesa Pawn.
    * @param board Tabla de șah pe care se află piesa Pawn.
    * @return True dacă mutarea este validă, false altfel.
    */
    bool isValidMove(const sf::Vector2f& initialPosition, const sf::Vector2f& newPosition, const Board& board) const override;
};

#endif //OOP_PAWN_H
