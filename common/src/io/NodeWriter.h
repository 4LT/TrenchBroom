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

#pragma once

#include <map>
#include <memory>
#include <vector>

namespace tb::mdl
{
class BrushNode;
class BrushFace;
class EntityNode;
class LayerNode;
class Node;
class WorldNode;
} // namespace tb::mdl

namespace tb::io
{
class NodeSerializer;

class NodeWriter
{
private:
  using EntityBrushesMap = std::map<mdl::EntityNode*, std::vector<mdl::BrushNode*>>;

  const mdl::WorldNode& m_world;
  std::unique_ptr<NodeSerializer> m_serializer;

public:
  NodeWriter(const mdl::WorldNode& world, std::ostream& stream);
  NodeWriter(const mdl::WorldNode& world, std::unique_ptr<NodeSerializer> serializer);
  ~NodeWriter();

  void setExporting(bool exporting);
  void writeMap();

private:
  void writeDefaultLayer();
  void writeCustomLayers();
  void writeCustomLayer(const mdl::LayerNode* layer);

public:
  void writeNodes(const std::vector<mdl::Node*>& nodes);

private:
  void writeWorldBrushes(const std::vector<mdl::BrushNode*>& brushes);
  void writeEntityBrushes(const EntityBrushesMap& entityBrushes);

public:
  void writeBrushFaces(const std::vector<mdl::BrushFace>& faces);
};

} // namespace tb::io
