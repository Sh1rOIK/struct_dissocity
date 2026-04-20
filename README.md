# Struct_dissociaty
Language: C++
Type: Console Application / Class Library

Description
A project for modeling, managing and logging the states of "alter personalities" (internal parts of the system). Implements the "Registry" pattern with static object storage and the ability to save/load state.

Functionality
Creating alter objects (default constructors and with parameters).

Setting the name and function (setAlters).

Counting the number of times an object has been accessed (callCounter).

Static registry of all created objects (all_alters).

View all the alterations (showAlter).

Saving all the alterations to a file (saveAllToFile).

Downloading alterations from a file (LoadFromFile).

Using
Add alterers via struct_dissociaty::addAlter(name, func).

View the list using struct_dissociaty::showAlter().

Save the state to a file for later download.  
