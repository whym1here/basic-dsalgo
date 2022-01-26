# Adding Debugging Header to your template
```cpp
#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include<algo/debug.h>
#endif

int main(){
    vector<int> a(10);
    iota(a.begin(), a.end(), 1LL);
    // for such clean code and dbg to work
    dbg(a);
    return 0;
}
```

## Windows
1. Navigate to ```MinGW\include\c++\11.2.0\x86_64-w64-mingw32``` or search ```stdc++.h``` .
2. Create a folder with name **algo**.
3. Paste the file **debug.h** into the folder.

## Linux
1. Navigate to ```/usr/include/c++/9/algo``` or whatever version you are on.
2. Create a folder with name **algo** (with sudo permission).
3. Paste the file **debug.h** into the folder (with sudo permission).

## Compiler Flags
Codeforces Blog : [Compiler Flags](https://codeforces.com/blog/entry/15547)
- ```-std=c++2a``` : for C++20
- ```-Wall``` : basic warnings
- ```-Wextra``` : basic warnings
- ```-Wshadow``` : warns if a declared name shadows the same name in some outer level
- ```-Wconversion``` :  warns if data can be lost in an implicit conversion
- ```-fsanitize=address``` : this option inserts memory access checks into the program, such as checks for out-of-bounds accesses
- ```-fsanitize=undefined -fno-sanitize-recover``` : a similar option that catches undefined behavior, for example, a null pointer dereference
- ```-fstack-protector``` : stack protection
- ```-O2``` : Optimization Flag

# Setting-up IDE for new header 

## VS Code (Code Runner)
Add this to your settings.json
```json
"code-runner.executorMap": {
    "cpp": "g++ -std=c++2a -DLOCAL $fullFileName -o $fileNameWithoutExt && ./$fileNameWithoutExt"
}
```
or
```json
    "code-runner.executorMap": {
        "cpp": "g++ -std=c++2a -DLOCAL -Wall -Wextra -Wshadow -Wconversion -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -O2 $fullFileName -o $fileNameWithoutExt && ./$fileNameWithoutExt"
    }
```
