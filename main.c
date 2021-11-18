/* Daniel da Silva Severiano dos Santos - cartao numero - turma
   Programa Final da disciplina de
 */

//includes
#include <stdio.h>
#include "raylib.h"
// #include "game.h"
#include "draw.h"
#include "player.h"
// #include "level.h"

//typedefs
typedef enum GameScreen { SPLASH = 0, MAINMENU, GAME, SCORE, HELP, ABOUT }                     GameScreen;
typedef enum MainMenuOption { NEWGAME = 0, CONTINUE, LOADMAP, RANKING, HELPS, ABOUTS, EXIT }   MainMenuOption;

int main() {
    //Variáveis da tela
    const int screenWidth = 1200;
    const int screenHeight = 700;
    const int splashscreenTimeout = 300;
    const char *windowTitle = "Super Mario DOS";

    InitWindow(screenWidth, screenHeight, windowTitle);     //Inicializa janela da raylib

    Mario mario = initMario();

    Rectangle marioRec = { 0.0f, 0.0f, mario.txL.width / 8.0, mario.txL.height };
    Rectangle destRec = { 0.0f, 0.0f, MARIO_WIDTH, MARIO_HEIGHT };

    MainMenuOption currentMainMenuOption = NEWGAME; //enum para listar a opção selecionada do menu principal
    int exit = 0; //flag para encerrar o jogo

    GameScreen currentScreen = SPLASH;

    int framesCounter = 0;

    //Inicialização de recursos
    Font fontMario = LoadFontEx("resources/SuperMario256.ttf", 46, 0, 250); //Carrega a fonte para ser usada na janela

    SetExitKey(KEY_BACKSPACE); //Libera ESC para uso e encerra imediatamente a janela com Backspace

    //l_LoadLevel("resources/fases/fase1.txt");
    // g_CreateBlock(5.0, 5.0, 0);

    SetTargetFPS(60);

    //Loop do jogo
    while (!WindowShouldClose() && !exit) {
        //Lógica
        switch (currentScreen) {
            case SPLASH: {
                //Tela de inicialização

                framesCounter++;

                //Temporizador da tela de inicialização (pressione enter para pular)
                if (framesCounter > splashscreenTimeout || IsKeyPressed(KEY_ENTER)) {
                    currentScreen = MAINMENU;
                }
            } break;

            case MAINMENU: {
                if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE)) {
                    if (currentMainMenuOption == EXIT || IsKeyPressed(KEY_ESCAPE)) exit = 1;
                    else if (currentMainMenuOption == HELPS) currentScreen = HELP;
                    else if (currentMainMenuOption == ABOUTS) currentScreen = ABOUT;
                    else if (currentMainMenuOption == RANKING) currentScreen = SCORE;
                    else {
                        currentScreen = GAME;
                        framesCounter = 0;

                        if (currentMainMenuOption == NEWGAME) {
                            //load stage 1
                        } else if (currentMainMenuOption == CONTINUE) {
                            //loadsave
                        } else if (currentMainMenuOption == LOADMAP) {
                            //loadmap
                        }
                    }
                } else if (IsKeyPressed(KEY_DOWN)) {
                    if (currentMainMenuOption == 6) currentMainMenuOption = 0;
                    else currentMainMenuOption++;
                } else if (IsKeyPressed(KEY_UP)) {
                    if (!currentMainMenuOption) currentMainMenuOption = 6;
                    else currentMainMenuOption--;
                }
            } break;

            case GAME: {
                if (IsKeyPressed(KEY_ESCAPE)) {
                    //TODO: pause game, option to save progress
                } else {
                    framesCounter++;
                    mario.pos.x += mario.speed.x * mario.speedMultiplier.x;
                    mario.pos.y += mario.speed.y * mario.speedMultiplier.y;

                    printf("%f  x  %f\n", mario.pos.x, mario.pos.y);

                    if (framesCounter >= 60 / MARIO_ANIMATION_SPEED) {
                        framesCounter = 0;
                        mario.currentAnimationFrame++;
                    }

                    //g_GameMain();
                    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                        mario.speed.x = -1;
                        mario.facingRight = true;

                        if (mario.currentAnimationFrame > MARIO_WALK3) mario.currentAnimationFrame = MARIO_WALK1;                        //TODO: add check on Y velocity
                    } else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                        mario.speed.x = 1;
                        mario.facingRight = false;

                        if (mario.currentAnimationFrame > MARIO_WALK3) mario.currentAnimationFrame = MARIO_WALK1;                        //TODO: add check on Y velocity
                    } else {
                        mario.speed.x = 0;
                        mario.currentAnimationFrame = 0;
                    }

                    marioRec.x = (mario.currentAnimationFrame * marioRec.width);
                }
            } break;

            case SCORE: {
                // TODO: add scoreboard
                if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE)) {
                    currentScreen = MAINMENU;
                }
            } break;

            case HELP: {
                if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE)) {
                    currentScreen = MAINMENU;
                }
            } break;

            case ABOUT: {
                // TODO: add section
                if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE)) {
                    currentScreen = MAINMENU;
                }
            } break;

            default: break;
        }
        //----------------------------------------------------------------------------------
        //Gráficos
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        switch (currentScreen) {
            case SPLASH: {
                drawSplash(fontMario, windowTitle);

                if (framesCounter < splashscreenTimeout / 2) {
                    DrawRectangle(0, 0, screenWidth, screenHeight - 100, Fade(BLACK, (splashscreenTimeout / 2 - framesCounter) / (splashscreenTimeout * 0.5)));
                } else {
                    DrawRectangle(0, 0, screenWidth, screenHeight - 100, Fade(BLACK, (framesCounter - splashscreenTimeout / 2) / (splashscreenTimeout * 0.5)));
                }
            } break;

            case MAINMENU: {
                drawMainMenu(fontMario, windowTitle, currentMainMenuOption);
            } break;

            case GAME: {
                // DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                // DrawText("GAME SCREEN", 20, 20, 40, MAROON);
                // DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
                //d_Draw();
                if (mario.facingRight) DrawTexturePro(mario.txR, marioRec, destRec, mario.pos, 0, WHITE); //TODO: fix phantom hand bug by splitting textures into single files and turning mario.txR and txL into arrays
                else DrawTexturePro(mario.txL, marioRec, destRec, mario.pos, 0, WHITE);
            } break;

            case SCORE: {
                // TODO: Draw ENDING screen here!
                DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                DrawText("SCORE SCREEN", 20, 20, 40, DARKBLUE);
                DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
            } break;

            case HELP: {
                drawHelp(fontMario);
            } break;

            case ABOUT: {
                //bla
            } break;

            default: break;
        }

        EndDrawing();
    }

    UnloadFont(fontMario);
    unloadMarioTX(mario);
    CloseWindow();

    return 0;
}
