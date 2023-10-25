#include <SFML/Graphics.hpp>
#include <bits/stdc++.h> 

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project", sf::Style::Default, settings };
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project"};
    window.setFramerateLimit(60);

    sf::CircleShape circle(50.f);
    circle.setPosition(0, 0);

    float mv_velo = 0;

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                circle.setPosition(0.f, 0.f);
            }
        }


        // Clear the window w/ a black bg
        window.clear();

        // Move circle
        circle.move(0, mv_velo);

        // Add to move velocity
        mv_velo += 0.95;

        // Check bounds
        if (circle.getPosition().y >= (window.getSize().y - 100.f)) {
            // Reverse & dampen
            mv_velo = mv_velo * -0.9;
        }

        // Set color
        circle.setFillColor(sf::Color(100, 250, 50));

        // Draw entities
        window.draw(circle);

        // Display utilities
        window.display();
    }
}
