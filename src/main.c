#include "raylib.h"

#define GRAVITY .1f

struct Player {
  Rectangle body;
  Vector2 velocity;
  float speed;
  float friction;
  int canJump;
};

int main(void) {
  // Initialize
  InitWindow(800, 450, "Basic physics");
  SetTargetFPS(60);

  struct Player player;
  player.body =
      (Rectangle){GetScreenWidth() / 4.f, GetScreenHeight() / 2.f, 20.f, 20.f};
  player.velocity = (Vector2){0.f, 0.f};
  player.speed = .2f;
  player.friction = player.speed / 2;

  Rectangle ground = {0.f, GetScreenHeight() - 20.f, GetScreenWidth(), 1.f};

  // Game loop
  while (!WindowShouldClose()) {
    // Event handling
    // Make the player fall
    if (player.body.y < ground.y - player.body.height) {
      player.canJump = 0;
      player.velocity.y += GRAVITY;
    } else {
      player.canJump = 1;
      player.velocity.y = 0.f;
      player.body.y = ground.y - player.body.height;
    }

    // Player keyboard movement
    if (IsKeyDown(KEY_A))
      player.velocity.x -= player.speed;
    if (IsKeyDown(KEY_D))
      player.velocity.x += player.speed;
    if (IsKeyPressed(KEY_SPACE) && player.canJump)
      player.velocity.y -= 3.f;

    // Friction
    if (player.velocity.x > 0.f)
      player.velocity.x -= player.friction;
    if (player.velocity.x < 0.f)
      player.velocity.x += player.friction;

    // Update the position
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
