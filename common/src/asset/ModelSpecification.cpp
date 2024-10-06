/*
 Copyright (C) 2010 Kristian Duske

 This file is part of TrenchBroom.

 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#include "asset/ModelSpecification.h"

#include "kdl/hash_utils.h"
#include "kdl/path_hash.h"
#include "kdl/reflection_impl.h"

namespace tb::asset
{

kdl_reflect_impl(ModelSpecification);

} // namespace tb::asset

std::size_t std::hash<tb::asset::ModelSpecification>::operator()(
  const tb::asset::ModelSpecification& spec) const noexcept
{
  return kdl::combine_hash(
    kdl::path_hash{}(spec.path), kdl::hash(spec.skinIndex, spec.frameIndex));
}
