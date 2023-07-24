#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"

int DISPLAY_WIDTH = 1280;
int DISPLAY_HEIGHT = 720;
int DISPLAY_SCALE = 1;

struct GameState
{
	float timer = 0;
	int spriteID = 0;
};

GameState gameState;

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate(float elapsedTime)
{
	gamestate.timer += elapsedTime;
	Play::ClearDrawingBuffer(Play::cOrange);

	Play::DrawDebugText({ DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 },
		Play::GetSpriteName(gameState.spriteID),
		Play::cWhite);

	Play::DrawSprite(gameState.spriteID, Play::GetMousePos(), gameState.timer);

	if (Play::KeyPressed(VK_SPACE))
		gameState.spriteID++;

	Play::PresentDrawingBuffer();
	return Play::KeyDown(VK_ESCAPE);
}
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}

