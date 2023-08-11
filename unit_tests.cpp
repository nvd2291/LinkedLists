/*
 *  unit_tests.cpp
 *  Naveed Naeem
 *  June 12, 2023
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *  
 *  Purpose: Unit test for each public member function
 */

#include "CharLinkedList.h"
#include <string>
#include <cassert>

using namespace std;
// Lower Case alphabet used for testing purposes
char ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";

// Test the functionality of the default class constructor
void test_CharLinkedList_default_constructor()
{
    CharLinkedList emptyLinkedList;
    assert(emptyLinkedList.isEmpty());
    assert(emptyLinkedList.size() == 0);
}

// Test the functionality of the second constructor
void test_CharLinkedList_second_constructor()
{
    CharLinkedList singletonList('M');
    assert(singletonList.isEmpty() == false);
    assert(singletonList.size() == 1);
    assert(singletonList.first() == 'M');
    assert(singletonList.last() == 'M');

}

// Test the functionality of the second constructor with a numeric input
void test_CharLinkedList_second_constructor_num_input()
{
    // 90 = 'Z'
    CharLinkedList singletonList(90);

    assert(singletonList.isEmpty() == false);
    assert(singletonList.size() == 1);
    assert(singletonList.first() == 'Z');
    assert(singletonList.last() == 'Z');
}

// Test the functionality of the third constructor with an empty array
void test_CharLinkedList_third_constructor_empty()
{
    CharLinkedList emptyLinkedList(nullptr, 0);
    assert(emptyLinkedList.isEmpty());
    assert(emptyLinkedList.size() == 0);
}

// Test the functionality of the second constructor
void test_CharLinkedList_third_constructor()
{
    CharLinkedList alphaList(ALPHABET, 26);
    assert(alphaList.isEmpty() == false);
    assert(alphaList.size() == 26);
    assert(alphaList.first() == 'a');
    assert(alphaList.last() == 'z');
    assert(alphaList.toString() == 
    "[CharLinkedList of size 26 <<abcdefghijklmnopqrstuvwxyz>>]");
}

// Test the copy constructor with and empty list as the input
void test_CharLinkedList_copy_constructor_empty()
{
    CharLinkedList emptyList1;
    CharLinkedList emptyList2(emptyList1);

    assert(emptyList2.isEmpty() == true);
    assert(emptyList2.size() == 0);
}

// Test the copy constructor with a non-empty list
void test_CharLinkedList_copy_constructor()
{
    CharLinkedList alphaList1(ALPHABET, 26);
    CharLinkedList alphaList2(alphaList1);

    assert(alphaList2.isEmpty() == false);
    assert(alphaList2.size() == 26);
    assert(alphaList2.first() == 'a');
    assert(alphaList2.last() == 'z');
    assert(alphaList2.toString() == 
    "[CharLinkedList of size 26 <<abcdefghijklmnopqrstuvwxyz>>]");
}

// Test Operator Overload Copy Constructor with empty list
void test_CharLinkedList_overload_copy_constructor_empty()
{
    CharLinkedList emptyList1;
    CharLinkedList emptyList2 = emptyList1;

    assert(emptyList2.isEmpty() == true);
    assert(emptyList2.size() == 0);
}

// Test Operator Overload Copy Constructor
void test_CharLinkedList_overload_copy_constructor()
{
    CharLinkedList alphaList1(ALPHABET, 26);
    CharLinkedList alphaList2 = alphaList1;
    assert(alphaList2.isEmpty() == false);
    assert(alphaList2.size() == 26);
    assert(alphaList2.first() == 'a');
    assert(alphaList2.last() == 'z');
    assert(alphaList2.toString() == 
    "[CharLinkedList of size 26 <<abcdefghijklmnopqrstuvwxyz>>]");

}

// Test the first() and last() methods with an empty list
void test_CharLinkedList_first_last_empty()
{
    CharLinkedList emptyList;

    assert(emptyList.isEmpty() == true);
    assert(emptyList.size() == 0);

    // String Variable to get the error message thrown
    string error_message = "";
    // Boolean variable to track whether range_error is thrown
    bool range_error_thrown = false;


    // Test first() on the emptyList
    try
    {
        emptyList.first();
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }
    
    assert(range_error_thrown == true);
    assert(error_message == "cannot get first of empty LinkedList");

    // Test last() on the emptyList
    try
    {
        emptyList.last();
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }
    
    assert(range_error_thrown == true);
    assert(error_message == "cannot get last of empty LinkedList");
}

