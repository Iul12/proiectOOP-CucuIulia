//
// Created by Iulia on 12/7/2023.
//
#include <SFML/Graphics.hpp>
#include "../headers/Piece.h"

Piece::Piece(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) :
        sprite(texture), position(position), isSelected(false), width(width), height(height), pieceColor(color) {
    sprite.setPosition(position);
}

Piece& Piece::operator=(const Piece& piece) {
    if (this != &piece) {
        sprite = piece.sprite;
        position = piece.position;
    }
    return *this;
}

void Piece::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Piece::move(const sf::Vector2f& newPosition) {
    position = newPosition;
    sprite.setPosition(position);
}

const sf::Vector2f& Piece::getPosition() const {
    return position;
}

void Piece::setIsSelected(bool selected) {
    isSelected = selected;
}

sf::Color Piece::getColor() const {
    return (pieceColor == white) ? sf::Color::White : sf::Color::Black;
}

std::ostream& operator<<(std::ostream& os, const Piece& piece) {
    os << "Piece at position: (" << piece.position.x << ", " << piece.position.y << ")" << std::endl;
    return os;
}

