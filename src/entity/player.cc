//
// Created by Larry Peng on 4/18/21.
//

#include "entity/player.h"
#include "entity/projectile.h"

namespace finalproject {

Player::Player() {
  row_ = 0;
  col_ = 0;
}

void Player::Display() const {
  //Temporarily an orange triangle to represent the player
  ci::gl::color(ci::Color("orange"));
  size_t grid = 40;
  glm::vec2 top_point(grid / 2.0 + col_ * grid, row_ * grid + 5);
  glm::vec2 left_point(col_ * grid + 5, row_ * grid + grid - 5);
  glm::vec2 right_point(col_ * grid + grid - 5, row_ * grid + grid - 5);
  ci::gl::drawSolidTriangle(top_point, left_point, right_point);
}

void Player::UpdateLocation(size_t row, size_t col) {
  size_t new_row = row_ + row;
  size_t new_col = col_ + col;
  if (new_row >= current_room_->GetHeight() || new_col >= current_room_->GetWidth() || new_row < 0 || new_col < 0) {
    std::cout << "Reached Edge of Room" << std::endl;
  } else if (current_room_->GetObstacles().at(new_row).at(new_col) != nullptr){
    std::cout << "Cannot Move There" << std::endl;
  } else {
    row_ = new_row;
    col_ = new_col;
  }
}

void Player::UpdateRoom(Room* room) {
  current_room_ = room;
}

void Player::AddItem(Item* item) {
  inventory_.push_back(item);
  //Add mechanics to update player stats
}


size_t Player::GetCol() const {
  return col_;
}

size_t Player::GetRow() const {
  return row_;
}

std::vector<Item*> Player::GetInventory() const {
  return inventory_;
}

void Player::FireProjectile(size_t direction) const {
  size_t grid = 40;
  size_t range = 200;
  size_t strength = 20;
  float speed = 5;
  Projectile* proj = new Projectile(col_ * grid + grid / 2, row_ * grid + grid / 2, direction, range, strength, true, grid, speed);
  current_room_->AddProjectile(proj);
}



} // namespace finalproject