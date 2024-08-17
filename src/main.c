#include "raylib.h"

#define GRAVITY .1f

struct Player {
  Rectangle body;
  Vector2 velocity;
  float speed;
};

int main(void) {
  // Initialize
  InitWindow(800, 450, "Basic physics");
  SetTargetFPS(60);

  struct Player player;
  player.body =
      (Rectangle){GetScreenWidth() / 4.f, GetScreenHeight() / 2.f, 10.f, 10.f};
  player.velocity = (Vector2){0.f, 0.f};
  player.speed = 1.f;

  Rectangle ground = {0.f, GetScreenHeight() - 20.f, GetScreenWidth(), 1.f};

  // Game loop
  while (!WindowShouldClose()) {
    // Event handling
    // Make the player fall
    if (!CheckCollisionRecs(player.body, ground)) {
      player.velocity.y += GRAVITY;
      player.body.y += player.velocity.y;
    } else
      player.velocity.y = 0.f;

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
