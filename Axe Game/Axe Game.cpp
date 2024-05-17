#include <iostream>
#include "raylib.h"

int main() {
    // Initialization
    const int screenWidth{ 800 };
    const int screenHeight { 450 };

    InitWindow(screenWidth, screenHeight, "Raylib - Basic Window");

    SetTargetFPS(60);

    int circle_x{ 200 }, circle_y{ 200 }, circle_radius{ 25 };
    int l_circle_x{ circle_x - circle_radius }, r_circle_x{ circle_x + circle_radius },
        u_circle_y{ circle_y - circle_radius }, b_circle_y{ circle_y + circle_radius };
    
    int axe_x{ 400 }, axe_y{ 400 }, axe_length{ 50 };
    int l_axe_x{ axe_x }, r_axe_x{ axe_x + axe_length },
        u_axe_y{ axe_y }, b_axe_y{ axe_y + axe_length };

    int direction{ 10 };

    bool collision_with_axe =   (b_axe_y >= u_circle_y) &&
                                (u_axe_y <= b_circle_y) &&
                                (r_axe_x >= l_circle_x) &&
                                (l_axe_x <= r_circle_x);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (collision_with_axe) {
            DrawText("Game over!", 400, 200, 20, RED);
        }
        else {
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            collision_with_axe = (b_axe_y >= u_circle_y) &&
                (u_axe_y <= b_circle_y) &&
                (r_axe_x >= l_circle_x) &&
                (l_axe_x <= r_circle_x);

            DrawCircle(circle_x, circle_y, circle_radius, BLUE);

            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

            axe_y += direction;
            if (axe_y > screenHeight || axe_y < 0) {
                direction = -direction;
            }

            //Move the circle
            if (IsKeyDown(KEY_D) && circle_x < screenWidth) {
                circle_x += 10;
            }
            else if (IsKeyDown(KEY_A) && circle_x > 0) {
                circle_x -= 10;
            }
            else if (IsKeyDown(KEY_W) && circle_y > 0) {
                circle_y -= 10;
            }
            else if (IsKeyDown(KEY_S) && circle_y < screenHeight) {
                circle_y += 10;
            }


        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}