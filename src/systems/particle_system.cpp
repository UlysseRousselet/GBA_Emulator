/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** particle_system
*/

#include "C_Systems.hpp"

void particle_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<Position> &position, Sparse_array<ParticleSystem> &particle)
{
    std::shared_ptr<sf::RenderWindow> window;
    float deltaTime = 0.0f;

    for (size_t i = 0; i < windows.size(); i++) {
        if (windows[i].has_value()) {
            window = windows[i].value().window;
            deltaTime = windows[i].value().deltaTime;
            break;
        }
    }

    for (size_t i = 0; i < position.size() && i < particle.size(); i++) {
        if (position[i].has_value() && particle[i].has_value()) {
            auto &particleSys = *particle[i];
            particleSys.updateCooldown -= deltaTime;

            if (particleSys.updateCooldown <= 0.0f) {
                particleSys.updateCooldown = 0.05f;
                const auto &pos = *position[i];

                Particle p = {sf::Vector2f{pos.x - 10, pos.y + 20}, particleSys.radius, particleSys.color};
                particleSys.particles.emplace_front(p);

                if (particleSys.particles.size() > particleSys.amount)
                    particleSys.particles.pop_back();

                for (auto it = particleSys.particles.begin(); it != particleSys.particles.end();) {
                    auto &p = *it;

                    p.position.x += particleSys.velocity.x + (rand() % 3);
                    p.position.y += particleSys.velocity.y + 2 + ((rand() % 6) - 3);
                    p.radius = std::max(0.0f, p.radius - 2.0f);

                    p.color.r = std::min(255, p.color.r + 30);
                    p.color.g = std::min(255, p.color.g + 30);
                    p.color.b = std::min(255, p.color.b + 30);

                    if (p.radius <= 0.1f)
                        it = particleSys.particles.erase(it);
                    else
                        ++it;
                }
            }

            for (const auto &p : particleSys.particles) {
                particleSys.shape.setPosition(p.position);
                particleSys.shape.setSize({p.radius, p.radius});
                particleSys.shape.setFillColor(p.color);
                window->draw(particleSys.shape);
            }
        }
    }
}