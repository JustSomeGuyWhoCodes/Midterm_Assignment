\# Spirograph — C++ \& raylib



An animated, interactive Spirograph created using \*\*C++ and raylib\*\* in Visual Studio 2022.



This project demonstrates how to use circles, trigonometry, loops, and keyboard inputs to create different geometric patterns.



It also serves as a step-by-step learning project. Instead of replacing older code whenever a new feature was added, I kept previous versions in separate functions so others can see how the program developed and understand the changes made along the way.



\## About the Project



A Spirograph creates geometric patterns by tracing the movement of a drawing point attached to a smaller circle rolling inside a larger circle.



In this program:



\- The \*\*red circle\*\* is the stationary outer circle.

\- The \*\*blue circle\*\* moves around the inside of the red circle.

\- The \*\*green dot\*\* is the drawing point that rotates with the blue circle.

\- The \*\*green lines\*\* show the path traced by the drawing point, creating the Spirograph pattern.



The animation continues running, allowing the user to experiment with different speeds and circle sizes.



Changing the inner circle's radius produces different patterns, while changing the speed controls how quickly they are drawn.



\## Controls



| Key | Action |

|---|---|

| Right Arrow | Increase drawing speed |

| Left Arrow | Decrease drawing speed |

| Up Arrow | Increase the inner circle's radius, creating a different pattern |

| Down Arrow | Decrease the inner circle's radius, creating a different pattern |



\*\*Important:\*\* Whenever a setting changes, the previous drawing is cleared and a new pattern begins.



The program also includes limits to prevent the animation speed from reaching zero and the inner circle from becoming too large or too small.



\## How the Code Progresses



The project contains five functions showing different stages of development.



Only the final `SpiroGraph()` function is called in `main()`. The other functions are kept so anyone looking through the code can follow the development process and learn how each new feature was added.



\### 1. `SpiroGraphCirclesDrawn()`



\*\*The starting point — creating the two circles.\*\*



This function introduces the basic setup of the program.



\- Creates an 800 × 800 window using raylib.

\- Draws a stationary red outer circle.

\- Draws a smaller blue circle inside it.

\- Uses the difference between the two radii to position the blue circle against the inner edge of the red circle.



The main idea introduced here is:



```cpp

float distance = outer - inner;

```



This calculates the distance between the centers of the two circles when the smaller circle is touching the inside edge of the larger one.



This stage focuses on understanding circle coordinates, radii, and positioning.



\### 2. `SpiroGraphInnerDrawingCircleMade()`



\*\*Adding movement and the drawing point.\*\*



This function builds on the previous stage by making the blue circle move around inside the red circle.



It introduces `cos()`, `sin()`, and `DEG2RAD` to calculate the blue circle's position based on an angle.



```cpp

float innerX = xCoordinate + cos(DEG2RAD \* angle) \* distance;

float innerY = yCoordinate - sin(DEG2RAD \* angle) \* distance;

```



The angle increases every frame, causing the blue circle to move around the inside of the red circle.



A small green dot is also added to represent the drawing point.



At this stage, the green dot stays to the right of the blue circle's center rather than rotating independently.



\### 3. `SpiroGraphRotatingCircles()`



\*\*Making the green drawing point rotate.\*\*



This stage introduces the rotation needed to create a Spirograph.



The blue circle's center continues moving around the red circle, but the green dot now rotates around the blue circle's center.



```cpp

float drawAngle = -distance / inner \* angle;

```



This calculates the drawing point's rotation angle based on the relationship between the two circles.



The negative sign causes the drawing point to rotate in the opposite direction from the movement of the blue circle's center.



The drawing point's position is then calculated using sine and cosine.



This stage demonstrates how combining two circular movements can create more complex motion.



\### 4. `SpiroGraphDraw()`



\*\*Creating the actual Spirograph pattern.\*\*



This function introduces drawing lines between the green dot's previous positions.



A `for` loop calculates the drawing point's position at different angles and connects those positions using `DrawLine()`.



```cpp

DrawLine(previousX, previousY, drawX2, drawY2, GREEN);



previousX = drawX2;

previousY = drawY2;

```



After each line is drawn, the current position is saved as the previous position for the next iteration.



An important detail is that `ClearBackground()` clears the window every frame.



To keep the Spirograph visible, the `for` loop starts from the beginning and redraws all previously calculated lines up to the current angle.



This creates the appearance of a continuous drawing that gradually builds over time.



\### 5. `SpiroGraph()`



\*\*The completed interactive Spirograph.\*\*



This is the final version of the program and the function called by `main()`.



It combines everything from the previous stages and adds keyboard controls.



The user can now:



\- Increase or decrease the animation speed.

\- Change the inner circle's radius to create different patterns.

\- Reset the drawing automatically whenever a setting changes.

\- Continue watching the Spirograph draw without a programmed stopping point.



The program also uses conditional statements to limit the speed and circle size.



For example:



```cpp

if (inner - 5 >= 40)

{

&#x20;   inner -= 5;

&#x20;   distance = outer - inner;

&#x20;   angle = 0;

}

```



This prevents the inner circle's radius from dropping below 40 pixels.



Resetting `angle` to zero causes the drawing to start over using the new settings.



\## How the Spirograph Works



The program uses trigonometry to calculate positions along circular paths.



The main variables are:



| Variable | Purpose |

|---|---|

| `outer` | Radius of the stationary red circle |

| `inner` | Radius of the moving blue circle |

| `distance` | Distance between the two circle centers |

| `innerDrawCircle` | Distance between the green drawing point and the blue circle's center |

| `angle` | Controls the blue circle's position along its path |

| `drawAngle` | Controls the green drawing point's rotation |

| `speed` | Determines how much the angle increases each frame |



The blue circle's center moves along a circular path calculated using `cos()` and `sin()`.



The green drawing point rotates around the blue circle's center at a different rate.



Combining these two movements creates the Spirograph pattern.



Changing the inner circle's radius changes the relationship between the two rotations, resulting in different designs.



\## Technologies Used



\- \*\*C++\*\* — Main programming language.

\- \*\*raylib\*\* — Window creation, drawing, animation, and keyboard input.

\- \*\*Visual Studio 2022\*\* — Development environment.

\- \*\*cmath\*\* — Mathematical functions such as sine and cosine.



\## Running the Project



The project was developed in Visual Studio 2022 using C++ and raylib.



To run it:



1\. Open the project in Visual Studio 2022.

2\. Make sure raylib is installed and configured for the project.

3\. Build and run the program.

4\. Use the arrow keys to experiment with different patterns and speeds.

5\. Close the window to exit.



The final `SpiroGraph()` function is called by default.



To explore earlier development stages, change the function called inside `main()` to one of the other Spirograph functions.



\## Purpose of This Repository



This repository is intended to show both the finished program and the process of creating it.



The earlier functions have intentionally been left in the source code rather than removed or overwritten.



Each function represents a stage in development, allowing others who are learning C++ or raylib to see how the project progresses from drawing two simple circles to creating an animated, interactive Spirograph.



The goal is not just to show the final result, but also to help explain the programming concepts used to build it.

