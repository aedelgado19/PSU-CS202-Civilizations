# PSU-CS202-Civilizations
For this project, the goal was to create a text-based game about different civilizations to demonstrate **dynamic binding**. 
We had to implement three different types of unique civilizations, which are inherited from an **abstract base class** (Civilization).
This base class uses **virtual functions** such as buy(), sell(), and trade() and has protected information regarding the civilization's resources.

Civilizations are stored as nodes in a **doubly linked list.**

Notes on **time analysis** of data structure:
- O(1) time for accessing head pointer (stored for in DLL)
- O(N) time when program required a search through all nodes, worst case traversal
