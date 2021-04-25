from board_node import Node

board = [['','',''],
         ['','',''],
         ['','','']]


pos = [[1,2,3],
         [4,5,6],
         [7,8,9]]


pieces = {'computer':'','player':''}

visited = set()
to_visit = list()
computer = 'computer'
player = 'player'
start_node = Node(board, pos, None)


def isFinished(node):
   # if node.state
    pass




def expand(deepness):
    pass



#true is the
def play(turn, isFinished=False):
    if (turn == player):




player_piece = input('O or X: ');
computer_piece = 'X' if player_piece == 'O' else 'O'
print('Computer will play with: ' + computer_piece)

pieces[player] = player_piece
pieces[computer] = player_piece

who_goes_first = player if int(input('Who goes first? [0]: Computer | [1]: You\nOption:')) == 1 else computer


play(who_goes_first)






