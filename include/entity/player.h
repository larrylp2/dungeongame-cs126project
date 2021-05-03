//
// Created by Larry Peng on 4/18/21.
//

#pragma once

#include "cinder/gl/gl.h"
#include "game/item.h"
#include "game/room.h"

namespace finalproject {

/**
 * Class that represents the player.
 */
class Player {
 public:
  /**
   * Default Constructor for a player class.
   */
  Player();

  /**
   * Displays a player.
   */
  void Display();

  /**
   * Updates the player's location.
   *
   * @param row how much to change the row by
   * @param col how much to change the col by
   */
  void UpdateLocation(size_t row, size_t col);

  /**
   * Updates the player's current room.
   *
   * @param room the current room of the player
   */
  void UpdateRoom(Room* room);

  /**
   * Adds an item to the player's inventory, updating stats (need to implement)
   *
   * @param item the item the player gains
   */
  void AddItem(Item* item);

  /**
   * Get player column.
   *
   * @return the player's column location
   */
  size_t GetCol() const;

  /**
   * Get player row.
   *
   * @return the player's row location
   */
  size_t GetRow() const;

  /**
   * Gets the player's inventory
   *
   * @return the player's inventory
   */
  std::vector<Item*> GetInventory() const;

  /**
   * Fires a projectile.
   *
   * @param direction the direction to do the attack
   */
  void FireProjectile(size_t direction) const;

  /**
   * Makes this player take damage, returning the amount of health it has left
   *
   * @param damage the amount of damage this enemy takes
   * @return the new current health of this enemy
   */
  double TakeDamage(double damage);


 private:
  // The current room of the player
  Room* current_room_;

  // The row of the player
  size_t row_;

  // The col of the player
  size_t col_;

  // The inventory of the player
  std::vector<Item*> inventory_;

  size_t max_health_;

  size_t current_health_;

  size_t attack_;

  size_t defense_;

  size_t range_;

  size_t shot_;

  size_t vitality_;

};

}