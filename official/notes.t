Hokay so, what we are going to be doing is gradually adding the 'levels' to the definition of a State. State is an actual class, levels are simply a way to conceptualize the different stages of comprehension the compiler does.

The first level, which is all we have been focusing on, is simply breaking the code into words and the special characters that seperate them. After this level the compiler should have a list of state changes and words, which at a later level will be fed to the appropriate State.

The compiler should probably have all the information within itself, and States simply utilize compiler functions and manipulate compiler data. In a way, a State can only recieve a single word before a State change, but Im thinking there will be many cases where a space between words doesnt actually change the State. (definately not always tho)

Im going to want to be able to reuse routines for different characters and different States. Should keep that in mind..

Sooooo -- for now don't worry about any other levels of the States, simply get this first one done and tested before even worrying about how to implement the rest.