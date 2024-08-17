#include "raylib.h"

#define GRAVITY .1f

struct Player {
  Rectangle body;
  Vector2 velocity;
  float speed;
  float friction;
};

int main(void) {
  // Initialize
  InitWindow(800, 450, "Basic physics");
  SetTargetFPS(60);

  struct Player player;
  player.body =
      (Rectangle){GetScreenWidth() / 4.f, GetScreenHeight() / 2.f, 10.f, 10.f};
  player.velocity = (Vector2){0.f, 0.f};
  player.speed = .2f;
  player.friction = player.speed / 2;

  Rectangle ground = {0.f, GetScreenHeight() - 20.f, GetScreenWidth(), 1.f};

  // Game loop
  while (!WindowShouldClose()) {
    // Event handling
    // Make the player fall
    if (!CheckCollisionRecs(player.body, ground)) {
      player.velocity.y += GRAVITY;
    } else
      player.velocity.y = 0.f;

    // Player horizontal movement
    if (IsKeyDown(KEY_A))
      player.velocity.x -= player.speed;
    if (IsKeyDown(KEY_D))
      player.velocity.x += player.speed;

    // Friction
    if (player.velocity.x > 0.f)
      player.velocity.x -= player.friction;
    if (player.velocity.x < 0.f)
      player.velocity.x += player.friction;

    player.body.x += player.velocity.x;
    player.body.y += player.velocity.y;

    // Drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangleRec(player.body, BLACK);
    DrawRectangleRec(ground, GREEN);
    EndDrawing();
  }

  // Uninitialize
  CloseWindow();

  return 0;
}
