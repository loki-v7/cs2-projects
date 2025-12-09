#these imports are just for aesthetic
from time import sleep
import os

#define main
def main() -> None:

    os.system('clear')
    # loop till num of players
    while True:
        try:
            player_count = int(input('1 or 2 players?: \n'))
        except ValueError:
            print('Please enter a number\n')
            continue
        if player_count > 2 or player_count < 1:
            print('not an option')
        else:
            break

    # choose X or O
    while True: 
        x_or_o = input('X or O or end?: \n').strip().upper()
        # logic for checking x or o
        # logic for checking and choosing player count
        if player_count == 2:

            if x_or_o == 'X' or x_or_o == 'O':
                pvp_game(x_or_o)
                
            elif x_or_o == 'END':
                quit()

            else:
                print('not an option')
                sleep(3)
                os.system('clear')
        else:
            if x_or_o == 'X' or x_or_o == 'O':
                pve_game(x_or_o)

            elif x_or_o == 'END':
                quit()

            else:
                print('not an option')
                sleep(3)
                os.system('clear')

    # I clear the screen an os.system('clear') to make the screen look nice and not print the board and error 
    # I used sleep to make the errors look better


def pve_game(player_symbol):
    # i used a dictionary for the board and a cord list for choosing and looping
    tic_board = {'a1': '_', 'b1': '_', 'c1': '_', 'a2': '_', 'b2': '_', 'c2': '_', 'a3': '_', 'b3': '_', 'c3': '_'}
    cord_list = ['a1', 'b1', 'c1', 'a2', 'b2', 'c2', 'a3', 'b3', 'c3']
    # decides for who goes first
    if player_symbol =='X':
        opponet_symbol = 'O'
        player_goes_first = True
    else:
        opponet_symbol = 'X'
        player_goes_first = False
    # loop the game
    while True:
        #check  who go first
        if player_goes_first == True:
            game_state = player_turn(tic_board, cord_list, player_symbol)
            if game_state != 'none':
                break
            game_state = ai_turn(tic_board, cord_list, opponet_symbol, player_symbol)
            if game_state != 'none':
                break
        else:
            game_state = ai_turn(tic_board, cord_list, opponet_symbol, player_symbol)
            if game_state != 'none':
                break
            game_state = player_turn(tic_board, cord_list, player_symbol)
            if game_state != 'none':
                break
    print(game_state)
def pvp_game(player_symbol):
    #player vs player 
    # I have made the dictionary and store all the empty spaces and cords

    tic_board = {'a1': '_', 'b1': '_', 'c1': '_', 'a2': '_', 'b2': '_', 'c2': '_', 'a3': '_', 'b3': '_', 'c3': '_'}
    cord_list = ['a1', 'b1', 'c1', 'a2', 'b2', 'c2', 'a3', 'b3', 'c3']

    if player_symbol == 'X':
        opponent_symbol = 'O'
    else:
        opponent_symbol = 'X'

    game_state = ''
    
    while True:
        if player_symbol == 'X':
        #player turn
            game_state = player_turn(tic_board, cord_list, player_symbol)
        #check win
            if game_state != 'none':
                break

        #opponent turn
            print('O turn')
            game_state = player_turn(tic_board, cord_list, opponent_symbol)
        #check win
            if game_state != 'none':
                break
        else:
            print('X\'s turn')
            game_state = player_symbol(tic_board, cord_list, opponent_symbol)
            
    print(game_state)

def choose(cords, cord_list, tic_board):

    while True:

        print_board(cords)
        cord = input('What square are you marking: \n').strip().lower()
        
        if cord not in cord_list or tic_board[cord] != '_':
            print('not an option')
            sleep(3)
            os.system('clear')
        elif cord in cord_list:
            break

    return cord


def print_board(cords): 
    print(f'''
         A   B   C
      1 _{cords['a1']}_|_{cords['b1']}_|_{cords['c1']}_
      2 _{cords['a2']}_|_{cords['b2']}_|_{cords['c2']}_
      3 _{cords['a3']}_|_{cords['b3']}_|_{cords['c3']}_
          ''')
    return cords

def win_check(board, symbol):
    # my win check is just a bunch of if statements because I don't know how to optimize it
    if board['a1'] ==  symbol and board['b1'] == symbol and board['c1'] == symbol:
        return f'{symbol} wins'

    elif board['a2'] ==  symbol and board['b2'] == symbol and board['c2'] == symbol:
       return f'{symbol} wins'
        
    elif board['a3'] ==  symbol and board['b3'] == symbol and board['c3'] == symbol:
        return f'{symbol} wins'

    elif board['a1'] ==  symbol and board['a2'] == symbol and board['a3'] == symbol:
        return f'{symbol} wins'
        
    elif board['b1'] ==  symbol and board['b2'] == symbol and board['b3'] == symbol:
        return f'{symbol} wins'

    elif board['c1'] ==  symbol and board['c2'] == symbol and board['c3'] == symbol:
        return f'{symbol} wins'

    elif  board['a1'] ==  symbol and board['b2'] == symbol and board['c3'] == symbol:
        return f'{symbol} wins'

    elif board['c1'] ==  symbol and board['b2'] == symbol and board['a3'] == symbol:
        return f'{symbol} wins'
    elif board['a1'] != '_' and board['b1'] != '_' and board['c1'] != '_' and board['a2'] != '_' and board['b2'] != '_' and  board['c2'] != '_' and  board['a3'] != '_' and  board['b3'] != '_' and  board['c3'] != '_':
        return 'tie'

    return 'none'
def player_turn(tic_board, cord_list, player_symbol):
        # player turn
        os.system('clear')
        print(f'{player_symbol}\'s turn')
        cord = choose(tic_board, cord_list, tic_board) 
        tic_board[cord] = player_symbol
        os.system('clear')
        tic_board = print_board(tic_board)
        game_state = win_check(tic_board, player_symbol)
        return game_state

def ai_turn(tic_board, cord_list, ai_symbol, player_symbol):
    # ai turn logic
    os.system('clear')
    print(f'{ai_symbol}\'s turn (AI thinking...)')
    sleep(1)
    ai_move = ai_move_algorithm(tic_board, cord_list, ai_symbol, player_symbol)
    tic_board[ai_move] = ai_symbol
    os.system('clear')
    tic_board = print_board(tic_board)
    game_state = win_check(tic_board, ai_symbol)
    return game_state

def ai_move_algorithm(tic_board, cord_list, ai_symbol, player_symbol):
    # I made the AI beatable but it is still good
    available_moves = [cord for cord in cord_list if tic_board[cord] == '_']

    for cord in available_moves:
        tic_board[cord] = ai_symbol
        if win_check(tic_board, ai_symbol) == f'{ai_symbol} wins':
            tic_board[cord] = '_'
            return cord
        tic_board[cord] = '_'

    for cord in available_moves: 
        tic_board[cord] = player_symbol
        if win_check(tic_board, player_symbol) == f'{player_symbol} wins':
            tic_board[cord] = '_'
            return cord
        tic_board[cord] = '_'

    priority_moves = ['b2', 'a1', 'a3', 'c1', 'c3', 'a2', 'b1', 'b3', 'c2']
    for move in priority_moves:
        if move in available_moves:
            return move

if __name__ == '__main__':
    main()
