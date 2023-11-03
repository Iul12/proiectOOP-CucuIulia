#include <SFML/Graphics.hpp>
#include <iostream>

class Board{
private:
    unsigned int boardSize;
    unsigned int squareSize;
    sf::RectangleShape** squares;
    sf::Color white = sf::Color(255, 206, 160);
    sf::Color black = sf::Color(150, 90, 35);

public:
    explicit Board(int boardSize) : boardSize(boardSize), squareSize(boardSize / 8)
    {
        squares = new sf::RectangleShape*[8];
        for (int i = 0; i < 8; i++) {
            squares[i] = new sf::RectangleShape[8];
            for (int j = 0; j < 8; j++)
            {
                squares[i][j] = sf::RectangleShape(sf::Vector2f(static_cast<float>(squareSize), static_cast<float>(squareSize)));
                squares[i][j].setPosition(static_cast<float>(i * squareSize), static_cast<float>(j * squareSize));
                if ((i + j) % 2 == 0)
                    squares[i][j].setFillColor(white);
                else
                    squares[i][j].setFillColor(black);
            }
        }
    }

    Board(const Board& board){
        boardSize = board.boardSize;
        squareSize = board.squareSize;
        squares = new sf::RectangleShape*[8];
        for (int i = 0; i < 8; i++)
        {
            squares[i] = new sf::RectangleShape[8];
            for (int j = 0; j < 8; j++)
                squares[i][j] = board.squares[i][j];

        }
    }

    Board& operator=(const Board& board) {
        if (this != &board) {
            for (int i = 0; i < 8; i++) {
                delete[] squares[i];
            }
            delete[] squares;

            boardSize = board.boardSize;
            squareSize = board.squareSize;
            squares = new sf::RectangleShape *[8];
            for (int i = 0; i < 8; i++) {
                squares[i] = new sf::RectangleShape[8];
                for (int j = 0; j < 8; j++)
                    squares[i][j] = board.squares[i][j];
            }
        }
        return *this;
    }

    ~Board() {
        for (int i = 0; i < 8; i++) {
            delete[] squares[i];
        }
        delete[] squares;
    }

    void draw(sf::RenderWindow& window){
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
                window.draw(squares[i][j]);
        }
    }
    [[nodiscard]] unsigned int getSquareSize() const {
        return squareSize;
    }

    friend std::ostream& operator<<(std::ostream& os, const Board& board) {
        os << "Board Size: " << board.boardSize << "\n" << "Square Size: " << board.squareSize << std::endl;
        return os;
    }
};

class Textures {
private:
    static sf::Texture loadTexture(const std::string& file)
    {
        sf::Texture texture;
        if (!texture.loadFromFile(file)) {
            std::cout << "Error loading texture: " << file << std::endl;
        }
        return texture;
    }
public:

    static sf::Texture whitePawn;
    static sf::Texture whiteKnight;
    static sf::Texture whiteBishop;
    static sf::Texture whiteRook;
    static sf::Texture whiteQueen;
    static sf::Texture whiteKing;

    static sf::Texture blackPawn;
    static sf::Texture blackKnight;
    static sf::Texture blackBishop;
    static sf::Texture blackRook;
    static sf::Texture blackQueen;
    static sf::Texture blackKing;

    static void loadAllTextures()
    {
        whitePawn = loadTexture("C:/images/white_pawn.png");
        whiteKnight = loadTexture("C:/images/white_knight.png");
        whiteBishop = loadTexture("C:/images/white_bishop.png");
        whiteRook = loadTexture("C:/images/white_rook.png");
        whiteQueen = loadTexture("C:/images/white_queen.png");
        whiteKing = loadTexture("C:/images/white_king.png");

        blackPawn = loadTexture("C:/images/black_pawn.png");
        blackKnight = loadTexture("C:/images/black_knight.png");
        blackBishop = loadTexture("C:/images/black_bishop.png");
        blackRook = loadTexture("C:/images/black_rook.png");
        blackQueen = loadTexture("C:/images/black_queen.png");
        blackKing = loadTexture("C:/images/black_king.png");
    }

    friend std::ostream& operator<<(std::ostream& os, const Textures&) {
        os << "Textures information" << std::endl;
        return os;
    }
};
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

class Piece{
private:
    sf::Sprite sprite;
    sf::Vector2f position;

public:
    explicit Piece(const sf::Texture& texture, const sf::Vector2f& position) : sprite(texture), position(position) {
        sprite.setPosition(position);
    }
    Piece(const Piece& other) = default;
    Piece& operator=(const Piece& piece) {
        if (this != &piece)
        {
            sprite = piece.sprite;
            position = piece.position;
        }
        return *this;
    }
    virtual ~Piece() = default;
    virtual void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

    friend std::ostream& operator<<(std::ostream& os, const Piece& piece) {
        os << "Piece at position: (" << piece.position.x << ", " << piece.position.y << ")" << std::endl;
        return os;
    }
};

/**
class Pawn : public Piece {
public:
    Pawn(const sf::Texture& texture, const sf::Vector2f& position) : Piece(texture, position) {}
};

class Knight : public Piece {
public:
    Knight(const sf::Texture& texture, const sf::Vector2f& position) : Piece(texture, position) {}
};

class Bishop : public Piece {
public:
    Bishop(const sf::Texture& texture, const sf::Vector2f& position) : Piece(texture, position) {}
};

class Rook : public Piece {
public:
    Rook(const sf::Texture& texture, const sf::Vector2f& position) : Piece(texture, position) {}
};

class Queen : public Piece {
public:
    Queen(const sf::Texture& texture, const sf::Vector2f& position) : Piece(texture, position) {}
};

class King : public Piece {
public:
    King(const sf::Texture& texture, const sf::Vector2f& position) : Piece(texture, position) {}
};
*/

