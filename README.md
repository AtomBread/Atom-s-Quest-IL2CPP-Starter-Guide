# Atom's Quest IL2CPP Starter Guide
How to start making mods for the Quest or Quest 2

### This guide will show and explain how to make beginner mods for the Quest

#### What you will need

1. Somewhat knowledge of C++
2. A sideload ready PC/Quest
3. Around 10 minutes of your time reading
4. A link cable ( can be the one that came with quest )
5. A Pc with a Cable-C port
6. Bread

### Let's Begin
#### Basic Understanding of IL2CPP

IL2CPP converts IL ( Intermediate Language, what c# compiles too ) to CPP ( C++ )
most developers do this as they think it will make their game run faster and also have protection against cheaters/hackers, this is sometimes right, but most of the time its usless

##### How our cheat code will interfere with the compiled IL2CPP

When your interfering with Unity's Engine every GameObject, Class, Component, Object and every thing that was in the scenes hierarchy at build has a **instance** which is a pointer to that exact object at that time, we can use this to contact a script during run-time and change any of its fields to our command.

##### How are these instances represented at run-time

An instance of any object is delcared a **Il2CppObject**, if we have a **Il2CppObject** we can change an value in it.
**For example** if our game we're cheating on is GorillaLocomotion based game ( Bird Runners, Monkey Mischief ) then we could ( for example ) make our selfs zero gravity or make us super fast/powerful.
We could make ourselfs fast with **il2cpp_utils::SetFieldValue(self, "maxJumpSpeed", 100.0f)**
