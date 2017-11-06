//
//  main.cpp
//  Game2
//
//  Created by Mitchell Reinitz on 10/2/17.
//  Copyright © 2017 Mitchell Reinitz. All rights reserved.
//
#include <iostream>
#include <string>

using namespace std;
int main() // the code was generally cleaned up after suggestions from the code review
{
    string location = "start";
    string choice = "";
    int map = 0;
    int gas = 0;
    int health = 3;
    int saw = 0;
    while (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit") // *from Olivia - I tested the quit choice and it doesnt seem to be working you may want to look at it. I would have fixed it, but I didn't know what was wrong, sorry.
    {
       
        if (location == "start") // beginning starting position
        {
            cout << "You are in the middle of a forest. You see a trail to the north. The trail runs east to west. You want to go home. \n";
            cout << ">";
            cin >> choice;
            if (choice == "north" || choice == "North" || choice == "n" || choice == "N") // if player chooses this, they go to the beginning of the trail (trail)
            {
                location = "trail";
            }
            else if (choice == "south" || choice == "South" || choice == "s" || choice == "S") // player went south at the start of the game (southcliff)
            {
                location = "southcliff";
            }
           else if (choice == "west" || choice == "West" || choice == "w" || choice == "W") // player went west at the start of the game (westcliff)
            {
                location = "westcliff";
            }
            else if (choice == "east" || choice == "East" || choice == "e" || choice == "E") // player went east at the start of the game (eastcliff)
            {
                location = "eastcliff";
            }
            else if (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
        
        
        
        else if (location == "southcliff") // here, they find a saw which they will need to cut apart the tree on 40A
        {
            saw = 1;
            cout << "You headed south. You found and picked up a saw. \n";
            cout << ">";
            cin >> choice;
             if (choice == "north" || choice == "North" || choice == "n" || choice == "N") // *from Olivia - I made everything I could have 4 different choices that would work. All of them are similar to this line here.
            {
                location = "start";
            }
           else if(choice == "south" || choice == "South" || choice == "s" || choice == "S")
            {
                health = 0; // they fell off the cliff
            }
           else if (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
        
        
        
        
        else if (location == "eastcliff") // here, they are sent back to the start of the game
        {
            cout << "You headed east. You encounter a cliff. \n";
            cout << ">";
            cin >> choice;
            if (choice == "west" || choice == "West" || choice == "w" || choice == "W")
            {
                location = "start";
            }
            else if (choice == "east" || choice == "East" || choice == "e" || choice == "E")
            {
                health = 0; // they fell off the cliff
            }
            else if (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
        
        
        
        else if (location == "westcliff") // here, they are sent back to the start of the game
        {
            cout << "You headed west. You encounter a cliff. \n";
            cout << ">";
            cin >> choice;
            if (choice == "east" || choice == "East" || choice == "e" || choice == "E")
            {
                location = "start";
            }
            else if (choice == "west" || choice == "West" || choice == "w" || choice == "W")
            {
                health = 0; // they fell off the cliff
            }
            else if (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
        
        
        
        else if (location == "trail") // they are at the beginning of the trail. if they go west, they should be at trailblazer 42 and if they go east they should be at trailblazer 41. 41 should fork into A and B.
        {
            cout << "You are at the beginning of the trail. \n";
            cout << ">";
            cin >> choice;
            if (choice == "east" || choice == "East" || choice == "e" || choice == "E")
            {
                location = "trailblazer41";
            }
            else if (choice == "west" || choice == "West" || choice == "w" || choice == "W")
            {
                location = "trailblazer42";
            }
            else if (choice == "south" || choice == "South" || choice == "s" || choice == "S")
            {
                location = "start";
            }
            else if (choice == "north" || choice == "North" || choice == "n" || choice == "N")
            {
                cout << "Watch your step. \n";
                health = 0;
            }
            else if (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
             
                
                
        else if (location == "trailblazer40B") // if the player went left at the fork, they come here
        {
            cout << "You are at Trailblazer 40B. \n";
            cout << ">";
            cin >> choice;
            if (choice == "west" || choice == "West" || choice == "w" || choice == "W")
            {
                location = "trailblazer41";
            }
            else if (choice == "east" || choice == "East" || choice == "e" || choice == "E")
            {
                location = "field";
            }
            else if (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
                
        
                
        else if (location == "trailblazer40A") // if they go right at the fork, they will end up here
        {
            cout << "You are at Trailblazer 40A \n";
            cout << ">";
            cin >> choice;
            if (choice == "east" || choice == "East" || choice == "e" || choice == "E")
            {
                location = "blockedtrail";
            }
            else if (choice == "west" || choice == "West" || choice == "w" || choice == "W")
            {
                location = "trailblazer41";
            }
            else if (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit")
            {
                cout << "That is irrelevant. \n";
            }
        }
                
            
                
             
        else if (location == "blockedtrail") // They cannot pass here unless they have a saw. They need to noget a map to find an alternate route
        {
            if (saw == 0)
            {
                cout << "You have come across a tree in your way. As of now, you do not know of a way to get around it. Where would you like to go? \n";
                cout << ">";
                cin >> choice;
                if (choice == "west" || choice == "West" || choice == "w" || choice == "W")
                {
                    location = "trailblazer40A";
                }
            }
            else if (saw == 1)
            {
                location = "parkinglot";
            }
            else if (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit")
            {
                cout << "That is irrelevant. \n";
            }
        }
           
        
        
        else if (location == "parkinglot") // Once they find the saw, they will be able to cut apart the debris at blockedtrail and arrive here
        {
            cout << "You cut the tree out of your way and you see a car! Would you like to investigate it? \n";
            cout << ">";
            cin >> choice;
            if (choice == "yes" || choice == "Yes" || choice == "y" || choice == "Y")
            {
                location = "car";
            }
            else if (choice == "no" || choice == "No" || choice == "n" || choice == "N")
            {
                cout << "Would you like to go west?";
                if (choice == "yes" || choice == "Yes" || choice == "y" || choice == "Y")
                {
                    location = "blockedtrail";
                }
                else if (choice == "no" || choice == "No" || choice == "n" || choice == "N")
                {
                    location = "parkinglot";
                }
            }
            else if (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
                
        else if (location == "trailblazer42") // if the player goes west from the start of the trail, they come here and they should pick up a map here
        {
            cout << "You are at Trailblazer 42. You see a man here. You may approach him. \n";
            cout << ">";
            cin >> choice;
            if (choice == "approach" || choice == "Approach" || choice == "a" || choice == "A")
            {
                map = 1;
                cout << "You now have a map. After reading it, you realize that there is a parking lot past Trailblazer 40A. It also indicates that there is a saw somewhere that looks familiar. \n";
                cout << ">";
                cin >> choice;
                if (choice == "east" || choice == "East" || choice == "e" || choice == "E")
                {
                    location = "trail";
                }
                else if (choice == "west" || choice == "West" || choice == "w" || choice == "W")
                {
                    cout << "Now you know where the bears live. \n";
                    health = 0;
                }
            }
            else if (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit")
            {
                cout << "That is irrelevant. \n";
            }
        }
                
                
                
                
        else if (location == "trailblazer41") // if they go east at the start of the trail or west at either 40B or 40A, they will end up here
        {
            cout << "You are at Trailblazer 41. \n";
            cout << ">";
            cin >> choice;
            if (choice == "west" || choice == "West" || choice == "w" || choice == "W")
            {
                location = "trail";
            }
            else if (choice == "east" || choice == "East" || choice == "e" || choice == "E")
            {
                location = "fork";
            }
            else if (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit")
            {
                cout << "That is irrelevant. \n";
            }
        }
         
           
                
                
        else if (location == "fork") // here, they can go left (40B) or right (40A)
        {
            cout << "You have come to a fork in the trail. You may either go left or right. \n";
            cout << ">";
            cin >> choice;
            if (choice == "right" || choice == "Right" || choice == "R" || choice== "r")
            {
                location = "trailblazer40A";
            }
            else if (choice == "left" || choice == "Left" || choice == "l" || choice == "L")
            {
                location = "trailblazer40B";
            }
            else if (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit")
            {
                cout << "That is irrelevant. \n";
            }
        }
        
        
        
        
        else if (location == "field") // If the player went east at trailblazer 40B, they come here to get the gasoline.
        {
            cout << "You encounter a large field. It is on fire but you see a container of gasoline. You may grab it if you would like. \n";
            cout << ">";
            cin >> choice;
            if (choice == "grab" || choice == "Grab" || choice == "g" || choice == "G")
            {
                gas = 1;
                cout << "You grabbed the gasoline. The fire is closing in on you on all sides except for the west. Where would you like to go? \n";
                cout << ">";
                cin >> choice;
                if (choice == "west" || choice == "West" || choice == "w" || choice == "W")
                    {
                        location = "trailblazer40B";
                    }
                else if (choice != "west" || choice != "West" || choice != "w" || choice != "W")
                    {
                        health = 0;
                    }
            }
            else if (choice == "west" || choice == "West" || choice == "w" || choice == "W")
            {
                location = "trailblazer40B";
            }
            else if (choice != "q" || choice != "Q" || choice != "quit" || choice != "Quit")
            {
                cout << "That is irrelevant. \n";
            }
        }
    

        
        else if (location == "car") // *from Olivia - I noticed that there was a small bug here. I think I fixed it.
        {
            cout << "Would you like to try and start the car? \n";
            cout << ">";
            cin >> choice;
            if ((choice == "yes" && gas == 0) || (choice == "Yes" && gas == 0) || (choice == "y" && gas == 0) || (choice == "Y" && gas == 0))
            {
                cout << "Unless you have gas for the car, you cannot start it. Would you like to go west and try to find the gas? \n";
                cin >> choice;
                
                if (choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes") // *from Olivia - I added these lines because there seemed to be an if statment missing.
                {
                    location = "fork";
                }
                else if (choice == "n" || choice == "N" || choice == "no" || choice == "No")
                {
                    cout << "A bear family attacks you. You were killed due to your actions! Better luck next time.\n";
                    return 0;
                }
            }
            else if ((choice == "yes" && gas == 1) || (choice == "Yes" && gas == 1) || (choice == "y" && gas == 1) || (choice == "Y" && gas == 1))
            {
                cout << "\n \n Congratulations! You have started the car and are free to go home. You have made it out of the forest without dying. \n";
                return 0;
            }
        }
        
        
        if (health == 0) // when the player reaches 0 health, they die
        {
            cout << "Be careful. You were killed due to your actions. \n";
            return 0;
        }
        
        
        // *from Olivia - I like your game it's very creative and it wasn't terribly easy to win. Thanks for sharing your code with me!
        
        
        
    }
    return 0;
}

