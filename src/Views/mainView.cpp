#include "background.h"
#include <texture.h>
#include "mainView.h"

MainView::MainView()
{
}

int MainView::HandleInput(int focus, const Input& input)
{
	categoryView.HandleInput(focus, input);
}

int MainView::Display()
{
	background.Display();
	categoryView.Display();
	statusBar.Display();
	return 0;
}
