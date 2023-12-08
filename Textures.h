//
// Created by Iulia on 12/7/2023.
//

#ifndef OOP_TEXTURES_H
#define OOP_TEXTURES_H

#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @class Textures
 * @brief Gestionarea texturilor pentru piesele de șah.
 */

class Textures {
private:
    /**
     * @brief Încarcă o textură dintr-un fișier și actualizează lățimea și înălțimea acesteia.
     * @param file Calea către fișierul texturii.
     * @param width Referință la lățimea texturii.
     * @param height Referință la înălțimea texturii.
     * @return Textura încărcată.
     */
    static sf::Texture loadTexture(const std::string& file, float& width, float& height);

public:
    /// Texturi pentru piesele albe
    static sf::Texture whitePawn;
    static sf::Texture whiteKnight;
    static sf::Texture whiteBishop;
    static sf::Texture whiteRook;
    static sf::Texture whiteQueen;
    static sf::Texture whiteKing;

    /// Texturi pentru piesele negre
    static sf::Texture blackPawn;
    static sf::Texture blackKnight;
    static sf::Texture blackBishop;
    static sf::Texture blackRook;
    static sf::Texture blackQueen;
    static sf::Texture blackKing;

    /**
     * @brief Încarcă toate texturile pentru piesele de șah.
     */
    static void loadAllTextures();

    /**
     * @brief Suprascrie operatorul << pentru a afișa informații despre obiectul Textures.
     * @param os Fluxul de ieșire în care se afișează informațiile.
     * @param textures Obiectul Textures care se afișează.
     * @return O referință la fluxul de ieșire.
     */
    friend std::ostream& operator<<(std::ostream& os, const Textures&);
};


#endif //OOP_TEXTURES_H
