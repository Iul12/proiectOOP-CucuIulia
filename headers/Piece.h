/**
 * Nume fisier: Piece.h
 * Autor: Cucu Iulia-Maria
 * Data: 8/12/2023
 */

#ifndef OOP_PIECE_H
#define OOP_PIECE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Game.h"
#include "Board.h"

/**
 * @enum Color
 * @brief Enumerație pentru culorile pieselor de șah.
 */
enum Color { white, black };

/**
 * @class Piece
 * @brief Reprezintă o piesă de șah abstractă.
 */

class Piece {
private:
    sf::Sprite sprite; /// Sprite-ul asociat piesei.
    sf::Vector2f position; /// Poziția piesei pe tablă.
    Color pieceColor; /// Culorea piesei (Albă sau Neagră).


protected:
    bool isSelected; /// Indicator dacă piesa este selectată sau nu.
    float width; /// Lățimea piesei.
    float height; /// Înălțimea piesei.

public:
    /**
     * @brief Constructor pentru clasa Piece.
     * @param texture Textura piesei.
     * @param position Poziția inițială a piesei pe tablă.
     * @param width Lățimea piesei.
     * @param height Înălțimea piesei.
     * @param color Culorea piesei (Albă sau Neagră).
     */
    explicit Piece(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color);

    /**
     * @brief Constructor de copiere implicit pentru clasa Piece.
     * @param other Obiectul Piece care va fi copiat.
     */
    Piece(const Piece& other) = default;

    /**
     * @brief Operator de atribuire implicit pentru clasa Piece.
     * @param piece Obiectul Piece de la care se copiază.
     * @return O referință la obiectul Piece curent.
     */
    Piece& operator=(const Piece& piece);

    /**
     * @brief Destructor virtual pentru clasa Piece.
     */
    virtual ~Piece() = default;

    /**
     * @brief Creează o clonă a piesei.
     * @return O nouă instanță a piesei cu atribute identice.
     */
    virtual Piece* clone() const = 0;

    /**
     * @brief Desenează piesa pe fereastra dată.
     * @param window Fereastra de afișare pe care se desenează piesa.
     */
    virtual void draw(sf::RenderWindow& window);

    /**
     * @brief Mută piesa la noua poziție dată.
     * @param newPosition Noua poziție a piesei.
     */
    void move(const sf::Vector2f& newPosition);

    /**
     * @brief Obține poziția curentă a piesei.
     * @return Poziția curentă a piesei.
     */
    const sf::Vector2f& getPosition() const;

    /**
     * @brief Setează starea de selecție a piesei.
     * @param selected True dacă piesa este selectată, false altfel.
     */
    void setIsSelected(bool selected);

    /**
     * @brief Verifică dacă o mutare este validă pentru piesa.
     * @param initialPosition Poziția inițială a piesei.
     * @param newPosition Noua poziție către care se mută piesa.
     * @param board Tabla de șah pe care se află piesa.
     * @return True dacă mutarea este validă, false altfel.
     */
    virtual bool isValidMove(const sf::Vector2f& initialPosition, const sf::Vector2f& newPosition, const Board& board) const = 0;

    /**
     * @brief Obține culorea piesei.
     * @return Culorea piesei (Albă sau Neagră).
     */
    virtual sf::Color getColor() const;

    /**
     * @brief Suprascrie operatorul << pentru a afișa informații despre piesa.
     * @param os Fluxul de ieșire în care se afișează informațiile.
     * @param piece Piesa care se afișează.
     * @return O referință la fluxul de ieșire.
     */
    friend std::ostream& operator<<(std::ostream& os, const Piece& piece);
};


#endif //OOP_PIECE_H