// Test the first() and last() methods on a single element list
void test_CharLinkedList_first_last_single()
{
    CharLinkedList singletonList('J');
    assert(singletonList.isEmpty() == false);
    assert(singletonList.size() == 1);
    assert(singletonList.first() == 'J');
    assert(singletonList.last() == 'J');

}

// Test the first() and last() methods on a multi-element list
void test_CharLinkedList_first_last_multi()
{
    CharLinkedList alphabetList(ALPHABET,26);

    assert(alphabetList.size() == 26);
    assert(alphabetList.first() == 'a');
    assert(alphabetList.last() == 'z');
}

// Test size() on an empty list
void test_CharLinkedList_size_empty()
{
    CharLinkedList emptyList;

    assert(emptyList.isEmpty());
    assert(emptyList.size() == 0);
}

// Test size() on a single character list
void test_CharLinkedList_size_singleton()
{
    CharLinkedList singletonList('a');

    assert(singletonList.isEmpty() == false);
    assert(singletonList.size() == 1);
}

// Test size() on a short list of chars
void test_CharLinkedList_size_short()
{
    char shortArr[] = "ABCDE";
    CharLinkedList shortList(shortArr, 5);

    assert(shortList.isEmpty() == false);
    assert(shortList.size() == 5);
}

// Test size() on a list of chars containing the alphabet
void test_CharLinkedList_size_alphabet()
{
    CharLinkedList alphabetList(ALPHABET, 26);

    assert(alphabetList.isEmpty() == false);
    assert(alphabetList.size() == 26);
}

// Test elementAt() method on an empty list
void test_CharLinkedList_elementAt_empty()
{
    CharLinkedList emptyList;

    // String Variable to get the error message thrown
    string error_message = "";
    // Boolean variable to track whether range_error is thrown
    bool range_error_thrown = false;

    try
    {
       emptyList.elementAt(0);
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message ==
    "index (0) not in range [0..0)");
    
    try
    {
        emptyList.elementAt(-1);
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message ==
    "index (-1) not in range [0..0)");

}

// Test elementAt() method on a single char list
void test_CharLinkedList_elementAt_single()
{
    CharLinkedList singleList('m');

    assert(singleList.elementAt(0) == 'm');
    assert(singleList.size() == 1);
    assert(singleList.isEmpty() == false);

}

// Test elementAt() method on the alphabet characters
void test_CharLinkedList_elementAt_alphabet()
{
    CharLinkedList alphabetList(ALPHABET, 26);
    assert(alphabetList.size() == 26);
    assert(alphabetList.first() == 'a');
    assert(alphabetList.last() == 'z');

    for (int i = 0; i < alphabetList.size(); i++)
    {
        assert(alphabetList.elementAt(i) == ALPHABET[i]);
    }    
}

// Test elementAt() method on a sentence
void test_CharLinkedList_elementAt_sentence()
{
    char sentenceArray[] = "The quick brown fox jumps over the lazy dog.";
    CharLinkedList sentenceList(sentenceArray, 44);

    assert(sentenceList.size() == 44);
    assert(sentenceList.first() == 'T');
    assert(sentenceList.last() == '.');

    for (int i = 0; i < sentenceList.size(); i++)
    {
        assert(sentenceList.elementAt(i) == sentenceArray[i]);
    }    
}

// Test elementAt() method on invalid indices
void test_CharLinkedList_elementAt_invalid_indices()
{
    CharLinkedList alphabetList(ALPHABET, 26);

    // String Variable to get the error message thrown
    string error_message = "";
    // Boolean variable to track whether range_error is thrown
    bool range_error_thrown = false;

    try
    {
       alphabetList.elementAt(27);
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message ==
    "index (27) not in range [0..26)");
    
    try
    {
        alphabetList.elementAt(-1);
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message ==
    "index (-1) not in range [0..26)");
}

// Test the toString() and toReverseString() methods on an empty list
void test_CharLinkedList_strings_empty()
{
    CharLinkedList emptyList;
    assert(emptyList.isEmpty());
    assert(emptyList.size() == 0);

    assert(emptyList.toString() == 
    "[CharLinkedList of size 0 <<>>]");
    assert(emptyList.toReverseString() == 
    "[CharLinkedList of size 0 <<>>]");

}

