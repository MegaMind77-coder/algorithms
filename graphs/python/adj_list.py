
class adj_node: 
    def __init__(self, data):
        self.vertex = data
        self.next = None

class adj_list:
    def __init__(self, num_vertices):
        self.V = num_vertices
        self.list = [None] * self.V
    
    def add_edge(self, src, dest):
        new_node = adj_node(dest)
        new_node.next = self.list[src]
        self.list[src] = new_node

        new_node = adj_node(src)
        new_node.next = self.list[dest]
        self.list[dest] = new_node

    def print_adjlist(self):
        i = 0
        temp = self.list[0]
        while(i<self.V):
            temp = self.list[i]
            if(temp == None):
                break
            print(temp.vertex)
            i+=1

if __name__ == "__main__":
    
    V = 5
    new_graph = adj_list(V)
    new_graph.add_edge(0,1)

    new_graph.print_adjlist()