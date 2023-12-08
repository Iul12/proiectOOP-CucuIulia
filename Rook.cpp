//
// Created by Iulia on 12/7/2023.
//

#include "Rook.h"
#include <SFML/Graphics.hpp>

Rook::Rook(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) :
        Piece(texture, position, width, height, color) {}

Rook::Rook(const Piece& other) : Piece(other) {}

Rook* Rook::clone() const {
    return new Rook(*this);
}

bool Rook::isValidMove(const sf::Vector2f& initialPosition, const sf::Vector2f& newPosition, const Board& board) const
{
    /// Verificați dacă poziția nouă este în interiorul tablei
    if (newPosition.x < 0 || newPosition.x >= static_cast<float>(board.getSquareSize()) * 8 ||
        newPosition.y < 0 || newPosition.y >= static_cast<float>(board.getSquareSize()) * 8) {
        return false;
    }

    /// Calculați diferența de poziție între poziția curentă și cea nouă
    float deltaX = newPosition.x - initialPosition.x;
    float deltaY = newPosition.y - initialPosition.y;

    /// Verificați dacă mișcarea este doar pe orizontală sau doar pe verticală
    if ((deltaX == 0 && deltaY != 0) || (deltaX != 0 && deltaY == 0)) {
        return true;
    }

    return false;
}
