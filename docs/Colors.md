**Header File**: 
```cpp 
#include "Awnd.h"
```

**Namespace**
```cpp
namespace Awnd;
```

<h2>Description</h2>
<hr>

The `Color` class contains everything you need to make a RGB color.

<h2>Public Members</h2>
<hr>

**Constructors**
```cpp
Color();
Color(int red, int green, int blue);
```

**Operators**

`<<`

**Functions**

```cpp
void SetColor(int r, int g, int b);
```
**Description:**

Sets the color value.

**Parameters:**

`r` - red channel<br>
`g` - green channel<br>
`b` - blue channel

```cpp
int GetRed() const
```
**Description:**

Returns the red channel value

```cpp
int GetGreen() const
```
**Description:**

Returns the green channel value

```cpp
int GetBlue() const
```
**Description:**

Returns the blue channel value


```cpp
int r, g, b
```

**Description:**

the 3 color channels.

<h2>Code Example</h2>
<hr>

```cpp
int main(){
    Awnd::Color red(255, 0, 0);
    std::cout << Color(100, 0, 150) << ", " << red << std::endl;
    // Output: "100, 0, 150, 255, 0, 0"

    return 0;
}
```