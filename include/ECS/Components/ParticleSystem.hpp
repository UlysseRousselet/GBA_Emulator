/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** ParticleSystem
*/

/**
 * @file ParticleSystem.hpp
 * @brief Header file for the ParticleSystem component.
 *
 * This file defines the `ParticleSystem` and `Particle` structures, which are used
 * to simulate and manage particle effects in the game. The `ParticleSystem` is used to
 * create and update a collection of particles, each with a specific position, size,
 * color, and velocity.
 */

#ifndef PARTICLESYSTEM_HPP_
#define PARTICLESYSTEM_HPP_

#include <SFML/Graphics.hpp>
#include <list>

/**
 * @struct Particle
 * @brief Represents an individual particle.
 *
 * This structure is used to define a single particle within the system. Each
 * particle has a position, radius, and color, which define how it will be rendered.
 */
struct Particle {
    sf::Vector2f position; ///< The position of the particle in the game world.
    float radius;          ///< The radius (size) of the particle.
    sf::Color color;       ///< The color of the particle.
};

/**
 * @struct ParticleSystem
 * @brief Manages a collection of particles for visual effects.
 *
 * The `ParticleSystem` structure handles a group of particles, applying movement
 * and rendering for each particle. It defines properties like the velocity of the
 * particles, the number of particles, and their appearance.
 */
struct ParticleSystem {
    sf::RectangleShape shape;      ///< Shape used for rendering particles.
    sf::Vector2f velocity;         ///< Velocity applied to particles for movement.
    float radius;                  ///< Radius of each particle in the system.
    size_t amount;                 ///< Total number of particles in the system.
    sf::Color color;               ///< Color of the particles.
    std::list<Particle> particles; ///< List of individual particles in the system.
    float updateCooldown = 0.0f;
};

#endif /* !PARTICLESYSTEM_HPP_ */
