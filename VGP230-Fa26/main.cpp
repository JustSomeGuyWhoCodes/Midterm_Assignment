#include <raylib.h>
#include <string>
#include <cmath>
#include <raymath.h>

void FirstDrawing()
{


	InitWindow(500, 500, "My Cool Game");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{

		BeginDrawing();
		ClearBackground(RAYWHITE); // hold ctrl and click on any of these function things to see the header or something so in there we can see the list of things like commands like draw and what we can draw

		int r = 150;

		DrawCircle(250, 250, r + 20, BLACK);

		DrawCircle(250, 250, 150, BLUE);



		std::string text = "Gabriel";
		int xCen = 500 / 2;
		int yCen = 500 / 2;


		int fontSize = 60;
		int txtWidth = MeasureText(text.c_str(), fontSize);
		int halfTextWidth = txtWidth / 2;

		// font size is height
		// width is... we didnt catch it


		int txtCenX = xCen - halfTextWidth;
		int txtCenY = yCen - fontSize / 2;



		//octagon 5 sided shape

		int num = ((360 / 5) / 2) / 2;
		Vector2 center = Vector2{ (float)xCen, (float)yCen };
		DrawPoly(center, 5, r, -num, ORANGE);


		// rotating by degrees
		// 360 in a circle
		// pentagon has 5 corners so divide by 5
		// its like a bunch of triangles,, so degrees between each triangle is 360/5
		// each rotation is 72,



		DrawPolyLinesEx(center, 5, r, -18, 20, BLACK);

		DrawText(text.c_str(), txtCenX, txtCenY, fontSize, RED);
		// DrawText("Gabriel", 250, 250, 20, RED); // this also works










		EndDrawing();
	}


	CloseWindow();

	// s
}



void TemplateFunc()
{


	InitWindow(500, 500, "My Cool Game");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		EndDrawing();
	}


	CloseWindow();
}



void MovingBall()
{

	int width = 800;
	int height = 500;
	InitWindow(width, height, "Bouncing Ball Game!");

	int r = 50;
	int speed = 2;
	int centerX = r;
	int centerY = height/2;

	SetTargetFPS(60);

	

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);



		for (int i = 10; i > 0; i--)
		{
			//         cenX - Gap - 
			DrawCircle(centerX - i * speed * 5, centerY, r, Color{ 0,0,255, (unsigned char) (255-25*i) }); // have to cast it because the program doesnt like non direct values here
		}
		DrawCircle(centerX, centerY, r, BLUE);
		centerX += speed;



		EndDrawing();

		if (centerX > width + r)
		{
			centerX = -r;
		}


		
	}


	CloseWindow();
}


void BallsAssignment()
{

	int width = 500;
	int height = 500;
	InitWindow(width, height, "Ball Arena");

	int r = 5;
	int speedx = 4;
	int speedY = 8;
	int centerX = r;
	int centerY = height / 2;


	// red ball

	int redR = 5;
	int redSpeedx = -2;
	int redSpeedY = -11;
	int redCenterX = width - r;
	int redCenterY = height - (height / 2);

	SetTargetFPS(60);



	bool xPos = true;
	bool yPos = true;


	bool redXPos = true;
	bool redYPos = true;



	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		
		DrawCircle(centerX, centerY, r, BLUE);
		
		if (xPos == true)
		{
			centerX += speedx;
		}
		else
		{
			centerX -= speedx;
		}

		if (yPos == true)
		{
			centerY+= speedY;
		}
		else
		{
			centerY -= speedY;
		}
		//centerX += speed;
		//centerY += speed;



		//EndDrawing();

		if (centerX + r >= width)
		{
			xPos = false;
		}
		if (centerY + r >= height)
		{
			yPos = false;
		}


		if (centerX - r <= 0)
		{
			xPos = true;
		}
		if (centerY - r <= 0)
		{
			yPos = true;
		}



		//Red Ball


		DrawCircle(redCenterX, redCenterY, redR, RED);

		if (redXPos == true)
		{
			redCenterX -= redSpeedx;
		}
		else
		{
			redCenterX += redSpeedx;
		}

		if (redYPos == true)
		{
			redCenterY -= redSpeedY;
		}
		else
		{
			redCenterY += redSpeedY;
		}
		//centerX += speed;
		//centerY += speed;



		EndDrawing();

		if (redCenterX + redR >= width)
		{
			redXPos = false;
		}
		if (redCenterY + redR >= height)
		{
			redYPos = false;
		}


		if (redCenterX - redR <= 0)
		{
			redXPos = true;
		}
		if (redCenterY - redR <= 0)
		{
			redYPos = true;
		}


		/*
		
		if ((centerX + r) - (redCenterX - r) <= 0 && ((centerY + r) - (redCenterY - r)) <= 0)
		{
			centerX = 600;
			redCenterX = 600;
		}
		
		*/

		int dx = centerX - redCenterX;
		int dy = centerY - redCenterY;
		
		// we are using pythagoreas theorem to find the slope part which is the distance between the two objects
		float distance = sqrt(dx * dx + dy * dy);

		if (distance <= r + redR)  // so each radius is 25, so it needs at least 50 which is both added together, if its more than 50, not touching, less than 50, they are touching
		{
			centerX = 600;
			redCenterX = 600;
		}

	}


	CloseWindow();
}

//a

