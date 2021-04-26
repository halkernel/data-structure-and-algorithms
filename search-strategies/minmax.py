from board_node import Node

board = [['X','',''],
         ['','',''],
         ['','','']]


pos = [[1,2,3],
         [4,5,6],
         [7,8,9]]


pieces = {'computer':'','player':''}

visited = set()
computer = 'computer'
player = 'player'
current = Node(board, pos, None)
to_visit = list()
to_visit.append(current)
deepness = 3 



def expand(deepness, node, piece):
    node = to_visit.pop(0)
    for row in node.state:
        for col in row:            
            #if (row[col] == ''):
                #row[col] = piece
                #to_visit.append(Node(node.state, pos, None)
                #col = ''
    #print(to_visit)


def min_max(node, depth, maximizing):
    pass
    
expand(3, current, 'O')



#true is the
def play(turn, finished=False):
    while (not finished):        
        if (turn == player):
            current.reveal()
            print()
            current.positions()
            next_pos = int(input("Choose a position: "))
            ret = current.index_of(next_pos)            
            #TODO check valid position later (using was_marked)            
            was_marked = current.mark(ret, pieces[player])              
            print()
            current.reveal()
            print()
            current.positions()            
            turn = computer        
        if (turn == computer):
            pos = min_max()
            
                    
            




#player_piece = input('O or X: ')
#computer_piece = 'X' if player_piece == 'O' else 'O'
#print('Computer will play with: ' + computer_piece)

#pieces[player] = player_piece
#pieces[computer] = player_piece

#who_goes_first = player if int(input('Who goes first? [0]: Computer | [1]: You\nOption:')) == 1 else computer


#play(who_goes_first)


