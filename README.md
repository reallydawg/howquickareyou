# howquickareyou
This Repo is made for my ENGR103 Project. It is a game where you test your reaction time speed through 5 varying levels. The first level is easy and gets progressively harder as you go on until level 5 where its the most difficult to time. 
Reaction Time Game Details

User Input Controls

	•	Left Button (Button A):
	•	Function: Starts the game
	•	Assignment: Game initiation
	•	Threshold/Map Function: Not applicable
 
	•	Right Button (Button B):
	•	Function: Registers the player’s reaction
	•	Assignment: Reaction time measurement
	•	Threshold/Map Function: Not applicable

Game Rules

	1.	Starting the Game:
	•	The player presses the left button (Button A) to start the game.
 
	2.	Game Levels:
	•	The game consists of 5 levels.
	•	Each level progressively reduces the maximum delay before the LED lights up, making it harder.
 
	3.	Reaction Time Measurement:
	•	After a random delay, an LED lights up.
	•	The player must press the right button (Button B) as quickly as possible after the LED lights up.
	•	The reaction time is measured in milliseconds.
 
	4.	Scoring System:
	•	If the reaction time is less than 500 milliseconds, the player scores 10 points.
	•	If the reaction time is 500 milliseconds or more, the player scores 5 points.
	•	The score accumulates over the levels.
 
	5.	Game End:
	•	The game ends after completing 5 levels.
	•	The final score is displayed in the serial monitor.

Sensors Used

	1.	Buttons (Input Sensors):
	•	Sensor: Built-in buttons on Adafruit Circuit Playground Express
	•	Function: Detect user input for starting the game and reacting to the LED.
	•	Raw Range: 0 (not pressed) to 1 (pressed)
	•	Assignment: Left Button for starting the game, Right Button for measuring reaction time
	•	Threshold/Map Function: Direct digital read, no threshold or map function needed.
 
	2.	LEDs (Output Sensors):
	•	Sensor: Built-in LEDs on Adafruit Circuit Playground Express
	•	Function: Provide visual feedback to the player indicating when to react.
	•	Raw Range: Each LED has RGB values from 0 to 255
	•	Assignment: Randomly light up one of the LEDs to signal the player to press the right button
	•	Threshold/Map Function: Not applicable
 
	3.	Speaker (Output Sensor):
	•	Sensor: Built-in speaker on Adafruit Circuit Playground Express
	•	Function: Provide auditory feedback (tones) to indicate game events.
	•	Raw Range: Frequency (Hz) and duration (milliseconds)
	•	Assignment: Play tones to signal game start, level start, and correct reaction.
	•	Threshold/Map Function: Not applicable

Threshold and Map Functions

	•	Buttons:
	•	No threshold or mapping functions are applied since the buttons are digital inputs with states 0 or 1.
	•	LEDs:
	•	No threshold or mapping functions are applied. LEDs are controlled directly using RGB values.
	•	Speaker:
	•	No threshold or mapping functions are applied. Tones are played with specified frequencies and durations.

Summary

This sheet outlines the user input controls, game rules, sensors used, their functions, raw ranges, assignments, and any threshold or map functions applied in the reaction time game. The game utilizes the built-in buttons, LEDs, and speaker of the Adafruit Circuit Playground Express to provide an interactive and progressively challenging experience for the player.
