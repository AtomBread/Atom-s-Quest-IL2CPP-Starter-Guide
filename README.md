# Atom's Quest IL2CPP Starter Guide
How to start making mods for the Quest or Quest 2

### This guide will show and explain how to make beginner mods for the Quest

#### What you will need

1. Somewhat knowledge of C++
2. A sideload ready PC/Quest
3. Around 10 minutes of your time reading
4. A link cable ( can be the one that came with quest )
5. A Pc with a Cable-C port
6. Visual Studio Code
7. Unity Installed With Android Support ( for NDK )
7. Bread

### Let's Begin
#### Basic Understanding of IL2CPP

IL2CPP converts IL ( Intermediate Language, what c# compiles too ) to CPP ( C++ )
most developers do this as they think it will make their game run faster and also have protection against cheaters/hackers, this is sometimes right, but most of the time its usless

#### How our cheat code will interfere with the compiled IL2CPP

When your interfering with Unity's Engine every GameObject, Class, Component, Object and every thing that was in the scenes hierarchy at build has a **instance** which is a pointer to that exact object at that time, we can use this to contact a script during run-time and change any of its fields to our command.

#### How are these instances represented at run-time

An instance of any object is delcared a **Il2CppObject**, if we have a **Il2CppObject** we can change an value in it.
**For example** if our game we're cheating on is GorillaLocomotion based game ( Bird Runners, Monkey Mischief ) then we could ( for example ) make our selfs zero gravity or make us super fast/powerful.
We could make ourselfs fast with **il2cpp_utils::SetFieldValue(self, "maxJumpSpeed", 100.0f)**, which changes a property of our player ( maxJumpSpeed ), which uses a provided **Il2CppObject**, which we can get by making a hook.

#### Hooks?

Hooks are pieces of code which latch onto the Game Engine ( Unity ) and let us interfere with shit. if you hook find a instance ( lets say GorillaLocomotion.Player ) the code will wait untill a Component is added to the game ( Player is spawned ) and then it hooks/ latches on to the Player giving us a **Il2CppObject** which would probably be our player. **Then we could start to mess around**

#### How do i accualy do all this?

The first thing to do is set up a new Beat Saber Hook Project which you can do is 

1. Get qpm-rust
2. Get CMake
3. Clone this repository
4. Open the folder with this repository
5. Open powershell
6. Do "cd THE_DIRECTORY_OF_THE_FOLDER"
7. Do qpm restore
8. Eat Bread
9. Open "ndkpath.txt" in the repo folder
10. Goto the installation of your unity
11. Open the folders Editor/Data/PlayBackEngines/AndroidPlayer/NDK
12. Click on the bit at the top of file explorer that says This PC
13. Highlight it then copy it
14. Paste it into the txt you opened called "NDKPath"
15. Save The txt
16. Open Visual Studio Code
17. Click File in top left
18. Click Open Folder
19. Goto the repos folder
20. Open it
21. Open the sub folder "src" in Visual Studio Code
22. Open main.cpp
23. Get ready to code!

#### Starting To Code The Mod

Now that we somewhat know how IL2CPP works lets begin the mayhem!

##### Finding Methods, Fields, Values to change

You could use **IL2CPPInspecter, IL2CPPDumper and IL2CPPUnHollower** if you dont know any fields or methods
but if you do this is how to run/ edit them

##### Changing the Current Hook

To make a hook you must know the namespace, class name and the method to hook in within the class, **for example** GorillaLocomotion based games usally have the player script like this, (sus, "GorillaLocomotion", "Player", "Awake", void, Il2CppObject* self) if its for that type of game leave it
![](https://i.imgur.com/y4ocskb.png)

