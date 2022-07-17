import random

play_point = 0
comp_point = 0

print("Hello and Welcome to Aayush's RPS Tournament!")
print("The rules are quite simple. We will both choose one move from the following choices: rock, paper, or scissors")
print("Every time you beat me, you get a point and when I beat you, I get a point!")

ready = input("Are you ready? Please type Yes or No! ")

if ready == "Yes":
    print("Okay, lets begin! We will play for five rounds. Most points wins!")
elif ready == "No":
    print("Alright. Play when you are ready!")
    exit()
else: 
    print("Hmm, seems to be a typo! Type 'Yes' when you are fully ready! ")
    exit()


def outcome():
    if (player_move == "Paper" and comp_choice == "Rock") or (player_move == "Scissors" and comp_choice == "Paper") or (player_move == "Rock" and comp_choice == "Scissors"):
        print("You won that round!")
        return True
    elif player_move == comp_choice:
        return ("We both chose", player_move)
    else:
        print("I won that one!")
        return False
i = 0
while i < 6:
    comp_choice = random.choice(["Rock", "Paper", "Scissors"])
    player_move = input("Make your choice: Rock, Paper, or Scissors: ")
    print("My choice was", comp_choice)
    outcome()
    i += 1

if __name__ == '__main__':
    if outcome() == True: 
        print("You won the whole tournament! Congratulations! ")
    else:
        print("I won the whole tournament!")
    