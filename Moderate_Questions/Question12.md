# Question 12
## XML Encoding 
Since XML is very verbose, you are given a way of encoding it where each tag gets mapped to a pre-defined integer value. The language/grammar is as follows:
Element --> Tag Attributes END Children END
Attribute --> Tag Value
END --> 0
Tag --> some predefined mapping to int
Value --> string value
