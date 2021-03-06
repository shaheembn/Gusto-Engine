#pragma once

/**
 * A graphical component, that is used to draw a movable sprite at a given position, drawn with a given texture.
 */

#include "System/Texture.h"
#include "System/Shader.h"
#include "System/FileManager.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

enum RigidBodyType
{
  STATIC = 0,
  DYNAMIC = 1
};

class RigidBody
{
private:
  Shader shader;
  unsigned int texture;
  float vertices[20];
  unsigned int indices[6] = {
      3, 0, 2,
      2, 0, 1};
  unsigned int vbo;
  unsigned int vao;
  unsigned int ebo;

public:
  glm::vec2 position;
  glm::vec2 scale;
  glm::vec2 velocity = glm::vec2(0.f, 0.f);
  glm::vec2 force = glm::vec2(0.f, 0.f);
  float mass = 0.f;

  bool collided = false;

  RigidBodyType type;

  RigidBody(glm::vec2 Position, glm::vec2 Scale, RigidBodyType Type);

  glm::vec2 getPosition();
  glm::vec2 getScale();
  glm::vec2 getMass();

  void setPosition(glm::vec2 pos);
  void setScale(glm::vec2 scale);
  void setMass(float mass);
  void setTexture(std::string textureImagePath, float textureImageScale = 1.f);

  void updateMovement();
  void draw();
};
