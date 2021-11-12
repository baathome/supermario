#include "raylib.h"

//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen { SPLASH = 0, MAINMENU, GAME, SCORE} GameScreen;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 700;
    const int splashscreenTimeout = 300;
    const char *windowTitle = "Super Mario DOS";

    InitWindow(screenWidth, screenHeight, windowTitle);

    Font fontMario = LoadFontEx("resources/SuperMario256.ttf", 46, 0, 250);

    GameScreen currentScreen = SPLASH;

    int framesCounter = 0;          // Useful to count frames

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch(currentScreen)
        {
            case SPLASH:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > splashscreenTimeout || IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = MAINMENU;
                }
            } break;
            case MAINMENU:
            {
                // TODO: Update TITLE screen variables here!

                // Press enter to change to GAMEPLAY screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAME;
                }
            } break;
            case GAME:
            {
                // TODO: Update GAMEPLAY screen variables here!

                // Press enter to change to ENDING screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = SCORE;
                }
            } break;
            case SCORE:
            {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = MAINMENU;
                }
            } break;
            default: break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            switch(currentScreen)
            {
                case SPLASH:
                {
                    // TODO: Draw LOGO screen here!
                    DrawTextEx(fontMario, windowTitle, (Vector2){ 126.0f, 275.0f }, (float)fontMario.baseSize*1.75+5, 2, BROWN);
                    DrawTextEx(fontMario, windowTitle, (Vector2){ 150.0f, 275.0f }, (float)fontMario.baseSize*1.75, 2, MAROON);

                    if(framesCounter < splashscreenTimeout/2){
                        DrawRectangle(0,0,screenWidth, screenHeight, Fade(BLACK, (splashscreenTimeout/2-framesCounter)/(splashscreenTimeout*0.5)));
                    }
                    else{
                        DrawRectangle(0,0,screenWidth, screenHeight, Fade(BLACK, (framesCounter-splashscreenTimeout/2)/(splashscreenTimeout*0.5)));
                    }

                } break;
                case MAINMENU:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("MAIN MENU", 20, 20, 40, DARKGREEN);
                    DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

                } break;
                case GAME:
                {
                    // TODO: Draw GAMEPLAY screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    DrawText("GAME SCREEN", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

                } break;
                case SCORE:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                    DrawText("SCORE SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

                } break;
                default: break;
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded data (textures, fonts, audio) here!

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

