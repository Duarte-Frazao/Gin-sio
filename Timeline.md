# Basic Mission 8 - Hack this Site

Don't look at this tutorial if you haven't tried to solve it for a long time.

The best strategy to learn is to try untill you get stuck, if you remain that way for around 15/20 min read a tutorial just enough to get a glimpse of what you're supposed to do, close the tutorial and try again, repeat this process untill you get it right, it's the hardest way, but also the best way to learn!

Now let's dive into it!

### First let's take a look at the mission:

> Network Security Sam is going down with the ship - he's determined to keep obscuring the password file, no matter how many times people manage to recover it. This time the file is saved in /var/www/hackthissite.org/html/missions/basic/9/.

> In the last level, however, in my attempt to limit people to using server side includes to display the directory listing to level 8 only, I have mistakenly screwed up somewhere.. there is a way to get the obscured level 9 password. See if you can figure out how...

> This level seems a lot trickier then it actually is, and it helps to have an understanding of how the script validates the user's input. The script finds the first occurance of '<--', and looks to see what follows directly after it. 

We get some information:

* First we get our objective, find the location of the password file and read it, same as last mission
* We get the location of the file, /var/www/hackthissite.org/html/missions/basic/9/, our current directory
* The previous script had some kind of exploit that could help us in this misson

As they say, **This level seems a lot trickier then it actually is** so try untill you get completely stuck before you read the tutorial!

### Understanding the mission

If we read the mission and try to make sense of what they're telling us, we quickly realize level 9 is actually solved in level 8!
We have to use the script from last mission to get to /var/www/hackthissite.org/html/missions/basic/9/ and find the name of the file.

Well this is the hardest part, understand the mission, now you'll most likely have an idea of how to solve it, go for it!


#### [Stuck] trying to modify the ls instruction

Most likely you're trying to modify the last mission command:
 * `<!--#exec cmd="ls .." -->`
 
We want to see the name of a file in the directory missions/basic/9/, and we're executing the commmand from the directory missions/basic/8/tmp/ so let's summarize what we want to do (think of it like a tree):
  1. Move up one directory (from missions/basic/8/tmp/ to missions/basic/8/)
  2. Move up another directory (from missions/basic/8/ to missions/basic)
  3. Move down one directory (from missions/basic/ to missions/basic/9/)
  4. List the files in the current directory 
  
How can we achieve this? Well I encorage you to try untill you get it right, this boils down to you understanding how to navigate directories, remember that we use the slash to the right of the directory (ex basic/)

### Solution

Let's transform the first three points which represent the directory navigation into an instruction:
  1. Up ../
  2. Up ../
  3. Down to the basic mission 9 directory  9/
  
Next we just use the ls with this path, we get:

  * `<!--#exec cmd="ls ../../9/" -->`
  
### Finally

Now we get a list of the files in basic/mission/9/, with a strange looking one, the hidden file!

Hope you enjoyed the tutorial and learned something about directory navigation or an headache for getting stuck!










