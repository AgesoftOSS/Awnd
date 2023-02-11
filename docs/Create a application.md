In this article you will learn how to create a c++ win32 application using Awnd.

1. Add the `Awnd.h` header file to your `main.cpp` file.
```cpp
#include "Awnd.h"
```
2. Create a sample class for your application. the class must inheriate from the `AwndApp` class
```cpp
class SampleApp : public App {

}
```
3. Add a constructor where you can set your width and height of your window
```cpp
class SampleApp : public App {
public:
    App(int width, int height) {
		this->w = width;
		this->h = height;
	};

private:
    int w, h;
}
```
4. Override the `onApplicationCreate()` function
```cpp
class SampleApp : public App {
public:
    App(int width, int height) {
		this->w = width;
		this->h = height;
	};

private:

	void onApplicationCreate(float e_Time) override {

	}

private:
    int w, h;
}
```

5. Create a object from the `Application` class inside the `onApplicationCreate()` function

The Application constructor we're using is this one:
```cpp
Application(LPCWSTR windowsTitle, bool fullScreen, int rectwidth = 640, int rectheight = 480)
```

```cpp
void onApplicationCreate(float e_Time) override {

		// Hidding Console Window
		HideConsole();

		// Initalizing The Application
		Application* app = new Application( (LPCWSTR)L"Hello World", false, w, h );
		app->runWindow(e_Time);
	}
```

6. Implement a function that takes a `time` floating point and that executes the `onApplicationCreate()`

```cpp
public:
    // Making a function to execute the application, time is the renderTime
	void Execute(float time) {
		onApplicationCreate(time);
    }
```

7. Implement the `Awnd::ComponentHandler()` function.

The function is defined but empty. Awnd does handle the component creation. all you have to do is to implement the `Awnd::ComponentHandler()`

```cpp
void Awnd::ComponentHandler(HWND hWnd){

}
```
Let's add a `Button` component! we will use this constructor:

```cpp
Button(int x, int y, int width, int height, LPCWSTR text, HWND hwnd, HMENU Id);
```

```cpp
// Define a MACRO for your button ID
#define IDC_BUTTO 11

void Awnd::ComponentHandler(HWND hWnd){
	// Creates the Button
    Awnd::Button* btn = new Awnd::Button(100, 300, 100, 20, L"Hello World", hWnd, (HMENU)IDC_BUTTO);
	
	// And then append it to the frame.
    btn->append();
}
```
8. The application seems boring. Let's add Command Handling. Implement the `Awnd::CommandHandler(WPARAM wParam)` function

We're using Awnd's `OnClick` macro to add a click event for our button.

```cpp
void Awnd::CommandHandler(WPARAM wParam) {

	// If the Button is Pressed the application exits.
	if (OnClick(wParam, IDC_BUTTO))
		exit(0);
}
```

9. **Almost done!** now create a object of your class in your entry point

```cpp
int main(){
    // Initalize the application and run it
    App* app = new App(1280, 720);
	app->Execute(5.0f);
	return 0;
}
```

10. You're finished!