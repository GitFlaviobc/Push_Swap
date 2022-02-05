# So_long - My first Graphic project - 2D Top down Game

<h1 name ="content" align = "center">📋 Table of contents</h1>
<p align = "center">
  <a href = "#intro">Intro</a> -
  <a href = "#goal">Goal</a> -
  <a href = "#tec">Tecnology</a> -
  <a href = "#function">Functionality</a> -
  <a href = "#design">Design</a> -
  <a href = "#how">How to use</a> -
  <a href = "#test">Tests</a> -
  <a href = "#update">Update</a> -
  <a href = "#author">Author</a>
</p>

<a name="intro"/> <h2> Intro </h2> </a>
- This is a graphic project, that uses a minilibx library.
- Minilibix is a graphic library made for students at école 42, it uses X11 Xlib to create windowns and graphics.
- It is a small 2D game, so I also applied some game design elements during the project.
- The project is done using 42 Virtual Machine, it uses ubuntu.
- I coded on the VScode of my machine using SSH connection to the VM and did the tests on the VM itself.
- On personal goal on this project was to get player commands without using if, else, or switch.
- And again on this project I am using the functional programming to guide my code structure. Not perfect but getting better.
- All images of the game are made using xpm files. I created png files and converted to xpm. Some simple edits I made on the xpm itself.
- The main character credits goes to [chiken_art](https://opengameart.org/content/lpc-chicken-rework). I just edit a litte to fit my game.
<p></p>
<a href = "#content">📋</a>

<a name="goal"/> <h2> 🎯 Goal </h2> </a>
- so_long goal is to create a 2D game using the graphic library minilibx.
- The game has some rules:
  - Maps must be a file of type .ber  (.ber can be edited the same way you edit a .txt file)
  - Map must have rectangular shape.
  - Must have 1 player. map flag: P
  - Must have 1 exit. map flag: E
  - Must have 1 item to collect. map flag: C
  - The map must be surrounded by walls. map flag: 1
  - If an enemy touches the player the game closes. map flag: H or V
  - Empty space map flag: 0
  - Player must collect all items to be able to exit the game on the exit.
  - The number of player moves is displayed on the screen.
<p></p>
<a href = "#content">📋</a>

<a name="tec"/> <h2> 🛠️ Tecnology </h2> </a>
- Language: C
- VS code
- WSL ubuntu
- Remote SSH access from my machine to the Virtual Machine.
- Norminette 42 (code norm used by école 42)
- [minilibx](https://github.com/42Paris/minilibx-linux)
  - ###### the minilibx keeps getting updates so my version may be different from the one on the original github
<p></p>
<a href = "#content">📋</a>

<a name="function"/> <h2> 📚 Functionality </h2> </a>

![Game Gif](https://github.com/GitFlaviobc/so_long/blob/main/Images/SoLong.gif)

<p></p>
<a href = "#content">📋</a>

<a name="design"/> <h2> 🎮 Design </h2> </a>

- Character, Camera, Controller: 
  - Chiken. Because is friendly and neutral, common in games.
  - Because on how the game is made, the movement looks "fast" so I added pixels to the char sprite to simulate "speed".
  - Camera is fixed top down.
  - Movement is made by AWSD key, ESC quits the game.
- Map:
  - Map main floor is made with seamless green texture to simulate grass floor.
  - Walls are green bushes with the same green texture so it can blend with the floor.
  - The circular shape of the bushes make it easier to control. No need to check if the wall is a corner, top or down.
  - The green map also helps to not stress the player.
- Collectibles:
  - At first the idea was to make an egg, but with the animation it "looked like" a small chiken, so I kept that way.
  - The yellow color make it separate from the green map, calling attention to the player.
  - Yellow is also usually used in games as a good thing, like gold coins and stars.
  - The animation without moving calls attention to the player, in a "safe way".
- Enemies:
  - Just shape to avoid animation and have a movement that does not look "weird". Like a floating orb.
  - At first it was round shape but once I added Horizontal and Vertical movement, it got confusing to understand what was what.
  - Horizontal enemies have oval shape on the horizontal.
  - Vertical enemies have oval shape on the vertical.
  - Enemy colors are more agressive (red and purple).
  - Enemies are the only thing moving around the map, calling more attention to the player.

- Main map:
  - The main map starts with a smaller area to the player to move.
  - The main path has an item that the player can't avoid, so when the player pass it can understand that the it is collectable.
  - First enemy appears on the way with a big space to the player to wait and move.
  - Second enemy appears protecting one item, so player will have to get the timing.
  - Next 2 enemies gives only 1 square to the player to move so it can train the timing and have some challenge.
  - After that the map opens giving more space to the player to think.
  - I add 2 enemies on the Vertical as a small challenge.
  - After that I added 3 in Horizontal and one of them connects to the next are where I mix Horizontal and Vertical enemies.
  - The item on the next area is in a small area where both type of enemies connect making harder to the player.
  - The exit appears first but if the player does not collect the last item, it cannot exit the game.
  - The last item area is smaller and have 2 types of enimies that connect.
  - Player need to go to the safe zones and wait the right time to move, get the item and move back to the exit.
  - Added small easter egg on the map making the walls draw the number 42.

- Know bugs:
  - If an enemy touches an item or the exit, the player will not be able to access. Will create the a "combat" layer to fix this later.

<p></p>
<a href = "#content">📋</a>

<a name="how"/> <h2> 📖 How to use </h2> </a>

- Clone the repository
```bash
git clone https://github.com/GitFlaviobc/so_long.git
```
On the VM ubuntu, and Inside the Project folder:
- to create the library
```bash
make
```
or
```bash
make all
```
- to delete all obj (.o) files created
```bash
make clean
```
 - to delete all created files
```bash
make fclean
```
 - to delete all files and recreate the library
```bash
make re
```
- to run the main map of the game
```bash
make run
```
- to play in any map.
```bash
./so_long "path to the .ber file"
```
###### Without the " "
<p></p>
<a href = "#content">📋</a>

<a name="test"/> <h2> 👨‍💻 Tests </h2> </a>
- to check for leaks during the creation, execution e closure of the game. (The game gets really slow)
- I know that the minilibx has leaks, but I didn't have to fix it.
```bash
make leak
```
<p></p>
<a href = "#content">📋</a>

<a name="update"/> <h2> 🆙 Updates </h2> </a>
- The code I sent to evaluation will be kept the same. Any update will be on the update folder.⚠️🚧
<p></p>
<a href = "#content">📋</a>

<a name="author"/> <h2> 😀 Author </h2> </a>
Name: Flávio Bonini Campos
<p></p>

[![Linkedin](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/flaviobc88/)
<p></p>
<a href = "#content">📋</a>
<p></p>
