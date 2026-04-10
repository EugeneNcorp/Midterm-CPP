//Midterm Game Pseudo Code:

class MapManager
{
  //Matrix Dimensions
  char matrix [20][20];
  
  //Method that renders map
  void Render()
  {
  
    //Method draws matrix in it current state with two loops
    for(y < 20)
    {
      for(x < 20)
      {
          cout<< matrix[x][y]
      }
      cout<<endl;
    }
  }
}
class Entity
{

  //Entity properties
  string name;
  char representationSymbol; //like "@"
  int hp;
  int str;
  
    //entity's position
  int x, y;
  
  //function that changes entity's position
  void MoveTo(int newX, int newYб MapManager map)
  {
    //Clear the current position
    map.matrix[x][y] = '*';
    //apply new coordinates
    x = newX;
    y = NewY;
    
    //Put the symbol on the place of new coordinates
     map.matrix[x][y] = representationSymbol;
  }
}

class EnemyController
{
  //Array that knows about all enemies
  Entity enemies[10];
  
  enemies[0] = {"Skeleton", 'S', 5, 1, 10, 10}
  //Method that spawn all enemies 
  void SpawnEnemy(MapManager map)
  {
    map.maptrix[enemies[0].x][enemies[0].y] = enemies[0].representationSymbol;
  }
  
  //Move enemy if it's position two cells from the player
  if(player's position <= 2 cells)
  {
    enemies[0].MoveTo(enemies[0].x, enemies[0].y);
    
    enemies[0].x = nextPosX;
    enemies[0].y = nextPosY;
    
    enemies[0].MoveTo(enemies[0].x, nenemies[0].y);
  }
}

//Class that hold main methods and full game logic
class GameController
{
  Entity player{"Player", 18, 2, 1, 1};
  MapManager map;
  EnemyController enemies;
  bool isRunning = true;
  

  void StartGame()
  {
    while(true)
    {
      //Reset all game data including Inventory, Stats, enemies and items placement
      ResetAllData();
      //Prompt user to enter the game
      cin >> player.name;
      //this method initialize place map layout, player and enemies
      InitializeMap();
      //Spawn enemies in random rooms within boundaries.
      enemies.Spawn();  
      
      //Main Game Loop
      while (isRunning)
      {
        //Renders map
        map.Render();
        //Analyze player's input
        HandlePlayerInput();
        //Check player's Conditions
        UpdatePlayerConditions();
      }
    }
  }

  void HandlePlayerInput()
  {
    if('I' pressed)
    {
      //Function that Render Inventory and stop player's movement
      OpenInventory();
    }
    
    if("KEY_UP" OR "KEY_DOWN" OR "KEY_RIGHT" OR "KEY_LEFT")
    {
      //Do the input depending on the key pressed
      char keyPressed;
      cin >> keyPressed;
      AnalyzeMovement(keyPressed);
    }
  }

  void AnalyzeMovement(char dir)
  {
    //Find the current X and Y position of the player on board
    int nextPosX = currentPosX();
    int nextPosY = currentPosY();
    //Depending on the directional input we move the Player along the incremented Axis
    switch(dir)
    {
      case "KEY_UP": nextPosY--;
      case "KEY_DOWN": nextPosY++;
      case "KEY_LEFT": nextPosX--;
      case "KEY_RIGHT": nextPosX++;
    }
    if(Enemy on the way)
    {
      //if there is a enemy on the way, exchange attacks
      ExchangeAttacks();
    }
    
    if(There is no wall)
    {
      //if player can move further he moves
      player.MoveTo(nextPosX, nextPosY);
      //if there is an item at this position, it goes to inventory
      CheckItemStep(nextPosX, nextPosY);
    }

  }

  
  void UpdateConditions()
  {
    //if player doesn't have hp, reset the game
    if(player.hp <= 0)
    {
      ShowDeathScreen();
      isRunning = false;
    }
    
    //if player acquired key item, reset the game
    else if(player.HasItem("Amulet of Yendor"))
    {
      ShowWinScreen();
      isRunning = false;
    }
  }
}

main()
{
  //Start the game
  GameController game;
  game.StartGame();
  
  return 0;

  }
}
