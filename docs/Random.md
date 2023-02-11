**Header File**: 
```cpp 
#include "Random.h"
```

**Namespace**
```cpp
namespace Awnd;
```

<h2>Description</h2>
<hr>

The `Random` class contains static methods that generates pseudo-random numbers

<h2>Static Members</h2>
<hr>

```cpp
static int Integer();
```
**Description:**

Returns a random Integer

```cpp
static uint32_t UInt();
```
**Description:**

Returns a random uint32_t Integer

```cpp
static float Float();
```

**Description:**

Returns a random float


<h2>Code Example</h2>
<hr>

```cpp
int main(){
    // Required to make pseudo-random numbers
    Awnd::EnableRandom();
    
    uint32_t num = Awnd::Random::UInt();
    std::cout << num << std::endl;

    return 0;
}
```