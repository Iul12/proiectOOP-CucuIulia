//
// Created by Iulia on 12/7/2023.
//
#include <SFML/Graphics.hpp>
#include "../headers/Piece.h"
#include "../headers/Queen.h"


Queen::Queen(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) :
        Piece(texture, position, width, height, color) {}

Queen::Queen(const Piece& other) : Piece(other) {}

Queen* Queen::clone() const {
    return new Queen(*this);
}

bool Queen::isValidMove(const sf::Vector2f& initialPosition, const sf::Vector2f& newPosition, const Board& board) const
{
    /// Verificați dacă poziția nouă este în interiorul tablei
    if (newPosition.x < 0 || newPosition.x >= static_cast<float>(board.getSquareSize()) * 8 ||
        newPosition.y < 0 || newPosition.y >= static_cast<float>(board.getSquareSize()) * 8) {
        return false;
    }

    /// Calculați diferența de poziție între poziția curentă și cea nouă
    float deltaX = newPosition.x - initialPosition.x;
    float deltaY = newPosition.y - initialPosition.y;

    /// Verificați dacă mișcarea este pe orizontală, verticală sau pe una dintre diagonale
    if ((deltaX == 0 && deltaY != 0) || (deltaX != 0 && deltaY == 0) ||
        (std::abs(deltaX) == std::abs(deltaY))) {
        return true;
    }

    return false;
}