

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
        print()
            
    def mark(self, position, piece):
        pair = self.index_of(position)
        print(pair)
        if(self.state[pair[0]][pair[1]] == ''):
            self.state[pair[0]][pair[1]] = piece
        return None
    
    def positions(self):
        for r,s in zip(self.pos, self.state):
            for c,d in zip(r,s):
                print(str(c) + '|' if d == '' else ('-|'), end="")
            print()
        print()
            
    def index_of(self, val):
        for i, j in enumerate(self.pos):
            if val in j:
                a,b = i, j.index(val)
                if self.pos[i][j.index(val)] != 0:                    
                    return a,b
                return None
            
    def evaluate(self):
        a = 0
        b = 0
        #f(x) = a - b where a is the number of positions where
        #a piece can be put, and b the number of possible wins
        #in a row, diagonal or column
        for r in self.state:            
            for c in r:                
                if c == '':
                    a += 1        
                    
        for r in self.state:
            if len(set(r)) > 1:                
                b+=1            
                
        # tuple unpacking https://www.w3schools.com/python/python_tuples_unpack.asp
        for c in zip(*self.state):
            if len(set(c)) > 1:
                b+=1

                
        if not (self.state[0][0] == self.state[1][1] == self.state[2][2]):
            b+=1
        if not (self.state[0][2] == self.state[1][1] == self.state[2][0]):
            b+=1
            
        print(a,b)
        return a - b
            
    def isFinished():
        return True;

    def __repr__(self):
        return '<Node {}>'.format(self.state)

