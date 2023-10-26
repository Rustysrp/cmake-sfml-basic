#include <SFML/Graphics.hpp>
#include <bits/stdc++.h> 

int main()
{
    // Settings and window definitions
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project", sf::Style::Fullscreen, settings };
    window.setFramerateLimit(60);

    // Defining circle qualities
    auto radius = 50.f;
    sf::CircleShape circle(radius);
    circle.setPosition((window.getSize().x / 2) - radius, 10.f);

    // Physics variables
    float dt = 0.5f;
    float velo_x = 12.5f;
    float velo_y = 0.0f;
    float accel_x = 0.0f;
    float accel_y = 1.0f;

    // Main loop
    while (window.isOpen())
    {
        auto mid_s = (window.getSize().x / 2) - radius;

        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.scancode == sf::Keyboard::Scan::W) {
                    velo_y = velo_y - 2.5f;
                }

                if (event.key.scancode == sf::Keyboard::Scan::S) {
                    velo_y = velo_y + 2.5f;
                }

                if (event.key.scancode == sf::Keyboard::Scan::A) {
                    velo_x = velo_x - 2.5f;
                }

                if (event.key.scancode == sf::Keyboard::Scan::D) {
                    velo_x = velo_x + 2.5f;
                }
            }
        }

        // Clear the window w/ a black bg
        window.clear(sf::Color::Black);

        // Movement physics
        velo_x = velo_x + accel_x * dt;
        velo_y = velo_y + accel_y * dt;
        circle.move(velo_x * dt, velo_y * dt);

        // Check x and y bounds
        if (circle.getPosition().y >= (window.getSize().y - radius * 2) || circle.getPosition().y < 0) {
                // Reverse & dampen
                velo_y = velo_y * -0.95;

                // Make sure the ball doesn't go off screen
                if (circle.getPosition().y < 0) {
                    circle.setPosition(circle.getPosition().x, 0);
                }

                if (circle.getPosition().y >= (window.getSize().y - radius * 2)) {
                    circle.setPosition(circle.getPosition().x, window.getSize().y - radius * 2);
                }
        }

        if (circle.getPosition().x >= (window.getSize().x - radius * 2) || circle.getPosition().x < 0) {
                // Reverse & dampen
                velo_x = velo_x * -0.9;
                accel_x = accel_x * -1;
                
                // Make sure the ball doesn't go off screen
                if (circle.getPosition().x >= (window.getSize().x - radius * 2)) {
                    circle.setPosition(window.getSize().x - radius * 2, circle.getPosition().y);
                }

                if (circle.getPosition().x < 0) {
                    circle.setPosition(0, circle.getPosition().y);
                }
        }

        // Color and draw circle
        circle.setFillColor(sf::Color(250 * (1 / (velo_x * velo_y)), 250 * (1 / velo_x), 250 * (1 / velo_y)));
        window.draw(circle);

        // Display utilities
        window.display();

    }
}
