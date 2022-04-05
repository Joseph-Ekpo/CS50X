int main (void)
{
    float changeAmount;

    do
    {
        changeAmount = get_float("Change Owed: ");
    } while (changeAmount < 0);

// Coins
float quarter = 0.25, dime = 0.10, nickel = 0.05, penny = 0.01;

// After each calculation keep track of the remainder change.

    // Get dollar amount and use to calculate quarters
    int dollars = (changeAmount / 1);
    int quarters = dollars * 4;
	
    printf("%d dollars makes %d quarters\n", dollars, quarters);

    // Calculate how much change if amount is more than a dollar
    float remainderChange = changeAmount - dollars;
	
    printf("Remainder amount: %.2f\n", remainderChange);

    // Left over quarters from dollars
    int quartersLeft = (remainderChange / quarter);
    quarters += quartersLeft; // (remainderChange / quarter);
	
    printf("Total quarters: %d\n", quarters);

    // Get remainder amount
    double yahYeet = quartersLeft * quarter;
    

    // Calculate how much change is left after extracting quarters
    remainderChange = remainderChange - yahYeet;
	
    printf("Change after quarters: %.2f\n", remainderChange);

    // Get Dimes
    int dimes = (remainderChange / dime);
	
    printf("Total Dimes: %d\n", dimes);
	
    yahYeet = (dimes * dime);

    // Calculate how much change is left after extracting dimes
    remainderChange = remainderChange - yahYeet;
	
    printf("Change after dimes: %.2f\n", remainderChange);

    // Calculate how much change is left after extracting nickels
    int nickels = (remainderChange / nickel);
	
    printf("Total Nickels: %d\n", nickels);
	
    yahYeet = (nickels * nickel);
    remainderChange = remainderChange - yahYeet;

    printf("Change after nickels: %.2f\n", remainderChange);

    // Calculate the remaining change as pennies
    int pennies = round(remainderChange * 100);
	
    printf("Total pennies: %d\n", pennies);

    int minimumCoins = quarters + dimes + nickels + pennies;
    printf("%d\n", minimumCoins);
}