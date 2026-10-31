# Spirograph

A Spirograph created using **C++ and raylib** in Visual Studio 2022.

The program uses two circles and a drawing point to create different patterns using sine, cosine, and rotation.

The red circle stays still, the blue circle moves around inside it, and the drawing point creates patterns as it moves.

## Controls

| Key | Action |
|---|---|
| Right Arrow | Increase drawing speed |
| Left Arrow | Decrease drawing speed |
| Up Arrow | Increase inner circle size |
| Down Arrow | Decrease inner circle size |
| D | Switch to next drawing color |
| A | Switch to previous drawing color |

There are six drawing colors: Green, Purple, Orange, Pink, Sky Blue, and Gold.

Changing any setting clears the current drawing and starts a new one.

## Code Progression

Instead of replacing older code whenever I made changes, I kept each stage in a separate function. This allows anyone looking through the code to see how the program was built step by step.

1. **`SpiroGraphCirclesDrawn()`** — Creates and positions the two circles.
2. **`SpiroGraphInnerDrawingCircleMade()`** — Makes the inner circle move and adds the drawing point.
3. **`SpiroGraphRotatingCircles()`** — Makes the drawing point rotate around the inner circle.
4. **`SpiroGraphDraw()`** — Connects the drawing point's positions with lines to create patterns.
5. **`SpiroGraph()`** — The final version, adding controls for speed, circle size, and drawing color.

Only `SpiroGraph()` runs by default. You can change the function called in `main()` to see the earlier stages.

## How It Works

The program uses `sin()` and `cos()` to calculate the positions of the moving circle and drawing point.

A `for` loop redraws the previous lines every frame, allowing the pattern to remain visible as it grows.

Changing the inner circle's size creates different patterns.

## Running the Program

Open the project in **Visual Studio 2022** with **raylib** configured, then build and run it.

Use the arrow keys and A/D to experiment with different patterns, speeds, and colors!

![Spirograph](https://github.com/user-attachments/assets/aa7ac384-692d-4eb5-bada-49037e276879)
