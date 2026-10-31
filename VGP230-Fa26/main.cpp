#include <raylib.h>
#include <string>
#include <cmath>
#include <raymath.h>


void SpiroGraphCirclesDrawn()
{
		int wh = 800; // since width and height are same number, use same variable for both

		InitWindow(wh, wh, "Spirograph");
		SetTargetFPS(60);

		//set both circles in same spot to set up with one smaller than other so it's inside it

		float xCoordinate = wh / 2;
		float yCoordinate = wh / 2;

		float outer = 200; // large (outer) circle radius
		float inner = 75;  // small (outer) circle radius
		float distance = outer - inner;

		float angle = 0;
		float speed = 1;

		while (!WindowShouldClose())
		{

			float innerX = xCoordinate + cos(DEG2RAD * angle) * (distance);
			float innerY = yCoordinate - sin(DEG2RAD * angle) * (distance);


			BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawCircleLines(xCoordinate, yCoordinate, outer, RED);

			DrawCircleLines(xCoordinate + (outer - inner), yCoordinate, inner, BLUE);
			// outer is used as a valude so the inner circle is created at the border line of the outer circle, then subtract raidus of inner 
			// to move it properly inside the outer circle
			// Y coordinate stays the same for now so we can get it onto the same y level

			EndDrawing();
		}

		CloseWindow();
	
}


void SpiroGraphInnerDrawingCircleMade()
{
	int wh = 800; // since width and height are same number, use same variable for both

	InitWindow(wh, wh, "Spirograph");
	SetTargetFPS(60);

	//set both circles in same spot to set up with one smaller than other so it's inside it

	float xCoordinate = wh / 2;
	float yCoordinate = wh / 2;

	float outer = 200; // large (outer) circle radius
	float inner = 75;  // small (outer) circle radius
	float distance = outer - inner;
	float innerDrawCircle = 40;


	float angle = 0;
	float speed = 1;

	while (!WindowShouldClose())
	{

		float innerX = xCoordinate + cos(DEG2RAD * angle) * (distance);
		float innerY = yCoordinate - sin(DEG2RAD * angle) * (distance);
		// use these for the inner circle now
		// will help calculate the distance using the angle we set
		// if angle is 0, it is drawn where we originally had it drawn in previous function
		// a

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawCircleLines(xCoordinate, yCoordinate, outer, RED);

		DrawCircleLines(innerX, innerY, inner, BLUE);		
		DrawCircle(innerX + innerDrawCircle, innerY, 5, GREEN);
		// drawing a new circle inside the inner circle for the actual drawing proccess

		EndDrawing();
		angle += speed;
		// will change the angle by 1 every loop
	}

	CloseWindow();

}



void SpiroGraphRotatingCircles()
{
	int wh = 800; // since width and height are same number, use same variable for both

	InitWindow(wh, wh, "Spirograph");
	SetTargetFPS(60);

	//set both circles in same spot to set up with one smaller than other so it's inside it

	float xCoordinate = wh / 2;
	float yCoordinate = wh / 2;

	float outer = 200; // large (outer) circle radius
	float inner = 75;  // small (outer) circle radius
	float distance = outer - inner;
	float innerDrawCircle = 40;


	float angle = 0;
	float speed = 1;

	
	while (!WindowShouldClose())
	{

		float innerX = xCoordinate + cos(DEG2RAD * angle) * (distance);
		float innerY = yCoordinate - sin(DEG2RAD * angle) * (distance);

		float drawAngle = -(distance) / inner * angle;
		// tells us how quickly the green dot needs to rotate relative to the blue circle's movement
		// the negative sign makes its rotation go in the opposite direction

		// now we do for the inner drawing circle!
		float drawX = innerX + cos(DEG2RAD * drawAngle) * innerDrawCircle;
		float drawY = innerY - sin(DEG2RAD * drawAngle) * innerDrawCircle;

		// calculate new angle for inner circle for the drawing part

		
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawCircleLines(xCoordinate, yCoordinate, outer, RED);

		DrawCircleLines(innerX, innerY, inner, BLUE);
		DrawCircle(drawX, drawY, 5, GREEN);
		// replace green circle code with this now

		EndDrawing();
		angle += speed;
	}

	CloseWindow();

}


