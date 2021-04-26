

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
            
    def mark(self, pair, piece):
        if(self.state[pair[0]][pair[1]] == ''):
            print(piece)
            self.state[pair[0]][pair[1]] = piece
        return None
    
    def positions(self):
        for r,s in zip(self.pos, self.state):
            for c,d in zip(r,s):
                print(str(c) + '|' if d == '' else ('-|'), end="")
            print()
            
    def index_of(self, val):
        for i, j in enumerate(self.pos):
            if val in j:
                a,b = i, j.index(val)
                if self.pos[i][j.index(val)] != 0:                    
                    return a,b
                return None
            
    def isFinished():
        return True;

    def __repr__(self):
        return '<Node {}>'.format(self.state)

