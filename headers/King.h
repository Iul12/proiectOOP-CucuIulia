/**
 * Nume fisier: King.h
 * Autor: Cucu Iulia-Maria
 * Data: 8/12/2023
 */

#ifndef OOP_KING_H
#define OOP_KING_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Piece.h"

/**
 * @class King
 * @brief Reprezintă o piesă de șah de tip King.
 */

class King : public Piece {
public:
    /**
     * @brief Constructor pentru clasa King.
     * @param texture Textura pentru piesa King.
     * @param position Poziția inițială a piesei King pe tablă.
     * @param width Lățimea piesei King.
     * @param height Înălțimea piesei King.
     * @param color Culorea piesei King (Albă sau Neagră).
     */
    King(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color);

    /**
     * @brief Constructor de conversie pentru clasa King.
     * @param other Obiectul Piece care va fi convertit la King.
     */
    explicit King(const Piece& other);

    /**
     * @brief Creează o clonă a piesei King.
     * @return O nouă instanță a piesei King cu atribute identice.
     */
    King* clone() const override;

    /**
     * @brief Verifică dacă o mutare este validă pentru piesa King.
     * @param initialPosition Poziția inițială a piesei King.
     * @param newPosition Noua poziție către care se mută piesa King.
     * @param board Tabla de șah pe care se poate afla piesa King.
     * @return True dacă mutarea este validă, false altfel.
     */
    bool isValidMove(const sf::Vector2f& initialPosition, const sf::Vector2f& newPosition, const Board& board) const override;
};

#endif //OOP_KING_H
