import numpy as np
import random

# -------------------------------------------------
# April 01, 2021
# Cooper Senior
# -------------------------------------------------

class Die:

    def __init__(self, sides):
        """A constructor method to create a die with given number of sides"""
        self.sides = sides

    def roll(self):
        """A general method to roll the die"""
        return random.randint(1, self.sides)

# -------------------------------------------------

class Farkle:

    def __init__(self, sides):
        """A constructor method that can record 6 dice rolls"""
        self.rolls = np.zeros(6, dtype=np.int16)
        self.sides = sides

    def roll_dice(self):
        """A general method that rolls 6 dice"""
        for i in range(len(self.rolls)):
            self.rolls[i] = Die(self.sides).roll()

    def count_outcomes(self):
        """A helper method that determines how many 1s, 2s, etc. were rolled"""
        counts = np.zeros(self.sides + 1, dtype=np.int16)
        for roll in self.rolls:
            counts[roll] += 1
        return counts
        
#--------------------------------------------------

    def is_it_four_of_a_kind(self):
        if 4 in self.count_outcomes():
            return True
        else:
            return False

    def is_it_straight(self):
        count = 0
        for num in self.count_outcomes():
            if num == 1:
                count += 1
        if count == 6:
            return True
        else:
            return False
        
    def is_it_two_triplets(self):
        if 3 in self.count_outcomes():
            count = 0
            for num in self.count_outcomes():
                if num == 3:
                    count += 1
            if count > 1:
                return True
        else:
            return False

# -------------------------------------------------
        
def main(how_many):

    four_of_a_kind = 0
    straight = 0
    two_triplets = 0
    game = Farkle(6)

    for i in range(how_many):
        game.roll_dice()
        if game.is_it_four_of_a_kind():
            four_of_a_kind += 1
        elif game.is_it_straight():
            straight += 1
        elif game.is_it_two_triplets():
            two_triplets += 1

    print("Number of Rolls:", how_many)
    print("---------------------")
    
    print("Number of Four of a Kinds:", four_of_a_kind)
    print("Percent:", "{:.2f}%\n".format(four_of_a_kind * 100 / how_many))
    print("Number of Straights:", straight)
    print("Percent:", "{:.2f}%\n".format(straight * 100 / how_many))
    print("Number of Two Triplets:", two_triplets)
    print("Percent:", "{:.2f}%".format(two_triplets * 100 / how_many))

# -------------------------------------------------

main(1000)
    
        
