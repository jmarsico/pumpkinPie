The Menu classes will include the startup and pause menu, as well as the gameplay menu. The startup menu features text that scrolls through the screen similar to the beginning of the movie Star Wars.  Once finished, a state change will switch to a view of the startup menu, which features the title of the game as well as a list of levels that the player can select. 
The select() memeber function takes an x and y coordinate from the controller file and tests to see if that coordinate falls into a 'selection region' on the menu.  If it does, it changes the protected selection variable to the relevant selection (1,2,3,4,etc). 

The selection can be accessed from the outside by calling the getSelection() function.  This protects the selection varialbe from outside manipulation.

To test this class, I called the function from the main file and logged the results in three different places (from the main file when the mouse is clicked and the function is called, from the selection function and from the getSelection function.)

I also manually tested on screen to verify that the selection locations were accurate and that players could not miss-click their selection.