// Test the toString() and toReverseString() methods a single char list
void test_CharLinkedList_strings_singleton()
{
    CharLinkedList singleCharList('Z');

    assert(singleCharList.isEmpty() == false);
    assert(singleCharList.size() == 1);

    assert(singleCharList.toString() == 
    "[CharLinkedList of size 1 <<Z>>]");
    assert(singleCharList.toReverseString() == 
    "[CharLinkedList of size 1 <<Z>>]");
}

// Test the toString() and toReverseString() methods a short list
void test_CharLinkedList_strings_short()
{
    char shortArr[] = "AbcdE";
    CharLinkedList shortCharList(shortArr, 5);

    assert(shortCharList.isEmpty() == false);
    assert(shortCharList.size() == 5);

    assert(shortCharList.toString() == 
    "[CharLinkedList of size 5 <<AbcdE>>]");
    assert(shortCharList.toReverseString() == 
    "[CharLinkedList of size 5 <<EdcbA>>]");
}

// Test the toString() and toReverseString() methods on an alphabet list
void test_CharLinkedList_strings_alphabet()
{
    CharLinkedList alphabetList(ALPHABET, 26);

    assert(alphabetList.size() == 26);
    
    assert(alphabetList.toString() == 
    "[CharLinkedList of size 26 <<abcdefghijklmnopqrstuvwxyz>>]");

    assert(alphabetList.toReverseString() == 
    "[CharLinkedList of size 26 <<zyxwvutsrqponmlkjihgfedcba>>]");
    
}

// Test the toString() and toReverseString() methods on a sentence
void test_CharLinkedList_strings_sentence()
{
    char sentenceArray[] = "The quick brown fox jumps over the lazy dog.";
    CharLinkedList sentenceList(sentenceArray, 44);
    
    string outputStr = "[CharLinkedList of size 44 ";
    outputStr.append("<<The quick brown fox jumps over the lazy dog.>>]");
    assert(sentenceList.toString() == outputStr);

    string outputStrRev = "[CharLinkedList of size 44 ";
    outputStrRev.append("<<.god yzal eht revo spmuj xof nworb kciuq ehT>>]");
    assert(sentenceList.toReverseString() == outputStrRev);
}

// Test the toString() and toReverseString() methods list of special characters
void test_CharLinkedList_strings_special()
{
    char specialsArray[] = "!@#$%^&*()_+{}[]:;";
    CharLinkedList specialsList(specialsArray, 18);

    assert(specialsList.size() == 18);
    assert(specialsList.toString() == 
    "[CharLinkedList of size 18 <<!@#$%^&*()_+{}[]:;>>]");
    assert(specialsList.toReverseString() == 
    "[CharLinkedList of size 18 <<;:][}{+_)(*&^%$#@!>>]");
}

// Test pushAtBack() and pushAtFront() methods on an empty list
void test_CharLinkedList_pushAt_empty_list()
{
    CharLinkedList pushAtTestList;

    pushAtTestList.pushAtBack('X');
    pushAtTestList.pushAtBack('Y');
    pushAtTestList.pushAtBack('Z');

    assert(pushAtTestList.size() == 3);
    assert(pushAtTestList.first() == 'X');
    assert(pushAtTestList.last() == 'Z');

    pushAtTestList.pushAtFront('C');
    pushAtTestList.pushAtFront('B');
    pushAtTestList.pushAtFront('A');

    assert(pushAtTestList.size() == 6);
    assert(pushAtTestList.first() == 'A');
    assert(pushAtTestList.last() == 'Z');

    assert(pushAtTestList.toString() ==
    "[CharLinkedList of size 6 <<ABCXYZ>>]");
}

// Test pushAtBack() and pushAtFront() methods on an empty list with
// ASCII Number values
void test_CharLinkedList_pushAt_empty_list_numeric()
{
    CharLinkedList pushAtTestList;

    pushAtTestList.pushAtBack(55);
    pushAtTestList.pushAtBack(56);
    pushAtTestList.pushAtBack(57);

    assert(pushAtTestList.size() == 3);
    assert(pushAtTestList.first() == '7');
    assert(pushAtTestList.last() == '9');

    pushAtTestList.pushAtFront(50);
    pushAtTestList.pushAtFront(49);
    pushAtTestList.pushAtFront(48);

    assert(pushAtTestList.size() == 6);
    assert(pushAtTestList.first() == '0');
    assert(pushAtTestList.last() == '9');

    assert(pushAtTestList.toString() ==
    "[CharLinkedList of size 6 <<012789>>]");

}

