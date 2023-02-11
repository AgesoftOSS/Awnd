# Awnd
Awnd is a free & open source lightweight c++ framework for easily creating components and win32 applications.

*Here at agesoft we like to use our own products. we really avoid third party libraries that can ruin our projects.*

***If you use Awnd please credit @Copy05 or @AgesoftOSS***

# Features
<h2>Command Handling</h2>

With Awnd you don't have to go to the `WindowProc` to handle the commands you need<br><br> 
<h2>Creating Controls Easy</h2>

inside the `Awnd` namespace there are some control classes you can use to create the controls you need<br><br> 
<h2>Object Orientated</h2>

since this is c++ Awnd is very object orientated when it's about controls.<br><br> 
<h2>Helpful Utilities</h2>

Awnd has more than just Win32 specialized content. it has content for Console Development too.
<br><br><br> 

# Examples

**Creating a Win32 app**
```cpp
// Include the Awnd.h header file to get access to the Awnd namespace and to the Application.
#include "Awnd.h"

// Implement the ComponentHandler function to handle GUI Components.
void Awnd::ComponentHandler(HWND hWnd){

    // Creating a Label.
    Awnd::Label* label = new Awnd::Label(100, 300, 100, 20, L"Hello World", hWnd, (HMENU)10);
    label->append();
}

// Create a class which inheriates AwndApp for organized coding
class ExampleApp : public AwndApp {
public:
    // Manually passing the with and height
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

int main(){
    // Initalize the application and run it
    App* app = new App(1280, 720);
	app->Execute(5.0f);
	return 0;
}
```

**Pseudo-Random Numbers**

```cpp
// Include the Random header file to get access to the Random class
#include "Random.h"
#include "Awnd.h"
#include <iostream>

int main(){
    // run this function to get purely random numbers
    Awnd::EnableRandom();

    // Generates a random Integer.
	int n = Awnd::Random::Integer();
	std::cout << n << std::endl;
    Sleep(1500);
    return 0;
}
```

# Contrubution

If you like to contribute to the Awnd project open pull request and let's start coding!
