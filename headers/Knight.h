/**
 * Nume fisier: Knight.h
 * Autor: Cucu Iulia-Maria
 * Data: 8/12/2023
 */

#ifndef OOP_KNIGHT_H
#define OOP_KNIGHT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Piece.h"

/**
 * @class Knight
 * @brief Reprezintă o piesă de șah de tip Knight.
 */

class Knight : public Piece {
public:
    /**
     * @brief Constructor pentru clasa Knight.
     * @param texture Textura pentru piesa Knight.
     * @param position Poziția inițială a piesei Knight pe tablă.
     * @param width Lățimea piesei Knight.
     * @param height Înălțimea piesei Knight.
     * @param color Culorea piesei Knight (Albă sau Neagră).
     */
    Knight(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color);

    /**
     * @brief Constructor de conversie pentru clasa Knight.
     * @param other Obiectul Piece care va fi convertit la Knight.
     */
    explicit Knight(const Piece& other);

    /**
     * @brief Creează o clonă a piesei Knight.
     * @return O nouă instanță a piesei Knight cu atribute identice.
     */
    Knight* clone() const override;

    /**
     * @brief Verifică dacă o mutare este validă pentru piesa Knight.
     * @param initialPosition Poziția inițială a piesei Knight.
     * @param newPosition Noua poziție către care se mută piesa Knight.
     * @param board Tabla de șah pe care se află piesa Knight.
     * @return True dacă mutarea este validă, false altfel.
     */
    bool isValidMove(const sf::Vector2f& initialPosition, const sf::Vector2f& newPosition, const Board& board) const override;
};

#endif //OOP_KNIGHT_H