void TriangleFunc()
{

	int wh = 800;
	InitWindow(800, 800, "My Cool Game");
	SetTargetFPS(10);

	Vector2 top = Vector2{ (float)wh / 2,100 };
	Vector2 left = Vector2{ 100, (float)wh - 100 };
	Vector2 right = Vector2{ (float)wh - 100, (float)wh - 100 };

	float r = 20;

	int isDragging = 0;

	while (!WindowShouldClose())
	{
		Vector2 mouse = GetMousePosition();

		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			// The distance of the mouse position against the top circle
			float topDist = Vector2Distance(mouse, top);
			float leftDist = Vector2Distance(mouse, left);
			float rightDist = Vector2Distance(mouse, right);


			/*
			if (topDist < r)top = mouse;
			else if (leftDist < r)left = mouse;
			else if (rightDist < r)right = mouse;
			*/

			if (topDist < r) isDragging = 1;
			else if (leftDist < r) isDragging = 2;
			else if (rightDist < r) isDragging = 3;

			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) isDragging = 0; 
			// abcde
			// a
			switch (isDragging)
			{

			case 1: top = mouse; break;
			case 2: left = mouse; break;
			case 3: right = mouse; break;

			default:
			break;
			}

		}

		BeginDrawing();
		ClearBackground(GRAY);

		DrawTriangleLines(left, right, top, BLACK);

		// float gap = 200;
		DrawCircleV(top, r, BLUE);
		DrawCircleV(left, r, GREEN);
		DrawCircleV(right, r, RED);

		EndDrawing();
	}


	CloseWindow();
}

void ColorAddition()
{

	int wh = 800;
	float r = 300;

	InitWindow(800, 800, "My Cool Game");
	SetTargetFPS(10);

	Vector2 top = Vector2{ (float)wh / 2, r};
	Vector2 left = Vector2{ r, (float)wh - r };
	Vector2 right = Vector2{ (float)wh - r, (float)wh - r };


	int isDragging = 0;

	while (!WindowShouldClose())
	{
		
		BeginDrawing();
		ClearBackground(GRAY);

		BeginBlendMode(BLEND_ADDITIVE);

		DrawCircleV(top, r, BLUE);
		DrawCircleV(left, r, GREEN);
		DrawCircleV(right, r, RED);
		EndBlendMode();

		EndDrawing();
	}

	CloseWindow();
}

void TestFunc()
{


	InitWindow(800, 800, "My Cool Game");
	SetTargetFPS(30);

	float r = 50;
	float x = 400;
	float y = 400;

	float inc = 1;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawCircle(x, y, r, BLUE); // dead center
		//amb c
		float angle = 45; 
		x -= cos(DEG2RAD * angle) * inc; // does degree to radians, DEG2RAD    //  1/2
		y -= sin(DEG2RAD * angle) * inc; // (root 3) / 2
		EndDrawing();
	}


	CloseWindow();
}



void OctagonFunc()
{

	int wh = 800;
	InitWindow(800, 800, "My Cool Game");
	SetTargetFPS(10);

	float lineDistance = 200;

	/*
	 
	float angle = 45;
	x -= cos(DEG2RAD * angle) * inc; // does degree to radians, DEG2RAD    //  1/2
	y -= sin(DEG2RAD * angle) * inc; // (root 3) / 2
	
	*/

	Vector2 middle = Vector2{ (float)wh / 2, (float)wh / 2 };
	Vector2 pointOne = Vector2{ ((float)wh / 2) + lineDistance, (float)wh / 2 };

	float angle = 45;
	float x = (wh / 2) + (cos(DEG2RAD * angle) * lineDistance) ;
	float y = (wh / 2) - (sin(DEG2RAD * angle) * lineDistance);

	Vector2 pointTwo = Vector2{ x,y };

	// testing for second triangle


	Vector2 middle2 = Vector2{ (float)wh / 2, (float)wh / 2 };
	Vector2 pointOne2 = Vector2{ x,y };

	float angle2 = 90;
	float x2 = (wh / 2) + (cos(DEG2RAD * angle2) * lineDistance);
	float y2 = (wh / 2) - (sin(DEG2RAD * angle2) * lineDistance);

	Vector2 pointTwo2 = Vector2{ x2,y2 };


	// lets try and make a loop for this, make a new function



	while (!WindowShouldClose())
	{

		

		BeginDrawing();
		ClearBackground(GRAY);

		DrawTriangleLines(middle, pointOne, pointTwo, BLACK);
		DrawTriangleLines(middle2, pointOne2, pointTwo2, BLACK);

		
		EndDrawing();
	}


	CloseWindow();
}



void OctagonLoopFunc()
{

	int wh = 800;
	InitWindow(800, 800, "My Cool Game");
	SetTargetFPS(10);

	float lineDistance = 200;

	Vector2 pointStorage = Vector2{ 1,1 }; // placeholder numbers, can be anything, they will be overwritten 
	
	Vector2 middle = Vector2{ (float)wh / 2, (float)wh / 2 };
	Vector2 pointOne = Vector2{ ((float)wh / 2) + lineDistance, (float)wh / 2 };

	float angle = 45;
	float x = (wh / 2) + (cos(DEG2RAD * angle) * lineDistance);
	float y = (wh / 2) - (sin(DEG2RAD * angle) * lineDistance);

	Vector2 pointTwo = Vector2{ x,y };

	while (!WindowShouldClose())
	{



		BeginDrawing();
		ClearBackground(GRAY);


		for (int i = 0; i < 8; i++)
		{
			


			pointStorage = pointTwo;

			DrawTriangleLines(middle, pointOne, pointTwo, BLACK);

			pointOne = pointStorage;
			angle += 45;
			x = (wh / 2) + (cos(DEG2RAD * angle) * lineDistance);
			y = (wh / 2) - (sin(DEG2RAD * angle) * lineDistance);
			pointTwo = Vector2{ x,y };

		}



		DrawTriangleLines(middle, pointOne, pointTwo, BLACK);


		EndDrawing();
	}


	CloseWindow();
}

int main()
{

	OctagonLoopFunc();

	return 0;
}