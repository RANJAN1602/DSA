class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // You start by drinking all the initial bottles.
        int totalDrunk = numBottles;
        int emptyBottles = numBottles;

        // Loop as long as you have enough empty bottles to make an exchange.
        while (emptyBottles >= numExchange) {
            // Calculate how many new full bottles you can get.
            int newFullBottles = emptyBottles / numExchange;

            // Calculate the leftover empty bottles from this exchange.
            int leftoverEmpty = emptyBottles % numExchange;

            // Drink the new bottles and add them to the total.
            totalDrunk += newFullBottles;

            // Update your stock of empty bottles for the next round.
            // It's the ones you just drank + the leftovers from before.
            emptyBottles = newFullBottles + leftoverEmpty;
        }

        return totalDrunk;
    }
};