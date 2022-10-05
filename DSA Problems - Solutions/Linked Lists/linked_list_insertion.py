# Creating a Linked List


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Linkedlist:
    def __init__(self):
        self.head = None

    # fn to print the List
    def print_linked_list(self):
        if self.head == None:
            print("Linked List is empty!")
        else:
            n = self.head
            while n != None:
                print(n.data, "-->", end=" ")
                n = n.next

    # fn to add a node at the beginning of list
    def insert_start(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # fn to add a node at the end of list
    def insert_end(self, data):
        new_node = Node(data)
        if self.head == None:
            self.head = new_node
            return
        else:
            n = self.head
            while n.next != None:
                n = n.next
            n.next = new_node

    # fn to add a node after a given position
    def insert_at(self, data, node):
        temp = self.head
        while temp is not None:
            if temp.data == node:
                break
            temp = temp.next
        if node is None:
            return "Item not found in Llist"
        else:
            new_node = Node(data)
            new_node.next = temp.next
            temp.next = new_node


LL1 = Linkedlist()
LL1.insert_end(5)
LL1.insert_end(10)
LL1.insert_end(20)
print(LL1.print_linked_list())

LL1.insert_at(15, 10)
print(LL1.print_linked_list())
