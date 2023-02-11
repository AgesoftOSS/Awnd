**Header File**: 
```cpp 
#include "Awnd.h"
```

<h2>Description</h2>
<hr>

The `App` class contains the nessesary methods for creating a application using Awnd. to access the methods you have to inheriate it in your own class

<h2>Protected Functions</h2>
<hr>

```cpp
virtual void onApplicationCreate(float e_Time) 
virtual void onApplicationCreate()
```

**Description:**

needs to be overriden in your own class. by default it exits the application

**Parameter:**

`float e_Time` - The render time of the frame

```cpp
void HideConsole()
```
**Description:**

Hides the console.

```cpp
long GetScreenWidth()
```

**Description:**

returns the width of the screen

```cpp
long GetScreenHeight()
```

**Description:**

returns the height of the screen

<h2>Code Example</h2>
<hr>

```cpp
class SampleApp : public App {
public:

    long Sw = ScreenWidth();
    long Sh = ScreenHeight();

    void PrintValues(long x, long y){
        std::cout << "Screen Resolution: " << x << ", " << y << std::endl;
    }
}
```