//
// Created by Larry Peng on 4/19/21.
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace finalproject {

/**
 * Class that represents an item a player can pick up to get stronger.
 */
class Item {

 public:
  /**
   * Constructor for an item.
   *
   * @param name
   * @param health
   * @param attack
   * @param defense
   * @param speed
   * @param shot
   * @param vitality
   */
  Item(std::string name, size_t health, size_t attack, size_t defense, size_t speed, size_t shot, size_t vitality);

  /**
   * Displays the item.
   *
   * @param row the row to display
   * @param col the column to display
   * @param grid_size the size of the grid square occupied by the item
   */
  void Display(size_t row, size_t col, size_t grid_size) const;

  /**
   * Returns a string representation summarizing this item's information
   *
   * @return a string describing this item
   */
  std::string GetSummary() const;

  /**
   * Returns the item's health mod
   *
   * @return health mod
   */
  size_t GetHealth() const;

  /**
   * Returns the item's attack mod
   *
   * @return attack mod
   */
  size_t GetAttack() const;

  /**
   * Returns the item's defense mod
   *
   * @return defense mod
   */
  size_t GetDefense() const;

  /**
   * Returns the item's range mod
   *
   * @return range mod
   */
  size_t GetRange() const;

  /**
   * Returns the item's shot speed mod
   *
   * @return shot mod
   */
  size_t GetShot() const;

  /**
   * Returns the item's vitality mod
   *
   * @return vitality mod
   */
  size_t GetVitality() const;

private:

  std::string item_name_;

  //How much this item alters the health of the player
  size_t health_mod_;

  //How much this item alters the attack of the player
  size_t attack_mod_;

  //How much this item alters the defense of the player
  size_t defense_mod_;

  //How much this item alters the range of the player
  size_t range_mod_;

  //How much this item alters the shot speed of the player
  size_t shot_mod_;

  //How much this item alters the vitality of the player
  size_t vitality_mod_;



};


}
