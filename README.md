# Dictionary
Dictionary based on chained hash table.  
### How to use
```
table->insert("key", "value");
table->insert_unique("key", "value");
table->find("key", results);
table->remove("key");
```  
For more details see chained_hash_table.cpp
### To compile examples
sh make.sh