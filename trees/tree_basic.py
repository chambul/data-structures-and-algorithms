class TreeNode:

    def __init__(self, data):
        self.data = data
        self.parent = None 
        self.children = [] 


    def add_child(self,child):
        self.children.append(child)
        child.parent = self 


    def get_level(self): 
        level =0 
        node = self 
        while node.parent is not None:
            node = node.parent
            level += 1 

        return level 
    
    def print_tree(self): 
        spaces = ' ' * self.get_level() * 3
        prefix = spaces + "|__" if self.parent else ""
        print(prefix + self.data)
        if self.children:
            for child in self.children:
                child.print_tree()

    
def build_tree():
    root = TreeNode('Electronics') 
    laptop = TreeNode('Laptops')
    phone = TreeNode('Cell phones')
    tv = TreeNode('Televisions')

    root.add_child(laptop )
    root.add_child(phone)
    root.add_child(tv)

    laptop.add_child(TreeNode('Mac') )
    laptop.add_child(TreeNode('MS Surface') )
    laptop.add_child(TreeNode('Thinkpad') )

    phone.add_child(TreeNode('iphone') )
    phone.add_child(TreeNode('pixel') )
    phone.add_child(TreeNode('vivo') )


    tv.add_child(TreeNode('Samsung') )
    tv.add_child(TreeNode('LG') )

    root.print_tree()

if __name__ == '__main__':
    build_tree()