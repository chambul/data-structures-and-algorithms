class Graph:

    def __init__(self,edges):
        self.edges = edges 
        self.graph_dict = {} # initialise graph dictionary
        for start, end in edges:
            if start in self.graph_dict:
                self.graph_dict[start].append(end) 
            else: 
                self.graph_dict[start] = [end]
        print("Graph dictionary: ", self.graph_dict)

    # returns a list of lists, each containing a path
    def get_paths(self,start,end, path=[]):    

        if start not in self.graph_dict: 
            return [] 
      
        path = path + [start]
        if start == end: 
            return [path]

        new_paths = []
        for node in self.graph_dict[start]:
            if node not in path:
                paths = self.get_paths(node,end,path)
                for p in paths:
                    new_paths.append(p)
        return new_paths 
    

    def get_shortest_path(self, start, end):
        paths = self.get_paths(start, end)
        if len(paths) == 0:
            return None 
        elif len(paths) ==1:
            return paths
        else: 
            return min(paths)

if __name__ == '__main__':

    routes = [
        ("Mumbai", "Paris"),
        ("Mumbai", "Dubai"),
        ("Paris", "Dubai"),
        ("Paris", "New York"),
        ("Dubai", "New York"),
        ("New York", "Toronto"),
    ]

    route_graph = Graph(routes)
    
    start = "Mumbai"
    end = "New York"

    print(f"All paths between: {start} and {end}: ",route_graph.get_paths(start,end))
    print(f"Shortest path between {start} and {end}: ", route_graph.get_shortest_path(start,end))

    start = "Dubai"
    end = "New York"

    print(f"All paths between: {start} and {end}: ",route_graph.get_paths(start,end))
    print(f"Shortest path between {start} and {end}: ", route_graph.get_shortest_path(start,end))