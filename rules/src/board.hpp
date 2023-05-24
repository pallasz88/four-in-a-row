/*
 * Copyright 2023 László Paál
 *
 * This file is part of four_in_a_row.
 *
 * four_in_a_row is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * four_in_a_row is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with four_in_a_row.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef RULES_SRC_BOARD_HPP_
#define RULES_SRC_BOARD_HPP_

#include "rules/src/export_definition.hpp"
#include <cstdint>

namespace rules {
class API_EXPORT Board {
public:
  constexpr Board() = default;

  [[nodiscard]] constexpr std::uint64_t GetBlueBoard() const noexcept {
    return blueBoard;
  }

  [[nodiscard]] constexpr std::uint64_t GetRedBoard() const noexcept {
    return redBoard;
  }

private:
  std::uint64_t redBoard{};
  std::uint64_t blueBoard{};
};
} // namespace rules

#endif // RULES_SRC_BOARD_HPP_