// Test pushAtBack() and pushAtFront() methods on a single char list
void test_CharLinkedList_pushAt_single_list()
{
    CharLinkedList singleCharList('a');

    for (int i = 1; i < 26; i++)
    {
        singleCharList.pushAtBack(ALPHABET[i]);
    }

    assert(singleCharList.toString() ==
    "[CharLinkedList of size 26 <<abcdefghijklmnopqrstuvwxyz>>]");

    char caps[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = (25); i >= 0; i--)
    {
        singleCharList.pushAtFront(caps[i]);
    }

    string outputStr = "[CharLinkedList of size 52 ";
    outputStr.append("<<ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz>>]");
    assert(singleCharList.toString() == outputStr);
}

// Test pushAtBack() and pushAtFront() methods on a short list
void test_CharLinkedList_pushAt_short_list()
{
    char shortArr[] = "ace";
    CharLinkedList shortList(shortArr,3);

    shortList.pushAtBack('J');
    shortList.pushAtBack('a');
    shortList.pushAtBack('m');
    shortList.pushAtBack('!'); 

    shortList.pushAtFront('p');
    shortList.pushAtFront('S');

    assert(shortList.size() == 9);
    assert(shortList.first() == 'S');
    assert(shortList.last() == '!');
}

// Test pushAtBack() and pushAtFront() methods on a long list
void test_CharLinkedList_pushAt_long_list()
{
    CharLinkedList longList(ALPHABET,26);
    char caps[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = (12); i >= 0; i--)
    {
        longList.pushAtFront(caps[i]);
    }

    for (int i = (13); i < 26; i++)
    {
        longList.pushAtBack(caps[i]);
    }

    string outputStr =  "[CharLinkedList of size 52 <<ABCDEFGHIJKLM";
    outputStr.append("abcdefghijklmnopqrstuvwxyzNOPQRSTUVWXYZ>>]");
    assert(longList.toString() == outputStr);

}

// Test insertAt() method with invalid indices on an empty list
void test_CharLinkedList_insertAt_invalid_indices_empty()
{
    CharLinkedList emptyList;
    // String Variable to get the error message thrown
    string error_message = "";
    // Boolean variable to track whether range_error is thrown
    bool range_error_thrown = false;

    try
    {
        emptyList.insertAt('Z', 1);
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }
    
    assert(range_error_thrown);
    assert(error_message == "index (1) not in range [0..0]");
}

