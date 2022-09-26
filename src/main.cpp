#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>

#include "game.h"
#include "ship.h"
std::vector<Ship *> ships;


sf::Texture spritesheet;
sf::Sprite invader;
namespace fs = std::filesystem;
using namespace std;


void Load() {


    fs::path pathToShow(".");
    std::cout << "exists() = " << fs::exists(pathToShow) << "\n"
              << "root_name() = " << pathToShow.root_name() << "\n"
              << "root_path() = " << pathToShow.root_path() << "\n"
              << "relative_path() = " << pathToShow.relative_path() << "\n"
              << "parent_path() = " << pathToShow.parent_path() << "\n"
              << "filename() = " << pathToShow.filename() << "\n"
              << "stem() = " << pathToShow.stem() << "\n"
              << "extension() = " << pathToShow.extension() << "\n";



    if (!spritesheet.loadFromFile("invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(0, 0, 32, 32));

    Invader *inv = new Invader(sf::IntRect(0, 0, 32, 32), {100, 100});
    //ships.push_back(inv);

    Invader::speed = 20.0;


    for (int r = 0; r < invaders_rows; ++r) {
        auto rect = sf::IntRect(0, 0, 32, 32);
        for (int c = 0; c < invaders_columns; ++c) {
            sf::Vector2f position = {float(10 + c * 32), 100};
            auto inv = new Invader(rect, position);
            ships.push_back(inv);
        }
    }

}

void Render(sf::RenderWindow &window) {
    window.draw(invader);
    for (const auto s: ships) {
        window.draw(*s);
    }
}

void Update(const float &dt) {
    for (auto &s: ships) {
        s->Update(dt);
    };
}

    int main() {


        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);


        auto window = sf::RenderWindow{{640u, 480u}, "CMake SFML Project"};
        Load();

        window.setFramerateLimit(144);


        while (window.isOpen()) {
            for (auto event = sf::Event{}; window.pollEvent(event);) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            Render(window);
            //window.draw(invader);

            //window.draw(shape);

            window.display();
            window.clear(sf::Color(0, 0, 255));
        }
    }