class Game_Chess {
private:
    sf::RenderWindow window;
    Board *board;
    std::vector<Piece *> pieces; //vector de pointeri la obiectele de tip piece

public:
    void addPiecesToVector() {
        unsigned int squareSize = board->getSquareSize();
        auto scale = static_cast<float>(squareSize); /// conversie la tipul float

        pieces.push_back(new Piece(Textures::whitePawn, sf::Vector2f(0 * scale, 6 * scale)));
        pieces.push_back(new Piece(Textures::whitePawn, sf::Vector2f(1 * scale, 6 * scale)));
        pieces.push_back(new Piece(Textures::whitePawn, sf::Vector2f(2 * scale, 6 * scale)));
        pieces.push_back(new Piece(Textures::whitePawn, sf::Vector2f(3 * scale, 6 * scale)));
        pieces.push_back(new Piece(Textures::whitePawn, sf::Vector2f(4 * scale, 6 * scale)));
        pieces.push_back(new Piece(Textures::whitePawn, sf::Vector2f(5 * scale, 6 * scale)));
        pieces.push_back(new Piece(Textures::whitePawn, sf::Vector2f(6 * scale, 6 * scale)));
        pieces.push_back(new Piece(Textures::whitePawn, sf::Vector2f(7 * scale, 6 * scale)));

        pieces.push_back(new Piece(Textures::whiteRook, sf::Vector2f(0 * scale, 7 * scale)));
        pieces.push_back(new Piece(Textures::whiteKnight, sf::Vector2f(1 * scale, 7 * scale)));
        pieces.push_back(new Piece(Textures::whiteBishop, sf::Vector2f(2 * scale, 7 * scale)));
        pieces.push_back(new Piece(Textures::whiteQueen, sf::Vector2f(3 * scale, 7 * scale)));
        pieces.push_back(new Piece(Textures::whiteKing, sf::Vector2f(4 * scale, 7 * scale)));
        pieces.push_back(new Piece(Textures::whiteBishop, sf::Vector2f(5 * scale, 7 * scale)));
        pieces.push_back(new Piece(Textures::whiteKnight, sf::Vector2f(6 * scale, 7 * scale)));
        pieces.push_back(new Piece(Textures::whiteRook, sf::Vector2f(7 * scale, 7 * scale)));

        pieces.push_back(new Piece(Textures::blackPawn, sf::Vector2f(0 * scale, 1 * scale)));
        pieces.push_back(new Piece(Textures::blackPawn, sf::Vector2f(1 * scale, 1 * scale)));
        pieces.push_back(new Piece(Textures::blackPawn, sf::Vector2f(2 * scale, 1 * scale)));
        pieces.push_back(new Piece(Textures::blackPawn, sf::Vector2f(3 * scale, 1 * scale)));
        pieces.push_back(new Piece(Textures::blackPawn, sf::Vector2f(4 * scale, 1 * scale)));
        pieces.push_back(new Piece(Textures::blackPawn, sf::Vector2f(5 * scale, 1 * scale)));
        pieces.push_back(new Piece(Textures::blackPawn, sf::Vector2f(6 * scale, 1 * scale)));
        pieces.push_back(new Piece(Textures::blackPawn, sf::Vector2f(7 * scale, 1 * scale)));

        pieces.push_back(new Piece(Textures::blackRook, sf::Vector2f(0, 0)));
        pieces.push_back(new Piece(Textures::blackKnight, sf::Vector2f(scale, 0)));
        pieces.push_back(new Piece(Textures::blackBishop, sf::Vector2f(2 * scale, 0)));
        pieces.push_back(new Piece(Textures::blackQueen, sf::Vector2f(3 * scale, 0)));
        pieces.push_back(new Piece(Textures::blackKing, sf::Vector2f(4 * scale, 0)));
        pieces.push_back(new Piece(Textures::blackBishop, sf::Vector2f(5 * scale, 0)));
        pieces.push_back(new Piece(Textures::blackKnight, sf::Vector2f(6 * scale, 0)));
        pieces.push_back(new Piece(Textures::blackRook, sf::Vector2f(7 * scale, 0)));


    }
    Game_Chess() : window(sf::VideoMode(596, 596), "Chess Game") {
        board = new Board(600);
        Textures::loadAllTextures();
        addPiecesToVector();
    }
    Game_Chess(const Game_Chess &other) {
        board = new Board(*other.board);
        pieces.clear();
        for (Piece *piece: other.pieces) {
            pieces.push_back(new Piece(*piece));
        }
    }

    ~Game_Chess() {
        delete board;
        for (Piece *piece: pieces) {
            delete piece;
        }
        std::cout<<"Chess ended!";
    }
    void run()
    {
        sf::Event event;
        while (window.isOpen())
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            board->draw(window);
            for (Piece* piece : pieces) {
                piece->draw(window);
            }
            window.display();
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Game_Chess& game) {
        os << "Chess Game Information" << std::endl;
        os << *game.board;
        for (Piece* piece : game.pieces) {
            os << *piece;
        }
        return os;
    }
};

int main() {
    Game_Chess game;
    game.run();
    std::cout << game;
    std::cout << Textures{};
    ///    return 0;
}
