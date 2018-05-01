# Documentation

- OVERALL COMMENTS

My intial proposal for this project was to create a 2D game with GoDot Engine. However, a week went by and I realised that changing the the Engine itself was going to be incredibly difficult so I had to change my proposal to work with UnReal Engine. Honestly, it was very difficult in getting to learn and know the engine. On top of that, most online resources only explain through Visual Scripting (Blueprints) not C++ code, so I did not have many resouces to work with and just the documentation. After working with UnReal, I thought that making a 2D game would look too simple and opted to make a 3D game. I decided to make a first person shooter and a training range.

If I were to have more time, one of the key features I would have added was shot accuracy which would say what percent of my shot hit something.

- TIMELINE


April 20th 

Changed Proposal from GoDot engine to UnReal and started working on UnReal Engine.

April 21st - 24th  

Read and watched tutorials and made a plan on how I should approach making a shooting range. A lot ofmy time was spent designing and comming up with the perfect sketch.

April 25 - 1st

- Made the game. I first started off with building the design and the shape of the shooting range.

- One of the main problems I had was to figure out how to make the object turn around and go back and forth. I figured it out with a lot of experimenting and looking at other Unreal Engine Projects

- Another problem I faced while making the game was to find an alternative to making different objects with different directions. As the direction was the only thing that was different, I wanted a way to keep the same object and just change direction. So I learnt a neat trick that that would set a property in C++ code editable in the UnReal Engine. So I could have the same cube object and make it travel in X,Y,X directions

- I also added code to choose a random direction each frame, but that did not make the shooting range look neat and gave me a headache so I cancelled that plan. So while implementing the design I changed the object properties to immovable (of the spheres at the front).

- I quite easily made the sphere travel faster over time, but after a while it got quite impossible to hit anything at all. So I set a cap to the max speed to a thousand. Currently, the gamewill reach max time after a 100 seconds of play. 

- Finding the correct settings for the camera and ligting and also player movement was not hard BUT very time consuming. I had to read a ton of example projects and look at other projects to realise the tiny settings I had to change to make it perfect. Pretty much a lot of documenation time. This probably took over 35 hours of time to figure out....

Finished at 1st May

