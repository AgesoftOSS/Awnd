/*
	Awnd_Example.cpp
	Copyright Agesoft 2021-2023

	This C++ file explains you how you can use Awnd to create a simple application
	
	This Example covers:
	- Handling Components
	- Handling Commands
	- Creating a simple application
	- Creating a Awnd::Button
	- Awnd onClick event

*/


// Include the Awnd.h header file to get access to the Awnd namespace and to the Application.
#include "Awnd.h"

// Define a macro for the ID of the button
#define IDC_BUTTO 11

// Implement the ComponentHandler function to handle GUI Components.
void Awnd::ComponentHandler(HWND hWnd){
    // Creates the Button
    Awnd::Button* btn = new Awnd::Button(100, 300, 100, 20, L"Hello World", hWnd, (HMENU)IDC_BUTTO);
	
	// And then append it to the frame.
    btn->append();
}

// Implement the CommandHandler function to handle Control events. (for example click event)
void Awnd::CommandHandler(WPARAM wParam) {
	// If the Button with the ID IDC_BUTTO (11) get's clicked the application Exits.
	// For click events Awnd provides a OnClick(wParam, ID) Macro.
	if (OnClick(wParam, IDC_BUTTO))
		exit(0);
}

// Create a class which inheriates AwndApp for organized coding
class ExampleApp : public AwndApp {
public:
    // A constructor to manually passing the with and height
	App(int width, int height) {
		this->w = width;
		this->h = height;
	};
private:
    // overriding the onApplicationCreate function or else the application will close on run
	void onApplicationCreate(float e_Time) override {

		// Hidding Console Window
		HideConsole();

		// Initalizing The Application
		Application* app = new Application( (LPCWSTR)L"Hello World", false, w, h );
		app->runWindow(e_Time);
	}

public:
    // Making a function to execute the application, time is the renderTime
	void Execute(float time) {
		onApplicationCreate(time);
    }
private:
	int w, h;
}

// Awnd is designed to work with console applications. 
int main(int argc, char** argv){

    // Initalize the application and run it
    App* app = new App(1280, 720);
	app->Execute(5.0f);
	return 0;
}