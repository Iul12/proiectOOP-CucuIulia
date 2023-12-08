//
// Created by Iulia on 12/7/2023.
//

#include "../headers/Textures.h"

sf::Texture Textures::whitePawn;
sf::Texture Textures::whiteKnight;
sf::Texture Textures::whiteBishop;
sf::Texture Textures::whiteRook;
sf::Texture Textures::whiteQueen;
sf::Texture Textures::whiteKing;
sf::Texture Textures::blackPawn;
sf::Texture Textures::blackKnight;
sf::Texture Textures::blackBishop;
sf::Texture Textures::blackRook;
sf::Texture Textures::blackQueen;
sf::Texture Textures::blackKing;

sf::Texture Textures::loadTexture(const std::string& file, float& width, float& height)
{
    sf::Texture texture;
    if (!texture.loadFromFile(file)) {
        std::cout << "Error loading texture: " << file << std::endl;
    } else {
        width = static_cast<float>(texture.getSize().x);
        height = static_cast<float>(texture.getSize().y);
    }
    return texture;
}

void Textures::loadAllTextures() {
    float width, height;
    whitePawn = loadTexture("C:/images/white_pawn.png", width, height);
    whiteKnight = loadTexture("C:/images/white_knight.png", width, height);
    whiteBishop = loadTexture("C:/images/white_bishop.png", width, height);
    whiteRook = loadTexture("C:/images/white_rook.png", width, height);
    whiteQueen = loadTexture("C:/images/white_queen.png", width, height);
    whiteKing = loadTexture("C:/images/white_king.png", width, height);

    blackPawn = loadTexture("C:/images/black_pawn.png", width, height);
    blackKnight = loadTexture("C:/images/black_knight.png", width, height);
    blackBishop = loadTexture("C:/images/black_bishop.png", width, height);
    blackRook = loadTexture("C:/images/black_rook.png", width, height);
    blackQueen = loadTexture("C:/images/black_queen.png", width, height);
    blackKing = loadTexture("C:/images/black_king.png", width, height);
}

std::ostream& operator<<(std::ostream& os, const Textures&) {
    os << "Textures information" << std::endl;
    return os;
}
