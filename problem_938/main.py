# /bin/env python3 
import numpy as np 
import random 
import matplotlib.pyplot as plt 

def main():
    """
    A deck of cards contain R red cards and B blue cards 
    A card is chosen randomly from the deck and removed. 
    A second card is then chosen uniformly randomly from the cards remaining and removed 
    """    
    R = 2 # Number of red cards
    B = 2 # Number of blue cards in the deck
    # The binary representation of the cards will be 1 is red 0 is blue 
    red_cards = np.ones(R, dtype=np.int8) # Generating the red cards
    blue_cards = np.zeros(B, dtype=np.int8) # Generating the blue cards
    deck = np.concatenate((red_cards, blue_cards)) # Joining the cards in the deck 
    random.shuffle(deck) # Shuffeling the deck 
    
    print("Original Deck")
    print(deck)
    
    # The logic of the problem
    def remove_card(deck): 
        first_idx = np.random.choice(range(0, len(deck)))
        second_idx = np.random.choice(range(0, len(deck)))

        first_card = deck[first_idx]
        second_card = deck[second_idx]

        if first_card == 1 and second_card == 1: 
            deck = np.delete(deck, [first_idx, second_idx])
        elif first_card == 0 and second_card == 0:
            pass 
        else:
            if first_card == 0:
                deck = np.delete(deck, first_idx)
            else:
                deck = np.delete(deck, second_idx)
        return deck # Returning the deck after one step 
    deck = remove_card(deck)
    ep = 0 
    t = 0 
    while ep != len(deck)  or t > 100:
        deck = remove_card(deck)
        ep = np.count_nonzero(deck)
        t =+ 1

    print(f"Deck after {t} iterations")
    print(f"The number of cards left is: {ep}")
    print(deck)
if __name__ =="__main__":
    main()