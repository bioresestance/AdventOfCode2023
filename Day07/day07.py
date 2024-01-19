# 32T3K 765
# T55J5 684
# KK677 28
# KTJJT 220
# QQQJA 483
# Expected ans = 6440

# Read in file

from collections import Counter


def read_in_file(filename):
    with open(filename) as f:
        data = f.read().splitlines()

    lines: list[tuple[str, int]] = []
    # Each line has a hand and a bid amount, separated by a space
    # Split each line into two parts
    for line in data:
        line = line.split(" ")
        hand = line[0]
        bid = int(line[1])
        lines.append((hand, bid))

    return lines


class Hand:
    cards_and_bid: tuple[str, int]
    hand_type: int

    def __init__(self, cards_and_bid: tuple[str, int]):
        self.cards_and_bid = cards_and_bid
        self.determine_hand_type()

    def card_values(self):
        card_order = "23456789TJQKA"
        cards, _ = self.cards_and_bid
        return [card_order.index(card) for card in cards]

    def determine_hand_type(self):
        cards, _ = self.cards_and_bid
        counts = Counter(cards)
        count_values = sorted(counts.values(), reverse=True)

        if count_values == [5]:  # Five of a kind
            self.hand_type = 6
        elif count_values == [4, 1]:  # Four of a kind
            self.hand_type = 5
        elif count_values == [3, 2]:  # Full house
            self.hand_type = 4
        elif count_values == [3, 1, 1]:  # Three of a kind
            self.hand_type = 3
        elif count_values == [2, 2, 1]:  # Two pair
            self.hand_type = 2
        elif count_values == [2, 1, 1, 1]:  # One pair
            self.hand_type = 1
        else:  # High card
            self.hand_type = 0

    def __str__(self) -> str:
        return str(self.cards_and_bid)

    def __repr__(self) -> str:
        return str(self.cards_and_bid)


class CamelCards:
    hands: list[Hand] = []
    sorted_hands: list[Hand] = []
    total_winnings: int = 0

    def __init__(self, hands: list[Hand]):
        self.hands = hands

    def sort_hands(self):
        buckets: list[list[Hand]] = [[] for _ in range(7)]
        # Put each hand into the appropriate bucket
        for hand in self.hands:
            hand.determine_hand_type()
            buckets[hand.hand_type].append(hand)

        for bucket in buckets:
            bucket.sort(key=lambda hand: hand.card_values(), reverse=False)
            self.sorted_hands += bucket
        for hand in self.sorted_hands:
            print(hand)

    def calculate_winnings(self):
        sum = 0
        for hand in self.sorted_hands:
            _, bid = hand.cards_and_bid
            sum += bid * (self.sorted_hands.index(hand) + 1)
        print(sum)


if __name__ == "__main__":
    data = read_in_file("Day07/input.txt")
    hands = [Hand(line) for line in data]
    camel_cards = CamelCards(hands)
    camel_cards.sort_hands()
    camel_cards.calculate_winnings()
