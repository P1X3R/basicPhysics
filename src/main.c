#include "raylib.h"

#define GRAVITY 9.8

struct Player {
  Rectangle body;
  Vector2 velocity;
  float speed;
};

int main(void) {
  // Initialize
  InitWindow(800, 450, "raylib [core] example - basic window");
  SetTargetFPS(60);

  struct Player player;
  player.body = (Rectangle){GetScreenWidth() / 4.0f, GetScreenHeight() / 2.0f,
                            10.0f, 10.0f};
  player.speed = 4;

  // Game loop
  while (!WindowShouldClose()) {
    // Event handling
    player.body.y += GRAVITY;

    // Drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangleRec(player.body, BLACK);
    EndDrawing();
  }

  // Uninitialize
  CloseWindow();

  return 0;
}