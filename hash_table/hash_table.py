CAPACITY = 50 


class Node:
    def __init__(self,key,value):
        self.key = key
        self.value = value
        self.next = None 

    
class HashTable:
    def __init__(self) :
        self.capacity = CAPACITY
        self.size = 0 
        self.buckets = [None for i in range(self.capacity)] 


        # hash function
    def hash(self, key):
        hashsum = 0
        for ch in key:
        #ord - unicode code of a specified character
            hashsum += ord(ch)
        return hashsum % self.capacity  
        
    def insert(self,key,value):
        self.size += 1
        index = self.hash(key)
        node = self.buckets[index]
        if node is None:
           # node = Node(key, value)
            self.buckets[index] = Node(key, value)
            return
        #else
        prev = node
        while node is not None:
            prev = node
            node = node.next

        prev.next = Node(key, value)

    def find(self, key):
        index = self.hash(key)
        node = self.buckets[index]
        value = None
        while node is not None:
            if node.key == key:
                value = node.value
                break 
            node = node.next

        return value
        

    def remove(self,key):
        index = self.hash(key)
        node = self.buckets[index]
        
        if node.next is None:
            self.buckets[index] = None 
            self.size -= 1 
            return True 
        else:

            prev = node
            while node.next is not None: 
                if node.key == key:
                    prev.next = node.next 
                    self.buckets[index] = None 
                else :
                    node = node.next

    
    def print(self):
        for i in range(self.capacity):
            node = self.buckets[i]
            if node is None:
                continue

            while node is not None:
                print(f" key {node.key} , value: {node.value}")
                node = node.next