// Test insertAt() method with invalid indices on a non-empty list
void test_CharLinkedList_insertAt_invalid_indices_not_empty()
{
    CharLinkedList alphabetList(ALPHABET, 26);

    assert(alphabetList.size() == 26);

    // String Variable to get the error message thrown
    string error_message = "";
    // Boolean variable to track whether range_error is thrown
    bool range_error_thrown = false;

    try
    {
        alphabetList.insertAt('!', 27);
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (27) not in range [0..26]");

    try
    {
        alphabetList.insertAt('!', -1);
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (-1) not in range [0..26]");
    
}

// Test insertAt into an empty list
void test_CharLinkedList_insertAt_empty_list()
{
    CharLinkedList emptyList;

    emptyList.insertAt('M', 0);
    emptyList.insertAt('A', 0);
    emptyList.insertAt('Z', 2);

    assert(emptyList.first() == 'A');
    assert(emptyList.last() == 'Z');
    assert(emptyList.size() == 3);
}

// Test insertAt by inserting characters into the middle of the alphabet
void test_CharLinkedList_insertAt_alphabet_list()
{
    CharLinkedList alphabetList(ALPHABET, 26);

    alphabetList.insertAt('!', 26);
    assert(alphabetList.size() == 27);
    assert(alphabetList.toString() == 
    "[CharLinkedList of size 27 <<abcdefghijklmnopqrstuvwxyz!>>]");
    
    alphabetList.insertAt('$', 13);
    alphabetList.insertAt('%', 13);
    alphabetList.insertAt('^', 13);
    alphabetList.insertAt('&', 13);
    alphabetList.insertAt('*', 13);

    assert(alphabetList.toString() == 
        "[CharLinkedList of size 32 <<abcdefghijklm*&^%$nopqrstuvwxyz!>>]");
}

// Test insertInOrder with an empty list
void test_CharLinkedList_insertInOrder_empty()
{
    CharLinkedList emptyList;

    emptyList.insertInOrder('A');
    assert(emptyList.first() == emptyList.last());
    assert(emptyList.size() == 1);
    assert(emptyList.toString() == "[CharLinkedList of size 1 <<A>>]");
}

// Test insertInOrder with a single character list
void test_CharLinkedList_insertInOrder_single()
{
    CharLinkedList singleCharList = 'L';

    singleCharList.insertInOrder('C');

    assert(singleCharList.size() == 2);
    assert(singleCharList.first() == 'C');
    assert(singleCharList.last() == 'L');

    singleCharList.insertInOrder('S');
    singleCharList.insertInOrder('Z');
    singleCharList.insertInOrder('A');

    assert(singleCharList.size() == 5);
    assert(singleCharList.first() == 'A');
    assert(singleCharList.last() == 'Z');

    assert(singleCharList.toString() == 
    "[CharLinkedList of size 5 <<ACLSZ>>]");
}

// Test insertInOrder by inserting the special characters between 'Z' and 'a'
void test_CharLinkedList_insertInOrder_special()
{
    char specialChars[] = "[\\]^_`";
    CharLinkedList specialList;
    specialList.pushAtFront('Z');
    specialList.pushAtBack('a');

    assert(specialList.size() == 2);
    assert(specialList.first() == 'Z');
    assert(specialList.last() == 'a');

    for (int i = 0; i < 6; i++)
    {
        specialList.insertInOrder(specialChars[i]);
    }

    assert(specialList.size() == 8);
    assert(specialList.toString() == 
    "[CharLinkedList of size 8 <<Z[\\]^_`a>>]");
}

// Test popFromFront() and popFromBack() on an empty list
void test_CharLinkedList_popFrom_empty_list()
{
    CharLinkedList emptyList;
    // String Variable to get the error message thrown
    string error_message = "";
    // Boolean variable to track whether runtime_error is thrown
    bool runtime_error_thrown = false;

    try
    {
        emptyList.popFromBack();
    }
    catch(const std::exception& e)
    {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    
    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty LinkedList");
    
    try
    {
        emptyList.popFromFront();
    }
    catch(const std::exception& e)
    {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    
    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty LinkedList");

}

// Test popFromFront() and popFromBack() on a single char list
void test_CharLinkedList_popFrom_single()
{
    CharLinkedList singleList1('A');
    CharLinkedList singleList2('Z');

    assert(singleList1.size() == 1);
    assert(singleList2.size() == 1);

    singleList1.popFromBack();
    singleList2.popFromFront();

    assert(singleList1.isEmpty());
    assert(singleList2.isEmpty());    

    assert(singleList1.size() == 0);
    assert(singleList2.size() == 0);

}

// Test popFromFront() and popFromBack() on a palindrome
void test_CharLinkedList_popFrom_palindrome()
{
    char palindrome[] = "0123456789876543210";
    CharLinkedList palindromeList(palindrome, 19);

    for (int i = 0; i < 9; i++)
    {
        assert(palindromeList.first() == palindromeList.last());
        palindromeList.popFromBack();
        palindromeList.popFromFront();
    }

    assert(palindromeList.size() == 1);
    assert(palindromeList.first() == palindromeList.last());
    assert(palindromeList.elementAt(0) == '9');
}

// Test removeAt() method with an empty list
void test_CharLinkedList_removeAt_empty()
{
    CharLinkedList emptyList;
    
    assert(emptyList.isEmpty());
    assert(emptyList.size() == 0);
    // String Variable to get the error message thrown
    string error_message = "";
    // Boolean variable to track whether range_error is thrown
    bool range_error_thrown = false;

    try
    {
        emptyList.removeAt(0);
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }
    
    assert(range_error_thrown);
    assert(error_message == "index (0) not in range [0..0)");
    
}

// Test removeAt() method with an single-element list and invalid indices
void test_CharLinkedList_removeAt_single_invalid()
{
    CharLinkedList singleList('A');

    // String Variable to get the error message thrown
    string error_message = "";
    // Boolean variable to track whether range_error is thrown
    bool range_error_thrown = false;

    try
    {
        singleList.removeAt(1);
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }
    
    assert(range_error_thrown);
    assert(error_message == "index (1) not in range [0..1)");

    range_error_thrown = false;

    try
    {
        singleList.removeAt(-1);
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }
    
    assert(range_error_thrown);
    assert(error_message == "index (-1) not in range [0..1)");

}

// Test removeAt() method with a single-element list
void test_CharLinkedList_removeAt_single()
{
    CharLinkedList singletonList('M');

    singletonList.removeAt(0);

    assert(singletonList.isEmpty());
    assert(singletonList.size() == 0);
}

// Test removeAt method for a list
void test_CharLinkedList_removeAt_list()
{
    char charArr[] = "ABCDEFGHI";
    CharLinkedList shortList(charArr, 9);

    shortList.removeAt(1);
    assert(shortList.size() == 8);
    assert(shortList.toString() == 
    "[CharLinkedList of size 8 <<ACDEFGHI>>]");

    shortList.removeAt(3);
    assert(shortList.toString() == 
    "[CharLinkedList of size 7 <<ACDFGHI>>]");

    shortList.removeAt(6);
    assert(shortList.toString() == 
    "[CharLinkedList of size 6 <<ACDFGH>>]");

}

// Test replaceAt method with invalid indices
void test_CharLinkedList_replaceAt_invalid()
{
    CharLinkedList emptyList;

    // String Variable to get the error message thrown
    string error_message = "";
    // Boolean variable to track whether range_error is thrown
    bool range_error_thrown = false;

    try
    {
        emptyList.replaceAt('L',0);
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (0) not in range [0..0)");

    try
    {
        emptyList.replaceAt('L',1);
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (1) not in range [0..0)");

    try
    {
        emptyList.replaceAt('L',-1);
    }
    catch(const std::exception& e)
    {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (-1) not in range [0..0)");
    
}

// Test replaceAt() by replacing the character at each index multiple times
void test_CharLinkedList_replaceAt_all()
{
    char arr[] = "12345";
    CharLinkedList numList(arr, 5);

    int alphabetSize = 26;

    for (int idx = 0; idx < numList.size(); idx++)
    {
        for (int a = 0; a < alphabetSize; a++)
        {
            numList.replaceAt(ALPHABET[a], idx);
            assert(numList.elementAt(idx) == ALPHABET[a]);
        }
    }
}

// Test concatenate() method where the input list is empty
void test_CharLinkedList_concatenate_empty_list()
{
    CharLinkedList firstList(ALPHABET,26);
    CharLinkedList secondList;

    firstList.concatenate(&secondList);

    assert(firstList.size() == 26);
    assert(firstList.first() == 'a');
    assert(firstList.last() == 'z');
    assert(firstList.toString() == 
    "[CharLinkedList of size 26 <<abcdefghijklmnopqrstuvwxyz>>]");

}

// Test concatenate() method where this list is empty
void test_CharLinkedList_concatenate_empty_list_this()
{
    CharLinkedList firstList;
    CharLinkedList secondList(ALPHABET,26);

    firstList.concatenate(&secondList);

    assert(firstList.size() == 26);
    assert(firstList.first() == 'a');
    assert(firstList.last() == 'z');
    assert(firstList.toString() == 
    "[CharLinkedList of size 26 <<abcdefghijklmnopqrstuvwxyz>>]");
}

// Test concatenate() method on two short lists
void test_CharLinkedList_concatenate()
{
    char arr1[] = "Space";
    char arr2[] = "Jam";

    CharLinkedList firstList(arr1, 5);
    CharLinkedList secondList(arr2, 3);

    firstList.concatenate(&secondList);

    assert(firstList.size() == 8);
    assert(firstList.first() == 'S');
    assert(firstList.last() == 'm');
    assert(firstList.toString() == 
    "[CharLinkedList of size 8 <<SpaceJam>>]");
}

// Test concatenate() method when the list passed is itself
void test_CharLinkedList_self_concatenation()
{
    char arr[] = "CHESHIRE";
    CharLinkedList cheshireList(arr, 8);

    assert(cheshireList.size() == 8);
    assert(cheshireList.toString() == 
    "[CharLinkedList of size 8 <<CHESHIRE>>]");

    cheshireList.concatenate(&cheshireList);

    assert(cheshireList.size() == 16);
    assert(cheshireList.toString() == 
    "[CharLinkedList of size 16 <<CHESHIRECHESHIRE>>]");

}

// Test if clear() method is working as expected
void test_CharLinkedList_clear()
{
    char arr[] = "CHESHIRE";
    CharLinkedList cheshireList(arr, 8);

    assert(cheshireList.size() == 8);
    assert(cheshireList.toString() == 
    "[CharLinkedList of size 8 <<CHESHIRE>>]");

    cheshireList.concatenate(&cheshireList);

    assert(cheshireList.size() == 16);
    assert(cheshireList.toString() == 
    "[CharLinkedList of size 16 <<CHESHIRECHESHIRE>>]");

    cheshireList.clear();
    assert(cheshireList.isEmpty() == true);
    assert(cheshireList.size() == 0);
    assert(cheshireList.toString() == 
    "[CharLinkedList of size 0 <<>>]");
}

int main()
{
    // Constructor Tests
    test_CharLinkedList_default_constructor();
    test_CharLinkedList_second_constructor();
    test_CharLinkedList_second_constructor_num_input();
    test_CharLinkedList_third_constructor_empty();
    test_CharLinkedList_third_constructor();
    test_CharLinkedList_copy_constructor_empty();
    test_CharLinkedList_copy_constructor();
    test_CharLinkedList_overload_copy_constructor_empty();
    test_CharLinkedList_overload_copy_constructor();

    // Public Method Tests

    // Test clear() method
    test_CharLinkedList_clear();

    // Test size() method with different list sizes
    test_CharLinkedList_size_empty();
    test_CharLinkedList_size_singleton();
    test_CharLinkedList_size_short();
    test_CharLinkedList_size_alphabet();

    // Test first() and last() methods
    test_CharLinkedList_first_last_empty();
    test_CharLinkedList_first_last_single();
    test_CharLinkedList_first_last_multi();

    // Test elementAt() methods
    test_CharLinkedList_elementAt_empty();
    test_CharLinkedList_elementAt_single();
    test_CharLinkedList_elementAt_alphabet();
    test_CharLinkedList_elementAt_sentence();
    test_CharLinkedList_elementAt_invalid_indices();

    // Test toString() and toReverseString() methods
    test_CharLinkedList_strings_empty();
    test_CharLinkedList_strings_singleton();
    test_CharLinkedList_strings_short();
    test_CharLinkedList_strings_alphabet();
    test_CharLinkedList_strings_sentence();
    test_CharLinkedList_strings_special();

    // Test pushAtBack() and pushAtFront() methods
    test_CharLinkedList_pushAt_empty_list();
    test_CharLinkedList_pushAt_empty_list_numeric();
    test_CharLinkedList_pushAt_single_list();
    test_CharLinkedList_pushAt_short_list();
    test_CharLinkedList_pushAt_long_list();

    // Test insertAt() method
    test_CharLinkedList_insertAt_invalid_indices_empty();
    test_CharLinkedList_insertAt_invalid_indices_not_empty();
    test_CharLinkedList_insertAt_empty_list();
    test_CharLinkedList_insertAt_alphabet_list();

    // Test insertInOrder() method
    test_CharLinkedList_insertInOrder_empty();
    test_CharLinkedList_insertInOrder_single();
    test_CharLinkedList_insertInOrder_special();

    // Test popFromBack() and popFromFront() methods
    test_CharLinkedList_popFrom_empty_list();
    test_CharLinkedList_popFrom_single();
    test_CharLinkedList_popFrom_palindrome();

    // Test removeAt() method
    test_CharLinkedList_removeAt_empty();
    test_CharLinkedList_removeAt_single_invalid();
    test_CharLinkedList_removeAt_single();
    test_CharLinkedList_removeAt_list();

    // Test replaceAt() method
    test_CharLinkedList_replaceAt_invalid();
    test_CharLinkedList_replaceAt_all();

    // Test concatenate() method
    test_CharLinkedList_concatenate_empty_list();
    test_CharLinkedList_concatenate_empty_list_this();
    test_CharLinkedList_concatenate();
    test_CharLinkedList_self_concatenation();

    return 0;
}
