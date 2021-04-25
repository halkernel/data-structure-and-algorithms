

class Node:
    def __init__(self, state, pos, parent):
        self.state = state
        self.pos = pos
        self.parent = parent

    
    def reveal(self):
        for r in self.state:
            for c in r:
                print(' |' if c == '' else (c + '|'), end="")
            print()
    
    
    def positions(self):
        for r in self.pos:
            for c in r:
                print(str(c) + '|', end="")
            print()


    def __repr__(self):
        return '<Node {}>'.format(self.state)

