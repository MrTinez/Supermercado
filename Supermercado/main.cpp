#include "olcPixelGameEngine.h"

/*CONSTANTS*/



class Supermercado : public olc::PixelGameEngine
{
public:
	Supermercado()
	{
		sAppName = "Supermercado - by Mr. Tinez";
	}
	int pScreenWidth = 800;
	int pScreenHeight = 600;
	int pScale = 1;

	int maxButtons = 3; 

	/*TODO: Separar todo en clases*/
	std::unique_ptr<bool[]> buttons;
	std::unique_ptr<olc::Pixel[]> colorButtons;

	/* Panel */
	olc::vi2d panelPixelPosition = { 40 , 450 };
	olc::vi2d panelPixelSize = { 720 , 130 };


	/* Botones */
	olc::vi2d buttonPixelPosition = { 60 , 470 };
	olc::vi2d buttonPixelSize = { 185 , 100 };




public:
	bool OnUserCreate() override
	{
		buttons = std::make_unique<bool[]>(maxButtons);
		colorButtons = std::make_unique<olc::Pixel[]>(maxButtons);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::DARK_BLUE);
		FillRect(panelPixelPosition, panelPixelSize, olc::WHITE);

		/*User Inputs*/
		/*TODO: SUPER SUCIO, LIMPIALO, IMBÉCIL*/
		/*TODO: Buscar documentación del GetKey*/
		if (GetKey(olc::Key::K1).bPressed)
		{
			buttons[0] = true;
			buttons[1] = false;
			buttons[2] = false;
		}

		if (GetKey(olc::Key::K2).bPressed)
		{
			buttons[0] = false;
			buttons[1] = true;
			buttons[2] = false;
		}

		if (GetKey(olc::Key::K3).bPressed)
		{
			buttons[0] = false;
			buttons[1] = false;
			buttons[2] = true;
		}

		for (int i = 0; i < maxButtons; i++)
		{
			if (buttons[i])
			{
				colorButtons[i] = olc::RED;
			}
			else
			{
				colorButtons[i] = olc::CYAN;
			}
		}

		/*TODO: No mames, optimiza esto, se ve horrible hdlv. >:(*/
		FillRect((buttonPixelPosition.x), buttonPixelPosition.y, buttonPixelSize.x, buttonPixelSize.y, colorButtons[0]);
		FillRect((buttonPixelPosition.x * 2) + buttonPixelSize.x, buttonPixelPosition.y, buttonPixelSize.x, buttonPixelSize.y, colorButtons[1]);
		FillRect((buttonPixelPosition.x * 3) + (buttonPixelSize.x * 2), buttonPixelPosition.y, buttonPixelSize.x, buttonPixelSize.y, colorButtons[2]);
		return true;
	}

};

int main()
{
	Supermercado pantallaPrincipal;
	if ( pantallaPrincipal.Construct(pantallaPrincipal.pScreenWidth, pantallaPrincipal.pScreenHeight, 
		pantallaPrincipal.pScale, pantallaPrincipal.pScale) )
	{
		pantallaPrincipal.Start();
	}

	return 0;
}