void SpiroGraphDraw()
{
	int wh = 800; // since width and height are same number, use same variable for both

	InitWindow(wh, wh, "Spirograph");
	SetTargetFPS(60);

	//set both circles in same spot to set up with one smaller than other so it's inside it

	float xCoordinate = wh / 2;
	float yCoordinate = wh / 2;

	float outer = 200; // large (outer) circle radius
	float inner = 75;  // small (outer) circle radius
	float distance = outer - inner;
	float innerDrawCircle = 40;


	float angle = 0;
	float speed = 1;

	while (!WindowShouldClose())
	{

		float innerX = xCoordinate + cos(DEG2RAD * angle) * (distance);
		float innerY = yCoordinate - sin(DEG2RAD * angle) * (distance);

		float drawAngle = -(distance) / inner * angle;
		// tells us how quickly the green dot needs to rotate relative to the blue circle's movement
		// the negative sign makes its rotation go in the opposite direction

		// now we do for the inner drawing circle!
		float drawX = innerX + cos(DEG2RAD * drawAngle) * innerDrawCircle;
		float drawY = innerY - sin(DEG2RAD * drawAngle) * innerDrawCircle;

		// calculate new angle for inner circle for the drawing part


		BeginDrawing();
		ClearBackground(RAYWHITE);

		float previousX = xCoordinate + distance + innerDrawCircle;
		float previousY = yCoordinate;

		for (float i = 0; i < angle; i += 1)
		{
			float innerX2 = xCoordinate + cos(DEG2RAD * i) * distance;
			float innerY2 = yCoordinate - sin(DEG2RAD * i) * distance;

			float drawAngle2 = -distance / inner * i;

			float drawX2 = innerX2 + cos(DEG2RAD * drawAngle2) * innerDrawCircle;
			float drawY2 = innerY2 - sin(DEG2RAD * drawAngle2) * innerDrawCircle;

			DrawLine(previousX, previousY, drawX2, drawY2, GREEN);

			previousX = drawX2;
			previousY = drawY2;
		}
		// loop through all previous angles to redraw the spirograph lines
		// calculate green dot position at each angle and connect it to previous position
		// save current position as previous for next loop
		// keeps all lines visible even though background clears every frame


		DrawCircleLines(xCoordinate, yCoordinate, outer, RED);

		DrawCircleLines(innerX, innerY, inner, BLUE);
		DrawCircle(drawX, drawY, 5, GREEN);
		// replace green circle code with this now

		
		EndDrawing();
		angle += speed;
	}

	CloseWindow();

}



void SpiroGraph()
{
	int wh = 800; // since width and height are same number, use same variable for both

	InitWindow(wh, wh, "Spirograph");
	SetTargetFPS(60);

	//set both circles in same spot to set up with one smaller than other so it's inside it

	float xCoordinate = wh / 2;
	float yCoordinate = wh / 2;

	float outer = 200; // large (outer) circle radius
	float inner = 75;  // small (outer) circle radius
	float distance = outer - inner;
	float innerDrawCircle = 40;


	float angle = 0;
	float speed = 1;

	// adding color choices
	Color colors[] = { GREEN, PURPLE, ORANGE, PINK, SKYBLUE, GOLD };
	int colorIndex = 0;

	while (!WindowShouldClose())
	{
		// speed controls
		if (IsKeyPressed(KEY_RIGHT))
		{
			speed += 1;
			angle = 0;
		}
		else if (IsKeyPressed(KEY_LEFT))
		{
			if (speed > 1)
			{
				speed -= 1;
				angle = 0;
			}
		}
		// if right arrow key is pressed, make faster
		// if left is pressed, make slower, is already at 1, no more changes possible for slower


		if (IsKeyPressed(KEY_UP))
		{
			if (inner + 5 < outer)
			{
				inner += 5;
				distance = outer - inner;
				angle = 0;
			}
		}
		else if (IsKeyPressed(KEY_DOWN))
		{
			if (inner - 5 >= 40)
			{
				inner -= 5;
				distance = outer - inner;
				angle = 0;
			}
		}
		// up increases size of inner blue circle and down decreases size, adds limits so it never becomes bigger than outer circle
		// and so it can always work no matter how small or big

		if (IsKeyPressed(KEY_D))
		{
			colorIndex++;

			if (colorIndex >= 6)
			{
				colorIndex = 0;
			}

			angle = 0;
		}
		else if (IsKeyPressed(KEY_A))
		{
			colorIndex--;

			if (colorIndex < 0)
			{
				colorIndex = 5;
			}

			angle = 0;
		}
		// added controls to change colors and limits so if values goes to far, loop around

		float innerX = xCoordinate + cos(DEG2RAD * angle) * (distance);
		float innerY = yCoordinate - sin(DEG2RAD * angle) * (distance);

		float drawAngle = -(distance) / inner * angle;
		// tells us how quickly the green dot needs to rotate relative to the blue circle's movement
		// the negative sign makes its rotation go in the opposite direction

		// now we do for the inner drawing circle!
		float drawX = innerX + cos(DEG2RAD * drawAngle) * innerDrawCircle;
		float drawY = innerY - sin(DEG2RAD * drawAngle) * innerDrawCircle;

		// calculate new angle for inner circle for the drawing part


		BeginDrawing();
		ClearBackground(RAYWHITE);

		float previousX = xCoordinate + distance + innerDrawCircle;
		float previousY = yCoordinate;

		for (float i = 0; i < angle; i += 1)
		{
			float innerX2 = xCoordinate + cos(DEG2RAD * i) * distance;
			float innerY2 = yCoordinate - sin(DEG2RAD * i) * distance;

			float drawAngle2 = -distance / inner * i;

			float drawX2 = innerX2 + cos(DEG2RAD * drawAngle2) * innerDrawCircle;
			float drawY2 = innerY2 - sin(DEG2RAD * drawAngle2) * innerDrawCircle;

			DrawLine(previousX, previousY, drawX2, drawY2, colors[colorIndex]);

			previousX = drawX2;
			previousY = drawY2;
		}
		// loop through all previous angles to redraw the spirograph lines
		// calculate green dot position at each angle and connect it to previous position
		// save current position as previous for next loop
		// keeps all lines visible even though background clears every frame


		DrawCircleLines(xCoordinate, yCoordinate, outer, RED);

		DrawCircleLines(innerX, innerY, inner, BLUE);
		DrawCircle(drawX, drawY, 5, colors[colorIndex]);
		// replace green circle code with this now


		EndDrawing();
		angle += speed;
	}

	CloseWindow();

}

int main()
{

	SpiroGraph();

	return 0;
}