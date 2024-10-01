# Nimble

Game where you eat smaller circles and grow, however be careful of touching the larger ones!

<sup></sub>Very original, yes... Actually i didn't get the idea from agar.io, it comes from some different web game that I used to play when I was smaller but lost the url since then.</sub></sup>

# Screenshots

https://user-images.githubusercontent.com/87543374/183166860-dd0db641-98ae-4d58-a7c8-1a2eed5a959a.mp4

## Compiling

### Windows

Execute the following command in the project's root directory:

```
g++ -c src/*.cpp -Wall -m64 -I include -I <SFML-PATH>/include && g++ *.o -o bin/release/main.exe -L <SFML-PATH>/lib -mwindows -lsfml-graphics -lsfml-window -lsfml-system
```

After compiling, you need to include the `config.cfg` file, the `fonts/` folder and the needed SFML `.dll` files into the `.exe` directory for it to run.

## Background

This is my first ever c++ project, actually when I started I didn't even know c++.\
So please take the code with a grain of salt ;)
