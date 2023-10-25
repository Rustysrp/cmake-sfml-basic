#include <SFML/Graphics.hpp>
#include <bits/stdc++.h> 

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project", sf::Style::Fullscreen, settings };
    window.setFramerateLimit(60);

    auto radius = 50.f;
    sf::CircleShape circle(radius);
    circle.setPosition((window.getSize().x / 2) - radius, 10.f);

    float mv_velo = 0;

    while (window.isOpen())
    {
        auto mid_s = (window.getSize().x / 2) - radius;

        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                circle.setPosition(mid_s, 10.f);
            }
        }


        // Clear the window w/ a black bg
        window.clear(sf::Color::Black);

        // Move circle
        circle.move(0, mv_velo);

        // Add to move velocity
        mv_velo += 0.95;

        // Check bounds
        if (circle.getPosition().y >= (window.getSize().y - radius * 2)) {
            // Reverse & dampen
            mv_velo = mv_velo * -0.9;
            circle.setPosition(mid_s, window.getSize().y - radius * 2);
        }

        // Set color
        circle.setFillColor(sf::Color(100, 250 * (1 / mv_velo), 100 * (1 / mv_velo)));

        // Draw entities
        window.draw(circle);

        // Display utilities
        window.display();
    }
}
