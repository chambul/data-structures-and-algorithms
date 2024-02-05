from hash_table import HashTable 

ht = HashTable()
ht.insert("Hello1",3000)
ht.insert("Hello2",4000)
ht.insert("Hello3",5000)

ht.print()

key = "Hello1"
val = ht.find(key)
print(f" value of the key {key} is {val}" ) 


ht.remove("Hello1")
ht.print()