<h4>Longest Compound word</h4>
How to run on your machine 
-Download/Clone the repository on your device
-Open Impledge.cpp and then open terminal </br>
-type g++ Impledge.cpp -o main </br>
-type main Input_01.txt </br>
-Solution file will be created with the respective output </br>

<h4>Apprach and Algorithm </h4>
For the given problem we need to find the words which are formed by the combination of the smaller words , and from this we need to find the first largest and the second largest word in length. </br>
Here we will use Trie Data structure to implement the following .</br>
-First we will sort the array in increasing order of length of the words so that while iteration bigger may be found by combination of the smaller word which may be already in Trie. </br>
-Then we will iterate the array and check if the word can be formed by the combination of the smaller of words if not then we will add that word in the Trie .</br>
-While checking if we can form the larger word from the smaller word we will iterate from 0 to length of given word and search for the substring which can formed from smaller words which are already present in the Trie. </br>
-If the word is formed by the combination of the smaller word then it will return true else false .</br>

<h4>Example</h4>
words= [cat , cats , catscats , catxdogcatsrat]</br>
so if we come on first word ```cat``` we iterate over each character of it and see if string from here exists on trie or not </br>
    from index 0 : c (dont exist on trie)</br>
    from index 1 : ca (dont exist on trie)</br>
    from index 2 : cat (dont exist on trie)</br>

    insert this string in trie 
    trie = cat
    
Now we come on second word ```cats``` similarly for this </br>
    from index 0 : c (exist on trie) </br>
    from index 1 : ca (exist on trie) </br>
    from index 2 : cat ( exist on trie) </br>
    from index 3 : cats (dont exist on trie) </br>

    insert this string in trie
    trie = cats
    

Now we come on last word ```catscats``` similarly for this </br>
  from index 0 : c (exist on trie but don't end ) </br>
    from index 1 : ca (exist on trie but don't end) </br>
    from index 2 : cat ( exist on trie but don't end) </br>
    from index 3 : cats (exist on trie and also end) from were we get this substring is present before  
    so from next index we will again start and find the if substring already exist in the tries .
