#include <stdlib.h>
#include "raylib.h"

#include "particle.h"

int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;

    SetRandomSeed(1);

    const int particleCount = 100000;
    Particle *particles = (Particle*)malloc(particleCount * sizeof(Particle));

    for (long int i = 0; i < particleCount; i++)
    {
        particles[i] = Particle(screenWidth, screenHeight);
    }
    

    InitWindow(screenWidth, screenHeight, "raylib test");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        Vector2 mousePos = (Vector2){(float)GetMouseX(), (float)GetMouseY()};
        for (long int i = 0; i < particleCount; i++)
        {   
            particles[i].attract(mousePos, 1);

            particles[i].doFriction(0.99);

            particles[i].move(screenWidth, screenHeight);
            
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for (int i = 0; i < particleCount; i++)
            {
                particles[i].drawPixel();
            }

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    MemFree(particles);
    //--------------------------------------------------------------------------------------

    return 0;
}
