

class Node:
    def __init__(self, state, parent):
        self.state = state
        self.parent = parent

    def reveal(self):
        for i in range(3):
            print ("{} {} {}".format(*self.state[3*i:3*i+3]))
        print()

    def z_index(self):
        return self.state.index(0)

    def __repr__(self):
        return '<Node {}>'.format(self.state)

